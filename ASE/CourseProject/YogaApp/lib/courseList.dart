import 'package:YogaApp/ListOfAsanas.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';

class CourseList extends StatefulWidget {
  @override
  _CourseListState createState() => _CourseListState();
}

class _CourseListState extends State<CourseList> {
  Query _ref;
  Query _refpass;

  String tempurl = null;

  Future<String> _getimage(BuildContext context, String str) async {
    await FireStorageService.loadImage(context, str).then((value) {
      print("download url   " + value.toString());
      tempurl = value.toString();
      return value.toString();
    });
  }

  @override
  void initState() {
    super.initState();
    print("ref creates");
    _ref = FirebaseDatabase.instance.reference().child("courses");
    _refpass = FirebaseDatabase.instance.reference();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      child: FirebaseAnimatedList(
          query: _ref,
          itemBuilder: (BuildContext cxt, DataSnapshot snaps,
              Animation<double> animation, int index) {
            print(snaps.value.toString());
            print(snaps.value['name']);

            return ListTile(
              contentPadding:
                  EdgeInsets.only(bottom: 10, top: 10, right: 10, left: 10),
              title: Text(snaps.value['name']),
              leading: Container(
                  height: 60,
                  width: 70,
                  decoration:
                      BoxDecoration(borderRadius: BorderRadius.circular(50)),
                  child: Image.network(
                    snaps.value['url'],
                    fit: BoxFit.fill,
                  )),
              onTap: () {
                Navigator.push(context, MaterialPageRoute(builder: (context) {
                  return ListOfAsanas(_refpass, snaps.value['name']);
                }));
                // ListOfAsanas(_ref, "padd");
              },
            );
          }),
      // child: Stack(
      //   children: <Widget>[
      //     Align(
      //       child: Container(
      //         color: Colors.lightBlue,
      //       ),
      //     ),
      //     Container(
      //       height: 150,
      //       decoration: BoxDecoration(
      //           color: Colors.deepPurple,
      //           borderRadius: BorderRadius.circular(550)),
      //     )
      //   ],
      // ),
    );
  }
}

class FireStorageService extends ChangeNotifier {
  FireStorageService();
  static Future<dynamic> loadImage(BuildContext context, String image) async {
    return await FirebaseStorage.instance.ref().child(image).getDownloadURL();
  }
}
