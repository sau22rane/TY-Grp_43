import 'package:YogaApp/widgets/AppDrawer.dart';
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

  static  List<Color> colors = [
    // Colors.grey,
    // Colors.orange,
    // Colors.green,
    // Colors.blue,

    
    Color(0xFF5E60CE),
    Color(0xFF4EA8DE),
    Color(0xFF56CFE1),
    Color(0xFF72EFDD),
  ];
  @override
  Widget build(BuildContext context) {
    return Scaffold(
       appBar: AppBar(
         backgroundColor:  colors[0],title: Text("Articles"
         ,style: TextStyle(color: Colors.white,
         ),
         ),
         
         actionsIconTheme: IconThemeData(color: Colors.black),
       ),
      drawer: AppDrawer(),
      backgroundColor: Colors.white,
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          // Column(
          //   children: [
          //     Container(
          //       padding: EdgeInsets.all(20),
          //       child: Text(
          //         "Articles",
          //         style: TextStyle(fontSize: 40, fontWeight: FontWeight.bold),
          //       ),
          //     ),
          //   ],
          // ),
          Expanded(
            child: ListView.builder(
                itemCount: titles.length,
                itemBuilder: (context, index) {
                  return Container(
                    height: 200,
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
                              Navigator.push(context,MaterialPageRoute(builder: (context) {
                                return BlogList(type : titles[index][0]);
                                  }));
                            },
                            child: Column(
                              children: [
                                Text(
                                  titles[index][0] ,
                                  style: TextStyle(
                                    fontSize: 20,
                                    color: Colors.white,
                                    fontWeight: FontWeight.bold,
                                  ),
                                ),
                                Text(
                                  titles[index][1] ,
                                  style: TextStyle(
                                    fontSize: 15,
                                    color: Colors.white,
                                    fontStyle: FontStyle.italic
                                    
                                  ),
                                ),
                              ],
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
