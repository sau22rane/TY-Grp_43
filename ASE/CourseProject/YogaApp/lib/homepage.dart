import 'package:YogaApp/widgets/AppDrawer.dart';
import 'package:flutter/material.dart';

class HomePage extends StatelessWidget {
  static String id = "Homepage";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('My Yoga '),
      ),
      drawer: AppDrawer(),
      body: Container(),
    );
  }
}
