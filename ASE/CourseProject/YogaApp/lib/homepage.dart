import 'package:YogaApp/widgets/AppDrawer.dart';
import 'package:flutter/material.dart';
import 'widgets/AppDrawer.dart';

class HomePage extends StatelessWidget {
  static String id = "HomePage";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Virtual Yoga '),
      ),
      drawer: AppDrawer(),
      body: Container(
        margin: EdgeInsets.all(20),
        color: Colors.white,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            Expanded(
              flex: 5,
              child: Container(
                child: Center(
                  child: Text(
                    "Who are you ?",
                    style: TextStyle(color: Colors.black),
                    textScaleFactor: 3,
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 3,
              child: Container(
                height: 100,
                padding: EdgeInsets.all(20),
                margin: EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.deepPurple[200],
                  borderRadius: BorderRadius.circular(30),
                ),
                child: Center(
                  child: Text(
                    "Participant",
                    style: TextStyle(color: Colors.white),
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 3,
              child: Container(
                height: 100,
                padding: EdgeInsets.all(20),
                margin: EdgeInsets.all(20),
                decoration: BoxDecoration(
                  color: Colors.deepPurple,
                  borderRadius: BorderRadius.circular(30),
                ),
                child: Center(
                  child: Text(
                    "Trainee",
                    style: TextStyle(color: Colors.white),
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 4,
              child: Container(),
            ),
          ],
        ),
      ),
    );
  }
}
