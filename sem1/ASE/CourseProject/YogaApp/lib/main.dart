import 'package:YogaApp/Blog/BlogList.dart';
import 'package:YogaApp/Blog/BlogTypeList.dart';
import 'package:YogaApp/ScoreViewer.dart';
import 'package:YogaApp/Blog/ViewBlog.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:YogaApp/login_screens/login_screen.dart';
import 'package:YogaApp/login_screens/welcome_screen.dart';
import 'package:YogaApp/login_screens/registration_screen.dart';
import 'package:YogaApp/choose.dart';
import 'homepage.dart';
import 'package:YogaApp/homepage.dart';
import 'package:YogaApp/courses/courseList.dart' as course;

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  final _auth = FirebaseAuth.instance;
  final user = await _auth.currentUser();
  final String initialRoute = (user == null) ? WelcomeScreen.id : HomePage.id;
  runApp(MyApp(
    initialRoute: initialRoute,
  ));
}

class MyApp extends StatelessWidget {
  final String initialRoute;
  MyApp({@required this.initialRoute});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      routes: {
        Choose.id: (context) => Choose(),
        LoginScreen.id: (context) => LoginScreen(),
        WelcomeScreen.id: (context) => WelcomeScreen(),
        RegistrationScreen.id: (context) => RegistrationScreen(),
        course.CourseList.id: (context) => course.CourseList(),
        BlogTypeList.id: (context) => BlogTypeList(),
        BlogList.id: (context) => BlogList(),
        ViewBlog.id: (context) => ViewBlog("s"),
        HomePage.id: (context) => HomePage(),
        ScoreViewer.id: (context) => ScoreViewer("1"),
        // ListOfAsanas.id : (context) => ListOfAsanas(null,"cgg"),
      },
      initialRoute: initialRoute,
    );
  }
}
