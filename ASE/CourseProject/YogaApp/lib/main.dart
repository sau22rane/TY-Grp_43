import 'package:YogaApp/ListOfAsanas.dart';
import 'package:YogaApp/courseList.dart';
import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'AsanaPlayer.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  // This widget is the root of your application.
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final dbref = FirebaseDatabase.instance.reference();

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: "Yoga",
      home: Scaffold(
        appBar: AppBar(
          title: Text("YOGA-APP"),
        ),
        body: Center(child: CourseList()),
        // body: ListOfAsanas(dbref, "stress"),
        // body: AsanaPlayer(),
      ),
    );
  }
}
