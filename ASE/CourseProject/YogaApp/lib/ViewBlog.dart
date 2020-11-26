import 'package:flutter/material.dart';
import 'package:flutter_plugin_pdf_viewer/flutter_plugin_pdf_viewer.dart';

class ViewBlog extends StatefulWidget {
  static final String id = "ViewBlog";
  @override
  _ViewBlogState createState() => _ViewBlogState();
}

class _ViewBlogState extends State<ViewBlog> {
  PDFDocument doc;
  @override
  Widget build(BuildContext context) {
    //get data from first class
    String data = ModalRoute.of(context).settings.arguments;
    viewNow() async {
      doc = await PDFDocument.fromURL(data);
      setState(() {});
    }

    Widget loading() {
      viewNow();
      if (doc == null) {
        return Text("Loading");
      }
      return Container();
    }

    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.red,
        title: Text("Retrieve Pdf"),
      ),
      body: doc == null ? loading() : PDFViewer(document: doc),
    );
  }
}
