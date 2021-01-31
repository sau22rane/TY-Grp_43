import 'package:YogaApp/models/ResponseModel.dart';
import 'package:flutter/material.dart';
import 'package:camera/camera.dart';
import 'package:tflite/tflite.dart';
import 'dart:math' as math;
import 'package:YogaApp/constants.dart';
import 'package:http/http.dart' as http;

Future<String> getRequest(var recognition , String asana) async {
  if (recognition.length == 0) return "null";
  var temp;
  for (var d in recognition) {
    print(d["keypoints"].toString());
    temp = d["keypoints"];
  }

  String url = "http://sau22rane2.pythonanywhere.com/?asana=" +
      asana +
      "&course=" +
      "Course1" +
      "&cords=" +
      temp.toString();

  print("temp : " + temp.toString());
  String res = await http.read(url);
  print("result @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#####" + res);
  return res;
}

typedef void Callback(List<dynamic> list, int h, int w);

class Camera extends StatefulWidget {
  final List<CameraDescription> cameras;
  final Callback setRecognitions;
  final String model;

  Camera(this.cameras, this.model, this.setRecognitions);
  @override
  _CameraState createState() => _CameraState();
}

class _CameraState extends State<Camera> {
  List<dynamic> _recog;
  CameraController controller;
  bool isDetecting = false;
  @override
  void initState() {
    super.initState();

    if (widget.cameras == null || widget.cameras.length < 1) {
      print('No camera is found');
    } else {
      controller = new CameraController(
        widget.cameras[0],
        ResolutionPreset.high,
      );
      controller.initialize().then((_) {
        if (!mounted) {
          return;
        }
        setState(() {});

        controller.startImageStream((CameraImage img) {
          if (!isDetecting) {
            isDetecting = true;

            int startTime = new DateTime.now().millisecondsSinceEpoch;

            Tflite.runPoseNetOnFrame(
              bytesList: img.planes.map((plane) {
                return plane.bytes;
              }).toList(),
              imageHeight: img.height,
              imageWidth: img.width,
              numResults: 2,
            ).then((recognitions) {
              // result
              int endTime = new DateTime.now().millisecondsSinceEpoch;
              print("Detection took ${endTime - startTime}");

              widget.setRecognitions(recognitions, img.height, img.width);
              setState(() {
                _recog = recognitions;
              });
              print(recognitions.toList());

              isDetecting = false;
            });
          }
        });
      });
    }
  }

  @override
  void dispose() {
    controller?.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    if (controller == null || !controller.value.isInitialized) {
      return Container();
    }

    var tmp = MediaQuery.of(context).size;
    var screenH = math.max(tmp.height, tmp.width);
    var screenW = math.min(tmp.height, tmp.width);
    tmp = controller.value.previewSize;
    var previewH = math.max(tmp.height, tmp.width);
    var previewW = math.min(tmp.height, tmp.width);
    var screenRatio = screenH / screenW;
    var previewRatio = previewH / previewW;

    return Padding(
      padding: EdgeInsets.all(8),
      child: Stack(
        children: <Widget>[
          OverflowBox(
            maxHeight: screenRatio > previewRatio
                ? screenH
                : screenW / previewW * previewH,
            // height: tmp.height * 0.5,
            maxWidth: screenRatio > previewRatio
                ? screenH / previewH * previewW
                : screenW,
            // width: tmp.width * 0.5,
            child: CameraPreview(controller),
          ),
          Align(
            alignment: Alignment.bottomCenter,
            child: RaisedButton(
              onPressed: () async {
                // print(await http.read('http://sau22rane2.pythonanywhere.com/?asana=&course=courseName'));
                print(
                    "++++++++++++++++++++GET REQUEST started++++++++++++++++");
                 //await print(await getRequest(_recog));
                print("++++++++++++++++++++DONE GET REQUEST++++++++++++++++");
              },
              elevation: 10,
              child: Text("Send Frame"),
            ),
          )
        ],
      ),
    );
  }
}
