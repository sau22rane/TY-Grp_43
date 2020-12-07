import 'package:flutter/material.dart';
import 'package:chewie/chewie.dart';
import 'package:video_player/video_player.dart';
import 'package:camera/camera.dart';
import 'package:tflite/tflite.dart';
import 'Detection/model.dart';
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
  String _model = "";

  @override
  void initState() {
    super.initState();
    videoPlayerController = VideoPlayerController.network(this.widget.url);
    chewieController = ChewieController(
      videoPlayerController: videoPlayerController,
      aspectRatio: 3 / 2,
      autoPlay: true,
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

    res = await Tflite.loadModel(
        model: "assets/posenet_mv1_075_float_from_checkpoints.tflite");
    print(res);
    print("MODEL LOADED SUCESSFULLY!!!");
  }

  onSelect(model) {
    setState(() {
      _model = model;
    });
    loadModel();
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
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text("Asana place"),
        ),
        body: Column(
          children: <Widget>[
            Camera(
              widget.camera,
              _model,
              setRecognitions,
            ),
            Container(
                decoration: BoxDecoration(color: Colors.lightBlueAccent),
                constraints: BoxConstraints.expand(
                  height: MediaQuery.of(context).size.height * 0.4,
                ),
                child: Chewie(controller: chewieController)),
          ],
        ),
      ),
    );
  }
}
