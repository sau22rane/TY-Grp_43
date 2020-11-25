import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:firebase_storage/firebase_storage.dart';

class ListOfAsanas extends StatefulWidget {
  static final String id = 'ListOfAsana';
  Query _ref;
  String courseName;
  Query _tref;
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
                          title: Text(snaps.value),
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

Widget get() {
  List<String> l = ["abcd", "efg"];
  return Container(
      // child: ListView.builder(
      //     itemCount: 2,
      //     itemBuilder: (BuildContext cxt, int index) {
      //       return ListTile(
      //         title: Text(l[index]),
      //       );
      //     }),

      );
}
