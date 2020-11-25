import 'package:flutter/material.dart';
import 'widgets/CustomAppBar.dart';

class BlogList extends StatelessWidget {
  static const String id = "Blog";
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blue,
      body: Column(
        children: [
          Expanded(
            flex: 2,
            child: CustomAppBar(
                text: 'Articles',
                align: Alignment.centerLeft,
                borderWidth: 2.0),
          ),
          Expanded(
            flex: 2,
            child: Container(
              color: Colors.red,
              child: Container(
                child: Align(
                  alignment: Alignment.center,
                  child: FittedBox(
                    fit: BoxFit.fitWidth,
                    child: Text(
                      "Outdoor Exercise \n 128 topics  - 1.3K articles",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ),
                decoration: BoxDecoration(
                  border: Border.all(color: Colors.blue, width: 2.0),
                  borderRadius:
                      BorderRadius.only(bottomLeft: Radius.circular(100)),
                  color: Colors.blue,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 2,
            child: Container(
              color: Colors.cyan,
              child: Container(
                child: Align(
                  alignment: Alignment.center,
                  child: FittedBox(
                    fit: BoxFit.fitWidth,
                    child: Text(
                      "Yoga Technology \n 110 topics  - 1K articles",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ),
                decoration: BoxDecoration(
                  border: Border.all(color: Colors.red, width: 2.0),
                  borderRadius:
                      BorderRadius.only(bottomLeft: Radius.circular(100)),
                  color: Colors.red,
                ),
              ),
            ),
          ),
          Expanded(
            flex: 2,
            child: Container(
              color: Colors.white,
              child: Container(
                child: Align(
                  alignment: Alignment.center,
                  child: FittedBox(
                    fit: BoxFit.fitWidth,
                    child: Text(
                      "Health & Wellness \n 80 topics  - 3K articles",
                      style: TextStyle(
                        fontSize: 20,
                        color: Colors.white,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                ),
                decoration: BoxDecoration(
                  border: Border.all(color: Colors.cyan, width: 2.0),
                  borderRadius:
                      BorderRadius.only(bottomLeft: Radius.circular(100)),
                  color: Colors.cyan,
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}
