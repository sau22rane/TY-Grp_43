import 'package:YogaApp/courses/ListOfAsanas.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';
/*
class CourseList extends StatefulWidget {
  @override
  static const String id = 'CourseList';
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
    return ListView(
      children: <Widget>[
        ListTile(
          title: Text("data"),
        ),
        Container(
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
                      decoration: BoxDecoration(
                          borderRadius: BorderRadius.circular(50)),
                      child: Image.network(
                        snaps.value['url'],
                        fit: BoxFit.fill,
                      )),
                  onTap: () {
                    Navigator.push(context,
                        MaterialPageRoute(builder: (context) {
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
        ),
      ],
    );
  }
}

class FireStorageService extends ChangeNotifier {
  FireStorageService();
  static Future<dynamic> loadImage(BuildContext context, String image) async {
    return await FirebaseStorage.instance.ref().child(image).getDownloadURL();
  }
}
*/

class CourseList extends StatefulWidget {
  @override
  static const String id = 'CourseList';
  _CourseListState createState() => _CourseListState();
}

class _CourseListState extends State<CourseList> {
  Query _ref;
  Query _refpass;
  String tempurl = null;

  @override
  void initState() {
    super.initState();
    print("ref creates");
    _ref = FirebaseDatabase.instance.reference().child("courses");
    _refpass = FirebaseDatabase.instance.reference();
  }

  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    return Scaffold(
        appBar: AppBar(
          title: Text(
            "Course List",
            style: TextStyle(color: Colors.black),
          ),
          backgroundColor: Colors.white,
          leading: Icon(
            Icons.assignment_return,
            color: Colors.grey,
          ),
          elevation: 0,
          actions: <Widget>[
            Padding(
              padding: const EdgeInsets.only(right: 15),
              child: Icon(
                Icons.wifi,
                color: Colors.grey,
              ),
            )
          ],
        ),
        body: Stack(
          children: <Widget>[
            Container(
              decoration: BoxDecoration(
                  color: Colors.blue,
                  image: DecorationImage(
                      image: AssetImage("assets/images/logo.jpg"),
                      fit: BoxFit.cover)),
            ),
            Container(
              height: size.height * 0.8,
              decoration: BoxDecoration(
                image: DecorationImage(
                    image: AssetImage("assets/images/logo.PNG"),
                    fit: BoxFit.cover),
                borderRadius:
                    BorderRadius.only(bottomLeft: Radius.circular(100)),
                color: Colors.orange,
              ),
              child: Padding(
                padding: const EdgeInsets.only(left: 60, bottom: 20),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: ListTile(
                    contentPadding: EdgeInsets.only(left: 1),
                    title: GestureDetector(
                      onTap: () {
                        Navigator.push(context,
                            MaterialPageRoute(builder: (context) {
                          return ListOfAsanas(_refpass, "Anxiety");
                        }));
                      },
                      child: Text(
                        "Health & Wellness",
                        style: TextStyle(
                            fontSize: 25,
                            fontWeight: FontWeight.bold,
                            color: Colors.white),
                        textAlign: TextAlign.left,
                      ),
                    ),
                    subtitle: Padding(
                      padding: const EdgeInsets.only(top: 8),
                      child: GestureDetector(
                        onTap: () {
                          Navigator.push(context,
                              MaterialPageRoute(builder: (context) {
                            return ListOfAsanas(_refpass, "Anxiety");
                          }));
                        },
                        child: Text(
                          "56 topics - 2k articles",
                        ),
                      ),
                    ),
                  ),
                ),
              ),
            ),
            Container(
              height: size.height * 0.6,
              decoration: BoxDecoration(
                image: DecorationImage(
                    image: AssetImage("assets/images/logo.jpg"),
                    fit: BoxFit.cover),
                borderRadius:
                    BorderRadius.only(bottomLeft: Radius.circular(100)),
                color: Colors.yellow,
              ),
              child: Padding(
                padding: const EdgeInsets.only(left: 60, bottom: 20),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: ListTile(
                    contentPadding: EdgeInsets.only(left: 1),
                    title: GestureDetector(
                      onTap: () {
                        Navigator.push(context,
                            MaterialPageRoute(builder: (context) {
                          return ListOfAsanas(_refpass, "Anxiety");
                        }));
                      },
                      child: Text(
                        "Technology",
                        style: TextStyle(
                            fontSize: 25,
                            fontWeight: FontWeight.bold,
                            color: Colors.white),
                        textAlign: TextAlign.left,
                      ),
                    ),
                    subtitle: Padding(
                      padding: const EdgeInsets.only(top: 8),
                      child: Text(
                        "110 topics - 1k articles",
                      ),
                    ),
                  ),
                ),
              ),
            ),
            Container(
              height: size.height * 0.4,
              decoration: BoxDecoration(
                image: DecorationImage(
                    image: AssetImage("assets/images/logo.jpg"),
                    fit: BoxFit.cover),
                borderRadius:
                    BorderRadius.only(bottomLeft: Radius.circular(100)),
                color: Colors.grey,
              ),
              child: Padding(
                padding: const EdgeInsets.only(left: 60, bottom: 20),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: ListTile(
                    contentPadding: EdgeInsets.only(left: 1),
                    title: GestureDetector(
                      onTap: () {
                        Navigator.push(context,
                            MaterialPageRoute(builder: (context) {
                          return ListOfAsanas(_refpass, "Anxiety");
                        }));
                      },
                      child: Text(
                        "Outdoor",
                        style: TextStyle(
                            fontSize: 25,
                            fontWeight: FontWeight.bold,
                            color: Colors.white),
                        textAlign: TextAlign.left,
                      ),
                    ),
                    subtitle: Padding(
                      padding: const EdgeInsets.only(top: 8),
                      child: Text(
                        "128 topics - 4k articles",
                      ),
                    ),
                  ),
                ),
              ),
            ),
            Container(
              height: size.height * 0.2,
              decoration: BoxDecoration(
                borderRadius:
                    BorderRadius.only(bottomLeft: Radius.circular(100)),
                color: Colors.white,
              ),
              child: Padding(
                padding: const EdgeInsets.only(left: 60, bottom: 35),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: GestureDetector(
                    onTap: () {
                      Navigator.push(context,
                          MaterialPageRoute(builder: (context) {
                        return ListOfAsanas(_refpass, "Anxiety");
                      }));
                    },
                    child: Text(
                      "Article",
                      style:
                          TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
                      textAlign: TextAlign.left,
                    ),
                  ),
                ),
              ),
            ),
          ],
        ));
  }
}
