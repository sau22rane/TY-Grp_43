import 'package:flutter/material.dart';
import 'package:YogaApp/courses/AsanaPlayer.dart';
import 'package:camera/camera.dart';
import 'package:firebase_database/firebase_database.dart';

class AsanaCard extends StatefulWidget {
  final List<CameraDescription> cameras;
  String _asana;
  String _url;

  @override
  _AsanaCardState createState() => _AsanaCardState();
  AsanaCard(this.cameras, this._asana);
}

class _AsanaCardState extends State<AsanaCard> {
  DatabaseReference _ref =
      FirebaseDatabase.instance.reference().child("Tutorials");

  Future readData() async {
    _ref.once().then((DataSnapshot snapshot) {
      print('snapshotData : ${snapshot.value}');
      Map<dynamic, dynamic> values = snapshot.value;

      print(values.toString());
      setState(() {
        widget._url = values[widget._asana];
        print(
            "===============set state of read data===============================");
        print(widget._url);
      });
    });
    print("witn in readdata");
    // return widget._tref;
  }

  @override
  void initState() {
    super.initState();
    readData();
  }

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
              backgroundImage:
                  AssetImage("assets/images/" + widget._asana + ".jpeg"),
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
                    widget._asana,
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
                        return AsanaPlayer(
                            widget.cameras, widget._asana, widget._url);
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
