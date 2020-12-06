import 'package:YogaApp/choose.dart';
import 'package:YogaApp/constants.dart';
import 'package:YogaApp/login_screens/registration_screen.dart';
import 'package:YogaApp/widgets/rounded_button.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/material.dart';
import 'package:modal_progress_hud/modal_progress_hud.dart';

class LoginScreen extends StatefulWidget {
  static const String id = 'login_screen';
  @override
  _LoginScreenState createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  bool showSpinner = false;
  final _auth = FirebaseAuth.instance;
  String email;
  String password;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: ModalProgressHUD(
        inAsyncCall: showSpinner,
        child: Padding(
          padding: EdgeInsets.symmetric(horizontal: 24.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: <Widget>[
              Flexible(
                child: Hero(
                  tag: 'logo',
                  child: Container(
                    height: 200.0,
                    child: Image.asset('assets/images/logo.png'),
                  ),
                ),
              ),
              SizedBox(
                height: 48.0,
              ),
              TextField(
                keyboardType: TextInputType.emailAddress,
                textAlign: TextAlign.center,
                onChanged: (value) {
                  email = value;
                },
                decoration:
                    kTextFieldDecoration.copyWith(hintText: 'Enter your email'),
              ),
              SizedBox(
                height: 8.0,
              ),
              TextField(
                obscureText: true,
                textAlign: TextAlign.center,
                onChanged: (value) {
                  password = value;
                },
                decoration: kTextFieldDecoration.copyWith(
                    hintText: 'Enter your password'),
              ),
              SizedBox(
                height: 24.0,
              ),
              RoundedButton(
                title: 'Log In',
                colour: Colors.deepPurple[400],
                onPressed: () async {
                  setState(() {
                    showSpinner = true;
                  });
                  try {
                    final user = await _auth.signInWithEmailAndPassword(
                        email: email, password: password);
                    if (user != null) {
                      Navigator.pushNamedAndRemoveUntil(
                          context, Choose.id, (context) => false);
                    }
                  } catch (e) {
                    print(e);
                    showDialog(
                      context: context,
                      builder: (BuildContext context) => AlertDialog(
                        title: Text("Login Failed"),
                        content: Text(
                            "Your email and password did not match.\nTry again."),
                        actions: [
                          FlatButton(
                            onPressed: () {
                              Navigator.pop(context);
                            },
                            child: Text("Close"),
                          ),
                        ],
                      ),
                    );
                  }
                  setState(() {
                    showSpinner = false;
                  });
                },
              ),
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    Text("Don't have an account ?"),
                    GestureDetector(
                      onTap: () {
                        Navigator.pushNamed(context, RegistrationScreen.id);
                      },
                      child: Text("Register Now",style: TextStyle(fontSize: 20,fontWeight: FontWeight.bold)),
                    )
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
