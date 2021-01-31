import 'package:YogaApp/courses/ListOfAsanas.dart';
import 'package:slimy_card/slimy_card.dart';
import 'package:flutter/material.dart';

class ScoreViewer extends StatefulWidget {
  static String id = "Scoreviewer";
  String result;
  ScoreViewer(this.result);
  @override
  _ScoreViewer createState() => _ScoreViewer();
}

class _ScoreViewer extends State<ScoreViewer> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: StreamBuilder(
        // This streamBuilder reads the real-time status of SlimyCard.
        initialData: false,
        stream: slimyCard.stream, //Stream of SlimyCard
        builder: ((BuildContext context, AsyncSnapshot snapshot) {
          return ListView(
            padding: EdgeInsets.zero,
            children: <Widget>[
              SizedBox(height: 200),

              // SlimyCard is being called here.
              SlimyCard(
                width: 350,
                // In topCardWidget below, imagePath changes according to the
                // status of the SlimyCard(snapshot.data).
                topCardWidget: topCardWidget('assets/images/success.gif'),
                bottomCardWidget: bottomCardWidget(widget.result),
              ),
            ],
          );
        }),
      ),
    );
  }

  // This widget will be passed as Top Card's Widget.
  Widget topCardWidget(String imagePath) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: <Widget>[
        Container(
          height: 150,
          width: 150,
          decoration: BoxDecoration(
            color: Colors.white,
            borderRadius: BorderRadius.circular(15),
            image: DecorationImage(image: AssetImage(imagePath)),
            boxShadow: [
              BoxShadow(
                color: Colors.black.withOpacity(0.1),
                blurRadius: 20,
                spreadRadius: 1,
              ),
            ],
          ),
        ),
        SizedBox(height: 15),
        Text(
          'Hurray ! ',
          style: TextStyle(color: Colors.white, fontSize: 20),
        ),
        SizedBox(height: 15),
        Text(
          'Click below to reveal your score ',
          style: TextStyle(
              color: Colors.white.withOpacity(0.8),
              fontSize: 12,
              fontWeight: FontWeight.w500),
        ),
        SizedBox(height: 10),
      ],
    );
  }

  // This widget will be passed as Bottom Card's Widget.
  Widget bottomCardWidget(String result) {
    String y;
    // if (x <= 3) {
    //   y = "Fair , Let's practise more ";
    // } else if (x <= 7) {
    //   y = "Good Job !";
    // }
    // else
    // {
    //   y = "Excellent , You are an expert now!";
    // }
    return Column(
      children: [
        Expanded(
          child: Text(
            widget.result,
            style: TextStyle(
              color: Colors.white,
              fontSize: 20,
              fontWeight: FontWeight.w500,
            ),
            textAlign: TextAlign.center,
          ),
        ),
        Expanded(
          child: RaisedButton(
            padding: EdgeInsets.all(20),
            color: Colors.white,
            child: Text(
              "Next",
              style: TextStyle(color: Colors.black),
            ),
            onPressed: () {
              Navigator.pop(context);
            },
          ),
        ),
      ],
    );
  }
}