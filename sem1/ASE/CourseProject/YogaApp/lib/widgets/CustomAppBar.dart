import 'package:flutter/material.dart';

class CustomAppBar extends StatelessWidget {
  final String text;
  final Alignment align;
  final double borderWidth;
  CustomAppBar({@required this.text, this.align, this.borderWidth});
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.symmetric(horizontal: 50, vertical: 0),
      width: double.infinity,
      height: 130,
      decoration: BoxDecoration(
        border: Border.all(color: Colors.grey[100], width: borderWidth),
        borderRadius: BorderRadius.only(bottomLeft: Radius.circular(100)),
        color: Colors.white,
      ),
      child: Align(
        alignment: align,
        child: FittedBox(
          fit: BoxFit.fitWidth,
          child: Text(
            text,
            style: TextStyle(
              fontSize: 30,
              color: Colors.black87,
              fontWeight: FontWeight.bold,
            ),
          ),
        ),
      ),
    );
  }
}
