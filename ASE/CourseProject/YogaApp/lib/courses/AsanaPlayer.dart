import 'package:YogaApp/ScoreViewer.dart';
import 'package:YogaApp/constants.dart';
import 'package:flutter/material.dart';
import 'package:chewie/chewie.dart';
import 'package:video_player/video_player.dart';
import 'package:camera/camera.dart';
import 'package:tflite/tflite.dart';
import 'Detection/Camera.dart';
import 'package:flutter_exoplayer/audioplayer.dart';


class AsanaPlayer extends StatefulWidget {
  final List<CameraDescription> camera;
  String _asana;
  String _url;
  @override
  _AsanaPlayerState createState() => _AsanaPlayerState();
  AsanaPlayer(this.camera, this._asana, this._url);
}

class _AsanaPlayerState extends State<AsanaPlayer> {
  VideoPlayerController videoPlayerController;
  ChewieController chewieController;
  bool flag = false;
  var result;

  AudioPlayer audioPlayer = AudioPlayer();
  static String url =
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/yoga1.mp4?alt=media&token=e9a66061-b452-47d9-9954-f56523d200fa";
  static Duration duration = new Duration(minutes: 0, seconds: 25);
  Video video = new Video(url: url, duration: duration);

  List<dynamic> _recognitions;
  int _imageHeight = 0;
  int _imageWidth = 0;
  String _model = posenet;
  int wait = 0;
  bool reach = false;

  @override
  void initState() {
    super.initState();
    if (widget.camera == null) {
      print("Camera null in asanaPlayer.dart file");
    }
    videoPlayerController = VideoPlayerController.network(widget._url);
    playAudio(
      first: true,
    );
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
    videoPlayerController.addListener(() {});
    chewieController.videoPlayerController.addListener(() async {
      if (chewieController.videoPlayerController.value.position.inSeconds ==
              video.duration.inSeconds &&
          flag == false) {
        //print("got it#################################");
        playAudio(
          first: false,
        );
        flag = true;
        result = await getRequest(_recognitions , widget._asana);
      }
      if (chewieController.videoPlayerController.value.position ==
          chewieController.videoPlayerController.value.duration  ) {
        {
          print(result);
          // (result != null) ?

          Navigator.push(context, MaterialPageRoute(builder: (context) {
            return ScoreViewer("9.4");
          }));
          // : {};
        }
      }
    });
  }

  loadModel() async {
    String res;
    //print("SELECTING POSENET");
    res = await Tflite.loadModel(
        model: "assets/posenet_mv1_075_float_from_checkpoints.tflite");
    print(res);
    //print("MODEL LOADED SUCESSFULLY!!!");
    setState(() {
      wait = 1;
    });
  }

  onSelect(model) {
    loadModel();
    //print("onselect complete");
  }

  setRecognitions(
    recognitions,
    imageHeight,
    imageWidth,
  ) {
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
    audioPlayer.dispose();
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
                padding: EdgeInsets.only(top: 50, left: 8, right: 8, bottom: 8),
                child: Chewie(controller: chewieController),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

void playAudio({bool first}) async {
  print("hii i am audio");
  String audioUrl2 =
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/hold_pose.mp3?alt=media&token=0928ce36-0128-436a-834f-130df4d33858";
  String audioUrl =
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/ttsMP3.com_VoiceText_2020-12-9_3_27_7.mp3?alt=media&token=397575ec-3916-4738-8941-481a2cf7e7af";
  AudioPlayer audioPlayer = new AudioPlayer();
  await audioPlayer.play(
    first ? audioUrl : audioUrl2,
    // playerMode: PlayerMode.BACKGROUND,
  );
}

class Video {
  String url;
  Duration duration;
  Video({this.duration, this.url});
}
