import 'package:YogaApp/Blog/BlogTypeList.dart';
import 'package:YogaApp/ScoreViewer.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:YogaApp/homepage.dart';
import 'package:YogaApp/login_screens/welcome_screen.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:YogaApp/courses/courseList.dart';

class AppDrawer extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Drawer(
      elevation: 10,
      child: Column(
        children: [
          Expanded(
            flex: 5,
            child: DrawerHeader(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Expanded(
                    flex: 5,
                    child: Container(
                      height: 90,
                      width: 130,
                      child: CircleAvatar(
                        radius: 80,
                        backgroundImage:
                            AssetImage("assets/images/profile.jpg"),
                      ),
                    ),
                  ),
                  Expanded(
                    flex: 2,
                    child: Padding(
                      padding: const EdgeInsets.symmetric(vertical: 2.0),
                      child: Text(
                        "Tarun Medtiya",
                        style: TextStyle(
                            fontFamily: 'SegoeUI-Bold',
                            fontSize: 25,
                            fontWeight: FontWeight.bold,
                            decoration: TextDecoration.none),
                      ),
                    ),
                  ),
                  Expanded(
                    flex: 1,
                    child: Padding(
                      padding: const EdgeInsets.symmetric(vertical: 3.0),
                      child: Text(
                        "@tarun_24",
                        textAlign: TextAlign.left,
                        style: TextStyle(
                            fontSize: 12, decoration: TextDecoration.none),
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ),
          Expanded(
            flex: 10,
            child: ListView(
              children: [
                DrawerListItem(
                  icon: Icons.home,
                  title: "Home",
                  id: HomePage.id,
                ),
                DrawerListItem(
                  icon: Icons.assignment_ind,
                  title: "Courses",
                  id: CourseList.id,
                ),
                DrawerListItem(
                  icon: Icons.person_outline,
                  title: "Articles",
                  id: BlogTypeList.id,
                ),
                DrawerListItem(
                  icon: Icons.info_outline,
                  title: "About Us",
                  id: ScoreViewer.id,
                ),
                DrawerListItem(
                  icon: Icons.exit_to_app,
                  title: "Log Out",
                  id: WelcomeScreen.id,
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

class DrawerListItem extends StatelessWidget {
  final IconData icon;
  final String id;
  final String title;
  final _auth = FirebaseAuth.instance;
  DrawerListItem(
      {@required this.icon, @required this.id, @required this.title});
  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: () {
        if (id == WelcomeScreen.id) {
          _auth.signOut();

          Navigator.pushNamedAndRemoveUntil(
              context, WelcomeScreen.id, (route) => false);
        } else
          Navigator.pushReplacementNamed(context, id);
      },
      child: ListTile(
        leading: Icon(
          icon,
          color: Colors.blue,
        ),
        title: Text(title),
      ),
    );
  }
}
