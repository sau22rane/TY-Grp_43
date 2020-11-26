import 'dart:convert';
import 'dart:io';
import 'dart:math';
import 'package:YogaApp/ViewBlog.dart';
import 'package:file_picker/file_picker.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';

class BlogList extends StatefulWidget {
  static final id = "BlogList";
  final String type;
  BlogList({Key key, this.type}) : super(key: key);
  @override
  _BlogList createState() => _BlogList();
}

class _BlogList extends State<BlogList> {
  List<Modal> itemList = List();
  final mainReference =
      FirebaseDatabase.instance.reference().child("BlogSection");

  String get type => widget.type;
  @override
  Widget build(BuildContext context) {
    print("heya");
    String type = ModalRoute.of(context).settings.arguments;

    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.deepPurple,
        title: Text(type),
      ),
      body: itemList.length == 0
          ? Text("Loading")
          : ListView.builder(
              itemCount: itemList.length,
              itemBuilder: (context, index) {
                return Padding(
                    padding: const EdgeInsets.fromLTRB(10, 0, 0, 0),
                    child: GestureDetector(
                      onTap: () {
                        String passData = itemList[index].link;
                        Navigator.pushNamed(context, ViewBlog.id,
                            arguments: passData);
                      },
                      child: Stack(
                        children: <Widget>[
                          Container(
                            height: 100,
                            decoration: BoxDecoration(
                              image: DecorationImage(
                                image: AssetImage('assets/images/logo.png'),
                                fit: BoxFit.cover,
                              ),
                            ),
                          ),
                          Center(
                            child: Container(
                              height: 140,
                              child: Card(
                                margin: EdgeInsets.all(18),
                                elevation: 7.0,
                                child: Center(
                                  child: Text(itemList[index].name +
                                      " " +
                                      (index + 1).toString()),
                                ),
                              ),
                            ),
                          ),
                        ],
                      ),
                    ));
              },
            ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          getPdfAndUpload();
          setState(() {});
        },
        child: Icon(
          Icons.add,
          color: Colors.white,
        ),
        backgroundColor: Colors.deepPurple,
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
    print(url);
    documentFileUpload(url);
    print("Saved");
  }

  void documentFileUpload(String str) {
    var data = {
      "PDF": str,
      "FileName": "file",
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
    mainReference.once().then((DataSnapshot snap) {
      print(snap);
      var data = snap.value;
      itemList.clear();
      data.forEach((key, value) {
        Modal m = new Modal(value['PDF'], value['FileName']);
        itemList.add(m);
        setState(() {});
      });
    });
  }
}

class Modal {
  String link, name;
  Modal(this.link, this.name);
}
