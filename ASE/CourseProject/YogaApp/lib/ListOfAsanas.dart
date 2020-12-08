import 'package:YogaApp/courses/AsanaPlayer.dart';
import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';

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
    this._ref = _ref;
    this.courseName = courseName;
    // print("this also ===============");
  }

  @override
  _ListOfAsanasState createState() => _ListOfAsanasState();
}

class _ListOfAsanasState extends State<ListOfAsanas> {
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
    print("ref creates");
    print("witn in readdata");
  }

  @override
  Widget build(BuildContext context) {
    func();
    return MaterialApp(
      home: Scaffold(
          appBar: AppBar(
            title: Text("Yoga-App"),
          ),
          body: widget._tref == null
              ? CircularProgressIndicator()
              : Container(
                  child: FirebaseAnimatedList(
                      query: widget._tref,
                      itemBuilder: (BuildContext cnt, DataSnapshot snaps,
                          Animation<double> animation, int index) {
                        print("snaps : " + snaps.value.toString());
                        return ListTile(
                          leading: Container(
                            height: 60,
                            width: 70,
                            decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(50)),
                            child: Image.network(
                              widget.urls.elementAt(index),
                              fit: BoxFit.fill,
                            ),
                          ),
                          title: Text(snaps.value),
                          onTap: () {
                            Navigator.push(context,
                                MaterialPageRoute(builder: (context) {
                              return AsanaPlayer();
                            }));
                          },
                        );
                      }),
                )),
    );
  }

  Future func() async {
    if (widget._tref != null) return 1;
    await readData();
    setState(() {});
    return 1;
  }
}