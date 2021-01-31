import 'package:flutter/material.dart';
import 'package:flutter_plugin_pdf_viewer/flutter_plugin_pdf_viewer.dart';

class ViewBlog extends StatefulWidget {
  static final String id = "ViewBlog";
  final String data;
  ViewBlog(this.data);
  @override
  _ViewBlogState createState() => _ViewBlogState();
}

class _ViewBlogState extends State<ViewBlog> {
  PDFDocument doc;
  @override
  Widget build(BuildContext context) {
    //get data from first class
    String data = widget.data;
    viewNow() async {
      doc = await PDFDocument.fromURL(data);
      setState(() {});
    }

    Widget loading() {
      viewNow();
      if (doc == null) {
        return Center(child: Text("Loading"));
      }
      return Container();
    }

    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blue,
      ),
      body: doc == null ? loading() : PDFViewer(document: doc),
    );
  }
}
