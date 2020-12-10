import 'package:YogaApp/courses/ListOfAsanas.dart';
import 'package:YogaApp/widgets/AppDrawer.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';
import 'package:camera/camera.dart';

class CourseList extends StatefulWidget {
  @override
  static const String id = 'CourseList';
  _CourseListState createState() => _CourseListState();
}

class _CourseListState extends State<CourseList> {
  Query _ref;
  Query _refpass;
  String tempurl = null;
  final GlobalKey<ScaffoldState> _scaffoldKey = new GlobalKey<ScaffoldState>();

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
    _getimage(context, "Vrikshasana.mp4");
  }

  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    return Scaffold(
        key: _scaffoldKey,
        drawer: AppDrawer(),
        appBar: AppBar(
          title: Text(
            "Course List",
            style: TextStyle(color: Colors.black),
          ),
          backgroundColor: Colors.white,
          leading: IconButton(
            icon: Icon(Icons.list, color: Colors.grey),
            onPressed: () => _scaffoldKey.currentState.openDrawer(),
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
                      image: AssetImage("assets/images/cloud.jpeg"),
                      fit: BoxFit.cover)),
            ),
            Container(
              height: size.height * 0.8,
              decoration: BoxDecoration(
                  image: DecorationImage(
                      alignment: Alignment.bottomCenter,
                      image: AssetImage("assets/images/smile.jpeg"),
                      fit: BoxFit.fitWidth),
                  borderRadius:
                      BorderRadius.only(bottomLeft: Radius.circular(100)),
                  color: Colors.orange,
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey,
                      offset: Offset(0.0, 1.0), //(x,y)
                      blurRadius: 15.0,
                    ),
                  ]),
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
                          return ListOfAsanas(_refpass, "everyday");
                        }));
                      },
                      child: Text(
                        "Everyday",
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
                        "Surf The Waves Of Happiness",
                        style: TextStyle(color: Colors.white),
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
                      image: AssetImage("assets/images/green.jpeg"),
                      fit: BoxFit.cover),
                  borderRadius:
                      BorderRadius.only(bottomLeft: Radius.circular(100)),
                  color: Colors.yellow,
                  boxShadow: [
                    BoxShadow(
                      color: Colors.grey,
                      offset: Offset(0.0, 1.0), //(x,y)
                      blurRadius: 15.0,
                    ),
                  ]),
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
                          return ListOfAsanas(_refpass, "intermediate");
                        }));
                      },
                      child: Text(
                        "Intermediate",
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
                        "Clam Your Busy Mind",
                        style: TextStyle(color: Colors.white),
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
                    image: AssetImage("assets/images/road.jpeg"),
                    fit: BoxFit.cover),
                borderRadius:
                    BorderRadius.only(bottomLeft: Radius.circular(100)),
                color: Colors.grey,
                boxShadow: [
                  BoxShadow(
                    color: Colors.grey,
                    offset: Offset(0.0, 1.0), //(x,y)
                    blurRadius: 2.0,
                  )
                ],
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
                          return ListOfAsanas(_refpass, "modernstyle");
                        }));
                      },
                      child: Text(
                        "Modern Style",
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
                        "Make Your Day Worry Free",
                        style: TextStyle(color: Colors.white),
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
                boxShadow: [
                  BoxShadow(
                    color: Colors.grey,
                    offset: Offset(0.0, 1.0), //(x,y)
                    blurRadius: 15.0,
                  ),
                ],
              ),
              child: Padding(
                padding: const EdgeInsets.only(left: 60, bottom: 35),
                child: Align(
                  alignment: Alignment.bottomLeft,
                  child: Text(
                    "Courses",
                    style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
                    textAlign: TextAlign.left,
                  ),
                ),
              ),
            ),
          ],
        ));
  }
}

class FireStorageService extends ChangeNotifier {
  FireStorageService();
  static Future<dynamic> loadImage(BuildContext context, String image) async {
    return await FirebaseStorage.instance.ref().child(image).getDownloadURL();
  }
}
