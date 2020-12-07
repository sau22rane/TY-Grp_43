import 'package:YogaApp/homepage.dart';
import 'package:flutter/material.dart';
import 'package:YogaApp/courses/AsanaPlayer.dart';
import 'package:camera/camera.dart';
import 'package:YogaApp/temp/home.dart';

class AsanaCard extends StatefulWidget {
  final List<CameraDescription> cameras;
  @override
  _AsanaCardState createState() => _AsanaCardState();
  AsanaCard(this.cameras);
}

class _AsanaCardState extends State<AsanaCard> {
  @override
  Widget build(BuildContext context) {
    Size size = MediaQuery.of(context).size;
    return Padding(
      padding: const EdgeInsets.all(10),
      child: Container(
        decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.all(Radius.circular(50))),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceAround,
          children: <Widget>[
            CircleAvatar(
              radius: 35,
              backgroundImage: AssetImage("assets/images/profile.jpg"),
            ),
            Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              textBaseline: TextBaseline.ideographic,
              textDirection: TextDirection.ltr,
              children: <Widget>[
                SizedBox(
                  height: 10,
                ),
                Padding(
                  padding: const EdgeInsets.only(bottom: 10, top: 15),
                  child: Text(
                    "Suryanamaskar",
                    style: TextStyle(
                      fontWeight: FontWeight.w400,
                      fontSize: 18,
                    ),
                  ),
                ),
                SizedBox(
                  height: 5,
                ),
                Text(
                  "Strech your body",
                  style: TextStyle(
                    fontSize: 10,
                    fontWeight: FontWeight.w300,
                  ),
                ),
                Text(
                  "12 Streches",
                  style: TextStyle(fontSize: 10, fontWeight: FontWeight.w300),
                ),
                Padding(
                  padding: const EdgeInsets.only(bottom: 10),
                  child: Text(
                    "24 Repeatitons",
                    style: TextStyle(fontSize: 10, fontWeight: FontWeight.w300),
                  ),
                ),
                SizedBox(
                  height: 15,
                ),
              ],
            ),
            Column(
              children: <Widget>[
                Padding(
                  padding: const EdgeInsets.only(top: 10, bottom: 5),
                  child: Text(
                    "30 mins",
                    style: TextStyle(fontSize: 18, fontWeight: FontWeight.w400),
                  ),
                ),
                Padding(
                  padding: const EdgeInsets.only(top: 5, bottom: 5),
                  child: RaisedButton(
                    onPressed: () {
                      Navigator.push(context,
                          MaterialPageRoute(builder: (context) {
                        return AsanaPlayer(widget.cameras);
                        // return ganta(widget.cameras);
                      }));
                    },
                    elevation: 10,
                    color: Colors.green,
                    shape: RoundedRectangleBorder(
                      borderRadius: BorderRadius.circular(18),
                    ),
                    child: Text(
                      " Start ",
                      style: TextStyle(color: Colors.white),
                    ),
                  ),
                )
              ],
            ),
          ],
        ),
      ),
    );
  }
}
