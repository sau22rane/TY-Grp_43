import 'package:flutter/material.dart';
// import 'package:chewie/chewie.dart';
// import 'package:video_player/video_player.dart';
// import 'package:tflite_flutter_plugin_example/classifier.dart';

class AsanaPlayer extends StatefulWidget {
  final String url =
      "https://firebasestorage.googleapis.com/v0/b/yogaapp-dc4e0.appspot.com/o/yoga1.mp4?alt=media&token=e9a66061-b452-47d9-9954-f56523d200fa";
  @override
  _AsanaPlayerState createState() => _AsanaPlayerState();
}

class _AsanaPlayerState extends State<AsanaPlayer> {
  @override
  Widget build(BuildContext context) {
    
    throw Container();
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
}
// class AsanaPlayer extends StatelessWidget {
// @override
// Widget build(BuildContext context) {
//     return Container();
//   }
// }
