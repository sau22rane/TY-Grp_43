import 'package:YogaApp/courses/AsanaCard.dart';
import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:camera/camera.dart';

class ListOfAsanas extends StatefulWidget {
  static final String id = 'ListOfAsana';
  Query _ref;
  String courseName;
  Query _tref;
  List<String> urls = [
    "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/1.png?alt=media&token=8f6d17e4-e67b-40b9-b526-6dbe0b1b9448",
    "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/2.png?alt=media&token=7ca85e65-a10d-4735-9f0f-a5e6a0674909",
    "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/3.png?alt=media&token=446f0e6d-56b9-4a75-973a-452c8ec5e766"
  ];
  ListOfAsanas(Query _ref, String courseName) {
    // this._ref = _ref;
    this._ref = FirebaseDatabase.instance.reference();
    this.courseName = courseName;
    // print("this also ===============");
  }
  @override
  _ListOfAsanasState createState() => _ListOfAsanasState();
}

class _ListOfAsanasState extends State<ListOfAsanas> {
  List<CameraDescription> cameras;

  Future<Null> cameraAvailablity() async {
    WidgetsFlutterBinding.ensureInitialized();
    try {
      cameras = await availableCameras();
      print("================CAMERA AVAILABLE===========");
    } on CameraException catch (e) {
      print('Error: $e.code\nError Message: $e.message');
      print("No camera available in ListOfAsana.dart file");
    }
  }

  Future callcameraAvailablity() async {
    await cameraAvailablity();
  }

  Future readData() async {
    widget._ref.once().then((DataSnapshot snapshot) {
      // print('snapshotData : ${snapshot.value}');
      Map<dynamic, dynamic> values = snapshot.value;
      values.forEach((key, values) {
        // print("values : " + values.toString());

        Map<dynamic, dynamic> v = values;
        v.forEach((key, value) {
          // print("inner : " + value.toString());
          // print("iner skey : " + key);
          print("Key : " + key);
          if (value["name"] == widget.courseName) {
            print("found");
            widget._tref = FirebaseDatabase.instance
                .reference()
                .child("courses")
                .child(key)
                .child("asanas");
          }
        });
      });
    });
    print("witn in readdata");
    // return widget._tref;
  }

  @override
  void initState() {
    super.initState();
    callcameraAvailablity();
    print("ref creates");
    print("witn in readdata");
  }

  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    func();

    return Scaffold(
        appBar: AppBar(
          title: Text(
            "START YOUR DAY WITH",
            style: TextStyle(color: Colors.white, fontSize: 18),
          ),
          leading: Icon(Icons.folder_open),
          centerTitle: true,
          elevation: 0,
          backgroundColor: Colors.deepPurple,
        ),
        body: Stack(
          children: <Widget>[
            Container(
              decoration: BoxDecoration(color: Colors.lightBlueAccent),
            ),
            Container(
              height: size.height * 0.18,
              decoration: BoxDecoration(
                  color: Colors.deepPurple,
                  borderRadius:
                      BorderRadius.vertical(bottom: Radius.circular(50))),
            ),
            widget._tref == null
                ? Center(child: CircularProgressIndicator())
                : Container(
                    child: FirebaseAnimatedList(
                        query: widget._tref,
                        itemBuilder: (BuildContext cnt, DataSnapshot snaps,
                            Animation<double> animation, int index) {
                          print("snaps : " + snaps.value.toString());

                          return AsanaCard(cameras, snaps.value.toString());
                        }),
                  )
          ],
        ));
  }

  Future func() async {
    if (widget._tref != null) return 1;
    await readData();
    setState(() {});
    return 1;
  }
}
