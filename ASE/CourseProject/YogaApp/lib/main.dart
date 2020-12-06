import 'package:YogaApp/BlogList.dart';
import 'package:YogaApp/BlogTypeList.dart';
import 'package:YogaApp/ViewBlog.dart';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:YogaApp/login_screens/login_screen.dart';
import 'package:YogaApp/login_screens/welcome_screen.dart';
import 'package:YogaApp/login_screens/registration_screen.dart';
import 'package:YogaApp/choose.dart';
import 'homepage.dart';
import 'courseList.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  final _auth = FirebaseAuth.instance;
  final user = await _auth.currentUser();
  final String initialRoute = (user == null) ? WelcomeScreen.id : Choose.id;
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
      routes: {
        Choose.id: (context) => Choose(),
        LoginScreen.id: (context) => LoginScreen(),
        WelcomeScreen.id: (context) => WelcomeScreen(),
        RegistrationScreen.id: (context) => RegistrationScreen(),
        CourseList.id: (context) => CourseList(),
        BlogTypeList.id: (context) => BlogTypeList(),
        BlogList.id: (context) => BlogList(),
        ViewBlog.id: (context) => ViewBlog(),
        HomePage.id: (context) => HomePage(),
      },
      initialRoute: initialRoute,
    );
  }
}
