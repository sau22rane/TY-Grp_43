import 'package:YogaApp/constants.dart';
import 'package:flutter/material.dart';
import 'package:chewie/chewie.dart';
import 'package:video_player/video_player.dart';
import 'package:camera/camera.dart';
import 'package:tflite/tflite.dart';
import 'package:camera/camera.dart';
import 'Detection/Camera.dart';
//import 'package:tflite_flutter_plugin_example/classifier.dart';

class AsanaPlayer extends StatefulWidget {
  final List<CameraDescription> camera;
  String url =
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/yoga1.mp4?alt=media&token=e9a66061-b452-47d9-9954-f56523d200fa";
  @override
  _AsanaPlayerState createState() => _AsanaPlayerState();
  AsanaPlayer(this.camera);
}

class _AsanaPlayerState extends State<AsanaPlayer> {
  VideoPlayerController videoPlayerController;
  ChewieController chewieController;

  List<dynamic> _recognitions;
  int _imageHeight = 0;
  int _imageWidth = 0;
  String _model = posenet;
  int wait = 0;

  @override
  void initState() {
    super.initState();
    if (widget.camera == null) {
      print("Camera null in asanaPlayer.dart file");
    }
    videoPlayerController = VideoPlayerController.network(this.widget.url);
    chewieController = ChewieController(
      videoPlayerController: videoPlayerController,
      aspectRatio: 3 / 2,
      // autoPlay: true,
      // looping: true,
      // showControls: false,
      // materialProgressColors: ChewieProgressColors(
      //   playedColor: Colors.red,
      //   handleColor: Colors.blue,
      //   backgroundColor: Colors.grey,
      //   bufferedColor: Colors.lightGreen,
      // ),
      placeholder: Container(
        color: Colors.cyan,
      ),
      autoInitialize: true,
    );
  }

  loadModel() async {
    String res;
    switch (_model) {
      case yolo:
        res = await Tflite.loadModel(
          model: "assets/yolov2_tiny.tflite",
          labels: "assets/yolov2_tiny.txt",
        );
        break;

      case mobilenet:
        res = await Tflite.loadModel(
            model: "assets/mobilenet_v1_1.0_224.tflite",
            labels: "assets/mobilenet_v1_1.0_224.txt");
        break;

      case posenet:
        print("SELECTING POSENET");
        res = await Tflite.loadModel(
            model: "assets/posenet_mv1_075_float_from_checkpoints.tflite");
        break;

      default:
        print("Runing default case");
        res = await Tflite.loadModel(
            model: "assets/ssd_mobilenet.tflite",
            labels: "assets/ssd_mobilenet.txt");
    }
    print(res);
    print("MODEL LOADED SUCESSFULLY!!!");
    setState(() {
      wait = 1;
    });
  }

  onSelect(model) {
    loadModel();
    print("onselect complete");
  }

  setRecognitions(recognitions, imageHeight, imageWidth) {
    setState(() {
      _recognitions = recognitions;
      _imageHeight = imageHeight;
      _imageWidth = imageWidth;
    });
  }

  @override
  void dispose() {
    videoPlayerController.dispose();
    chewieController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    // onSelect(posenet);
    if (_model == "") {
      //onSelect(posenet);
    }
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text("Asana place"),
        ),
        body: Column(
          children: <Widget>[
            SizedBox(
              height: 100,
            ),
            Align(
              alignment: Alignment.topCenter,
              child: Container(
                  padding: EdgeInsets.all(8),
                  decoration: BoxDecoration(color: Colors.lightBlueAccent),
                  height: MediaQuery.of(context).size.height * 0.35,
                  child: wait == 0
                      ? RaisedButton(
                          // onPressed: () => onSelect(posenet),
                          onPressed: () {
                            onSelect(posenet);
                          },
                          child: Text("Start"),
                        )
                      : Camera(
                          widget.camera,
                          _model,
                          setRecognitions,
                        )),
            ),
            Align(
              alignment: Alignment.bottomCenter,
              child: Container(
                  decoration: BoxDecoration(color: Colors.lightBlueAccent),
                  padding:
                      EdgeInsets.only(top: 50, left: 8, right: 8, bottom: 8),
                  child: Chewie(controller: chewieController)),
            ),
          ],
        ),
      ),
    );
  }
}
