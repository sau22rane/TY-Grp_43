import 'package:YogaApp/constants.dart';
import 'package:flutter/material.dart';
import 'package:chewie/chewie.dart';
import 'package:video_player/video_player.dart';
import 'package:camera/camera.dart';
import 'package:tflite/tflite.dart';
import 'package:camera/camera.dart';
import 'Detection/Camera.dart';

class AsanaPlayer extends StatefulWidget {
<<<<<<< HEAD
  final List<CameraDescription> camera;
  String url =
=======
  final String url =
>>>>>>> 01361d89944cc61a6924f20dff7c1cbfcaf552eb
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/yoga1.mp4?alt=media&token=e9a66061-b452-47d9-9954-f56523d200fa";
  @override
  _AsanaPlayerState createState() => _AsanaPlayerState();
  AsanaPlayer(this.camera);
}

class _AsanaPlayerState extends State<AsanaPlayer> {
<<<<<<< HEAD
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
=======
  @override
  Widget build(BuildContext context) {
    
    throw Container();
>>>>>>> 01361d89944cc61a6924f20dff7c1cbfcaf552eb
  }
  // VideoPlayerController videoPlayerController;
  // ChewieController chewieController;
  // @override
  // void initState() {
  //   super.initState();
  //   videoPlayerController = VideoPlayerController.network(this.widget.url);
  //   chewieController = ChewieController(
  //     videoPlayerController: videoPlayerController,
  //     aspectRatio: 3 / 2,
  //     autoPlay: true,
  //     // looping: true,
  //     // showControls: false,
  //     // materialProgressColors: ChewieProgressColors(
  //     //   playedColor: Colors.red,
  //     //   handleColor: Colors.blue,
  //     //   backgroundColor: Colors.grey,
  //     //   bufferedColor: Colors.lightGreen,
  //     // ),
  //     placeholder: Container(
  //       color: Colors.cyan,
  //     ),
  //     autoInitialize: true,
  //   );
  // }

<<<<<<< HEAD
  loadModel() async {
    String res;

    print("SELECTING POSENET");
    res = await Tflite.loadModel(
        model: "assets/posenet_mv1_075_float_from_checkpoints.tflite");
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
                  width: MediaQuery.of(context).size.width,
                  child: wait == 0
                      ? RaisedButton(
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
=======
  // @override
  // void dispose() {
  //   videoPlayerController.dispose();
  //   chewieController.dispose();
  //   super.dispose();
  // }

  // @override
  // Widget build(BuildContext context) {
  //   return MaterialApp(
  //     home: Scaffold(
  //       appBar: AppBar(
  //         title: Text("Asana place"),
  //       ),
  //       body: Container(
  //           decoration: BoxDecoration(color: Colors.lightBlueAccent),
  //           constraints: BoxConstraints.expand(
  //             height: MediaQuery.of(context).size.height,
  //           ),
  //           child: Chewie(controller: chewieController)),
  //     ),
  //   );
  // }
>>>>>>> 01361d89944cc61a6924f20dff7c1cbfcaf552eb
}
