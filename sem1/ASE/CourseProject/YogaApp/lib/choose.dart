import 'package:flutter/material.dart';
import 'homepage.dart';
import 'package:shared_preferences/shared_preferences.dart';

class Choose extends StatelessWidget {
  static String id = "Choose";
  setPractioner(bool value) async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    prefs.setBool('Participant/Trainee', value);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Container(
        margin: EdgeInsets.all(40),
        color: Colors.white12,
        child: Padding(
          padding: const EdgeInsets.all(20.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              Expanded(
                flex: 5,
                child: Padding(
                  padding: const EdgeInsets.all(10.0),
                  child: Image.asset('assets/images/logo2.png'),
                ),
              ),
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
                    color: const Color(0xFF56CFE1),
                    borderRadius: BorderRadius.circular(30),
                  ),
                  child: Center(
                    child: GestureDetector(
                      onTap: () {
                        setPractioner(true);
                  
                        Navigator.pushNamedAndRemoveUntil(context, HomePage.id,(context) =>false);
                      },
                      child: Text(
                        "PARTICIPANT",
                        style: TextStyle(color: Colors.white, fontSize: 20),
                      ),
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
                    color: const Color(0xFF5390D9),
                    borderRadius: BorderRadius.circular(30),
                  ),
                  child: Center(
                    child: GestureDetector(
                      onTap: () {
                         setPractioner(false);
                        Navigator.pushNamedAndRemoveUntil(context, HomePage.id,(context) =>false);
                        //Navigator.pushNamed(context, HomePage.id);
                       
                      },
                      child: Text(
                        "TRAINEE",
                        style: TextStyle(color: Colors.white, fontSize: 20),
                      ),
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
      ),
    );
  }
}
