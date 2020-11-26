import 'package:flutter/material.dart';
import 'widgets/CustomAppBar.dart';
import 'BlogList.dart';

class BlogTypeList extends StatelessWidget {
  static const String id = "BlogTypeList";
  static const List<String> titles = [
    "Outdoor Exercise \n 128 topics  - 1.3K articles",
    "Yoga Technology \n 110 topics  - 1K articles",
    "Health & Wellness \n 80 topics  - 3K articles"
  ];

  static const List<Color> colors = [Colors.blue, Colors.red, Colors.cyan];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blue,
      body: Column(
        mainAxisAlignment: MainAxisAlignment.start,
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Expanded(
            flex: 2,
            child: CustomAppBar(
                text: 'Articles',
                align: Alignment.centerLeft,
                borderWidth: 3.0),
          ),
          Expanded(
            flex: 8,
            child: ListView.builder(
                itemCount: titles.length,
                itemBuilder: (context, index) {
                  return Container(
                    color: (index == colors.length - 1)
                        ? Colors.white
                        : colors[index + 1],
                    child: Container(
                      child: Align(
                        alignment: Alignment.center,
                        child: FittedBox(
                          fit: BoxFit.fitWidth,
                          child: GestureDetector(
                            onTap: () {
                              Navigator.pushNamed(context, BlogList.id,
                                  arguments: titles[index]);
                            },
                            child: Text(
                              titles[index],
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
