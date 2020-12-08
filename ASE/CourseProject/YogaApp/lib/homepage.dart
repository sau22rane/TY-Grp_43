import 'package:YogaApp/widgets/AppDrawer.dart';
import 'package:fl_chart/fl_chart.dart';
import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  static String id = "HomepAGE";
  @override
  _HomePage createState() => _HomePage();
}

class _HomePage extends State<HomePage> {
  List<Color> gradientColors = [
    const Color(0xff23b6e6),
    const Color(0xff02d39a),
  ];

  bool showAvg = false;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("My Yoga"),
      ),
      drawer: AppDrawer(),
      body: Column(
        children: [
          Expanded(
            flex: 1,
            child: Container(
              padding: EdgeInsets.symmetric(vertical: 10),
              child: Text("Health Inights",style: TextStyle(fontSize: 0 ,color: Colors.black , fontWeight: FontWeight.bold),),),
          ),
          Expanded(
            flex: 7,
            child: Padding(
              padding: const EdgeInsets.all(8.0),
              child: Stack(
                children: <Widget>[
                  AspectRatio(
                    aspectRatio: 1.20,
                    child: Container(
                      decoration: const BoxDecoration(
                          borderRadius: BorderRadius.all(
                            Radius.circular(18),
                          ),
                          color: Color(0xff232d37)),
                      child: Padding(
                        padding: const EdgeInsets.only(
                            right: 18.0, left: 12.0, top: 24, bottom: 12),
                        child: LineChart(
                           mainData(),
                        ),
                      ),
                    ),
                  ),
                  
                ],
              ),
            ),
          ),
          Expanded(
            flex: 7,
            child: MyScoreList(),
          ),
        ],
      ),
    );
  }

  LineChartData mainData() {
    return LineChartData(
      gridData: FlGridData(
        show: true,
        drawVerticalLine: true,
        getDrawingHorizontalLine: (value) {
          return FlLine(
            color: const Color(0xff37434d),
            strokeWidth: 1,
          );
        },
        getDrawingVerticalLine: (value) {
          return FlLine(
            color: const Color(0xff37434d),
            strokeWidth: 1,
          );
        },
      ),
      titlesData: FlTitlesData(
        show: true,
        bottomTitles: SideTitles(
          showTitles: true,
          reservedSize: 22,
          getTextStyles: (value) => const TextStyle(
              color: Color(0xff68737d),
              fontWeight: FontWeight.bold,
              fontSize: 16),
          getTitles: (value) {
            switch (value.toInt()) {
             case 2:
                return 'TUE';
              case 5:
                return 'THU';
              case 8:
                return 'SAT';
            }
            return '';
          },
          margin: 8,
        ),
        leftTitles: SideTitles(
          showTitles: true,
          getTextStyles: (value) => const TextStyle(
            color: Color(0xff67727d),
            fontWeight: FontWeight.bold,
            fontSize: 15,
          ),
          getTitles: (value) {
            switch (value.toInt()) {
              case 1:
                return '2';
              case 6:
                return '5';
              case 10:
                return '10';
            }
            return '';
          },
          reservedSize: 28,
          margin: 12,
        ),
      ),
      borderData: FlBorderData(
          show: true,
          border: Border.all(color: const Color(0xff37434d), width: 1)),
      minX: 0,
      maxX: 11,
      minY: 0,
      maxY: 11,
      lineBarsData: [
        LineChartBarData(
          spots: [
            FlSpot(0, 5),
            FlSpot(2.6, 3.4),
            FlSpot(4.9, 4.5),
            FlSpot(5.3, 7),
            FlSpot(6.4, 8),
            FlSpot(7.5, 5.1),
            FlSpot(8.2, 5.4),
            FlSpot(8.9, 5.6),
            FlSpot(9.5, 8),
            FlSpot(11, 10)
          ],
          isCurved: true,
          colors: gradientColors,
          barWidth: 5,
          isStrokeCapRound: true,
          dotData: FlDotData(
            show: false,
          ),
          belowBarData: BarAreaData(
            show: true,
            colors:
                gradientColors.map((color) => color.withOpacity(0.3)).toList(),
          ),
        ),
      ],
    );
  }

  
}

class MyScoreList extends StatefulWidget {
  @override
  _MyScoreListState createState() => _MyScoreListState();
}

class _MyScoreListState extends State<MyScoreList> {
  List<DateTime> dates = [];

  List<FlSpot> data = [];
dynamic month = [  "Jan",  "Feb", "Mar",  "Apr", "May",  "June",  "Jul",  "Aug",  "Sep",  "Oct",  "Nov",  "Dec" ];
  dynamic dayData = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];

  List<double> scores = [3.4,4.5,7,8,5.1,5.4,5.6,8,10];

  var now = DateTime.parse("20201207");

  datesCalc(int count) {
    for (int i = 0; i < count; i++) {
      dates.add(now);
      data.add(FlSpot(now.weekday.toDouble(), scores[i]));
      now = now.add(new Duration(days: 1));
      
    }
  }

  @override
  Widget build(BuildContext context) {
    //print("i am here");
    datesCalc(scores.length);
    return ListView.builder(
      itemCount: dates.length-1,
      itemBuilder: (context, index) {
        return Card(
          child: ListTile(
            leading: Icon(
              Icons.favorite,
              color: const Color(0xff02d39a),
              
            ),
            title: Text(   dayData[dates[index].weekday-1] + "\t,\t" + dates[index].day.toString()+ "\t\t" + month[dates[index].month-1]+ "\t" + dates[index].year.toString() +
                  "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t"+scores[index].toString(),textAlign: TextAlign.center,),
            
          ),
        );
      },
    );
  }
}
// import 'package:YogaApp/widgets/AppDrawer.dart';
// import 'package:fl_chart/fl_chart.dart';
// import 'package:flutter/material.dart';

// class HomePage extends StatefulWidget {
//   static final String id = "HomePage";
//   @override
//   _HomePage createState() => _HomePage();
// }

// int count = 7;
// dynamic dayData = ["Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"];

// // dynamic monthData =
// //     '{ "1" : "Jan", "2" : "Feb", "3" : "Mar", "4" : "Apr", "5" : "May", "6" : "June", "7" : "Jul", "8" : "Aug", "9" : "Sep", "10" : "Oct", "11" : "Nov", "12" : "Dec" }';

// class _HomePage extends State<HomePage> {
//   List<Color> gradientColors = [
//     const Color(0xff23b6e6),
//     const Color(0xff02d39a),
//   ];

//   bool showAvg = false;

//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: Text("My Yoga"),
//       ),
//       drawer: AppDrawer(),
//       body: Column(
//         children: [
//           // Expanded(
//           //   flex: 2,
//           //   child: Container(),
//           // ),
//           Expanded(
//             flex: 7,
//             child: Padding(
//               padding: const EdgeInsets.all(8.0),
//               child: Stack(
//                 children: <Widget>[
//                   AspectRatio(
//                     aspectRatio: 1.20,
//                     child: Container(
//                       decoration: const BoxDecoration(
//                           borderRadius: BorderRadius.all(
//                             Radius.circular(18),
//                           ),
//                           color: Color(0xff232d37)),
//                       child: Padding(
//                         padding: const EdgeInsets.only(
//                             right: 18.0, left: 12.0, top: 24, bottom: 12),
//                         child: LineChart(
//                           mainData(),
//                         ),
//                       ),
//                     ),
//                   ),
//                 ],
//               ),
//             ),
//           ),
//           Expanded(
//             flex: 3,
//             child: Container(),
//           ),
//         ],
//       ),
//     );
//   }

//   LineChartData mainData() {
//     List<DateTime> dates = [];
//     List<FlSpot> data = [];
//     List<double> scores = [2.3, 4.5, 2, 10, 5.6, 7.8, 9.9, 10];
//     var now = DateTime.parse("20201207");
//     print(now.weekday);
//     for (int i = 0; i < count; i++) {
//       dates.add(now);
//       data.add(FlSpot(now.weekday.toDouble(), scores[i]));
//       now = now.add(new Duration(days: 1));
//       print(dates[i]);
//       print(data[i].x);
//     }

//     return LineChartData(
//       lineTouchData: LineTouchData(
//         enabled: true,
//         touchCallback: (LineTouchResponse lineTouchResponse)
//         {
//           return lineTouchResponse.lineBarSpots;
//           },
//       ),
//       gridData: FlGridData(
//         show: true,
//         drawVerticalLine: true,
//         getDrawingHorizontalLine: (value) {
//           return FlLine(
//             color: const Color(0xff37434d),
//             strokeWidth: 1,
//           );
//         },
//         getDrawingVerticalLine: (value) {
//           return FlLine(
//             color: const Color(0xff37434d),
//             strokeWidth: 1,
//           );
//         },
//       ),
//       titlesData: FlTitlesData(
//         show: true,
//         bottomTitles: SideTitles(
//           showTitles: true,
//           reservedSize: 22,
//           getTextStyles: (value) => const TextStyle(
//               color: Color(0xff68737d),
//               fontWeight: FontWeight.bold,
//               fontSize: 16),
//           getTitles: (value) {
//             return dayData[dates[value.toInt()].weekday];
//           },
//           margin: 8,
//         ),
//         leftTitles: SideTitles(
//           showTitles: true,
//           getTextStyles: (value) => const TextStyle(
//             color: Color(0xff67727d),
//             fontWeight: FontWeight.bold,
//             fontSize: 15,
//           ),
//           getTitles: (value) {
//             print(value);
//             return value.toString();
//           },
//           reservedSize: 28,
//           margin: 12,
//         ),
//       ),
//       borderData: FlBorderData(
//           show: true,
//           border: Border.all(color: const Color(0xff37434d), width: 1)),
//       minX: 1,
//       maxX: 7,
//       minY: 0,
//       maxY: 10,
//       lineBarsData: [
//         LineChartBarData(
//           spots: data,
//           isCurved: true,
//           colors: gradientColors,
//           barWidth: 7,
//           isStrokeCapRound: true,
//           dotData: FlDotData(
//             show: false,
//           ),
//           belowBarData: BarAreaData(
//             show: true,
//             colors:
//                 gradientColors.map((color) => color.withOpacity(0.3)).toList(),
//           ),
//         ),
//       ],
//     );
//   }
// }
