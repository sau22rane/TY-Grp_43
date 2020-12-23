import 'dart:convert';
import 'dart:io';
import 'dart:math';
import 'package:YogaApp/Blog/ViewBlog.dart';
import 'package:file_picker/file_picker.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';
import 'package:modal_progress_hud/modal_progress_hud.dart';
import 'package:shared_preferences/shared_preferences.dart';

bool pract;

class BlogList extends StatefulWidget {
  static final id = "BlogList";
  final String type;
  BlogList({Key key, this.type}) : super(key: key);
  @override
  _BlogList createState() => _BlogList();
}

class _BlogList extends State<BlogList> {
  List<Modal> itemList = List();
  bool spinner = true;
  String fileNameInput;
  final mainReference =
      FirebaseDatabase.instance.reference().child("BlogSection");
  getPractioner() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    try {
       bool boolValue = prefs.getBool('Participant/Trainee');
    if (boolValue != null) {
      pract = boolValue;
      print("pract " + pract.toString());
    } else {
      pract = true;
      print("Notfound");
      throw Exception;
    }

    }catch(e) {
      print("catched " + e);
    }
   
  }

  String get type => widget.type;
  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    String type = widget.type;
    //print(type);
    mainReference.once().then((DataSnapshot snap) {
      //print(snap);
      var data = snap.value;
      itemList.clear();
      data.forEach((key, value) {
        Modal m = new Modal(value['PDF'], value['FileName']);
        itemList.add(m);
        setState(() {
          spinner = false;
        });
      });
    });

    return Scaffold(
      resizeToAvoidBottomInset: true,
      appBar: AppBar(
        backgroundColor: Colors.blue,
        title: Text(type),
      ),
      body: ModalProgressHUD(
        inAsyncCall: spinner,
        child: Stack(
          children: [
            Container(
              decoration: BoxDecoration(color: Colors.lightBlueAccent),
            ),
            Container(
              height: size.height * 0.18,
              decoration: BoxDecoration(
                  color: Color(0xFF5E60CE),
                  borderRadius:
                      BorderRadius.vertical(bottom: Radius.circular(50))),
            ),
            ListView.builder(
              itemCount: itemList.length,
              itemBuilder: (context, index) {
                return Padding(
                    padding: const EdgeInsets.fromLTRB(10, 0, 10, 0),
                    child: GestureDetector(
                      onTap: () {
                        String passData = itemList[index].link;
                        Navigator.push(context,
                            MaterialPageRoute(builder: (context) {
                          return ViewBlog(passData);
                        }));
                       
                      },
                      child: Center(
                        child: Container(
                          height: 140,
                          child: Card(
                            shape: RoundedRectangleBorder(
                                borderRadius: BorderRadius.circular(30)),
                            margin: EdgeInsets.all(18),
                            elevation: 7.0,
                            child: Center(
                              child: Padding(
                                padding: const EdgeInsets.symmetric(
                                    horizontal: 14, vertical: 8),
                                child: Text(
                                  itemList[index].name,
                                  textAlign: TextAlign.center,
                                  style: TextStyle(fontWeight: FontWeight.w500),
                                ),
                              ),
                            ),
                          ),
                        ),
                      ),
                    ));
              },
            ),
          ],
        ),
      ),
      floatingActionButton: 
      // pract
      //     ? Container()
      //     :
           FloatingActionButton(
              onPressed: () {
                showModalBottomSheet(
                    context: context,
                    isScrollControlled: true,
                    builder: (context) => Container(
                          height: 500,
                          decoration: BoxDecoration(
                            borderRadius: BorderRadius.circular(40),
                          ),
                          child: Column(
                            children: [
                              Expanded(
                                flex: 3,
                                child: Container(
                                  child: Center(
                                      child: Text(
                                    "File Name ",
                                    style: TextStyle(
                                      fontSize: 20,
                                    ),
                                  )),
                                ),
                              ),
                              Expanded(
                                flex: 5,
                                child: Padding(
                                  padding: const EdgeInsets.all(10.0),
                                  child: TextField(
                                    textAlign: TextAlign.center,
                                    onChanged: (value) {
                                      fileNameInput = value;
                                    },
                                  ),
                                ),
                              ),
                              Expanded(
                                flex: 3,
                                child: Container(
                                  width: 300,
                                  decoration: BoxDecoration(
                                    color: Colors.deepPurple,
                                    borderRadius: BorderRadius.circular(20),
                                  ),
                                  child: GestureDetector(
                                    child: Center(
                                        child: Text(
                                      "Save",
                                      style: TextStyle(
                                          color: Colors.white,
                                          fontWeight: FontWeight.bold,
                                          fontSize: 20),
                                    )),
                                    onTap: () {
                                      setState(() {
                                        Navigator.pop(context);
                                        getPdfAndUpload();
                                      });
                                    },
                                  ),
                                ),
                              ),
                              Expanded(
                                flex: 5,
                                child: Container(),
                              ),
                            ],
                          ),
                        ));
                setState(() {});
              },
              child: Icon(
                Icons.add,
                color: Colors.white,
              ),
              backgroundColor: Color(0xFF5E60CE),
            ),
    );
  }

  Future getPdfAndUpload() async {
    var rng = new Random();
    String randomName = "";
    for (var i = 0; i < 20; i++) {
      print(rng.nextInt(100));
      randomName += rng.nextInt(100).toString();
    }
    File file = await FilePicker.getFile(
        type: FileType.custom, allowedExtensions: ['pdf']);
    String fileName = '$randomName.pdf';
    print(' fileName ' + fileName);
    savePdf(file.readAsBytesSync(), fileName);
  }

  Future savePdf(List<int> asset, String name) async {
    StorageReference reference = FirebaseStorage.instance.ref().child(name);
    StorageUploadTask uploadTask = reference.putData(asset);
    String url = await (await uploadTask.onComplete).ref.getDownloadURL();
    print("url " + url);
    documentFileUpload(url);
    print("Saved");
  }

  void documentFileUpload(String str) {
    var data = {
      "PDF": str,
      "FileName": fileNameInput,
    };
    mainReference.child(createCryptoRandomString()).set(data).then((v) {
      print("stored sucessful");
    });
  }

  String createCryptoRandomString([int length = 32]) {
    final Random _random = Random.secure();
    var values = List<int>.generate(length, (index) => _random.nextInt(256));
    return base64Url.encode(values);
  }

  @override
  void initState() {
    super.initState();
    spinner = true;
    getPractioner();
  }
}

class Modal {
  String link, name;
  Modal(this.link, this.name);
}
