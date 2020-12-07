import 'package:flutter/material.dart';

import 'BlogList.dart';

class BlogTypeList extends StatelessWidget {
  static const String id = "BlogTypeList";
  static const List<List<String>> titles = [
    ["Outdoor Exercise", "\n128 topics 1.3K articles"],
    ["Yoga Technology", "\n110 topics 1K articles"],
    ["Health & Wellness", "\n80 topics 3K articles"],
    ["Health & Wellness", "\n80 topics 3K articles"]
  ];

  static const List<Color> colors = [
    Color(0xFF7400B8),
    Color(0xFF5E60CE),
    Color(0xFF74EA8DE),
    Color(0xFF64DFDF)
  ];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Column(
            children: [
              Container(
                padding: EdgeInsets.all(20),
                child: Text(
                  "Articles",
                  style: TextStyle(fontSize: 40, fontWeight: FontWeight.bold),
                ),
              ),
            ],
          ),
          Expanded(
            child: ListView.builder(
                itemCount: titles.length,
                itemBuilder: (context, index) {
                  return Container(
                    height: 250,
                    color: (index == colors.length - 1)
                        ? colors[index]
                        : colors[index + 1],
                    child: Container(
                      child: Align(
                        alignment: Alignment.center,
                        child: FittedBox(
                          fit: BoxFit.fitWidth,
                          child: GestureDetector(
                            onTap: () {
                              Navigator.pushNamed(context, BlogList.id,
                                  arguments: titles[index][0]);
                            },
                            child: Text(
                              titles[index][0] + titles[index][1],
                              style: TextStyle(
                                fontSize: 20,
                                color: Colors.white,
                                fontWeight: FontWeight.bold,
                              ),
                            ),
                          ),
                        ),
                      ),
                      decoration: BoxDecoration(
                        border: Border.all(color: colors[index], width: 2.0),
                        borderRadius:
                            BorderRadius.only(bottomLeft: Radius.circular(100)),
                        color: colors[index],
                      ),
                    ),
                  );
                }),
          ),
        ],
      ),
    );
  }
}
