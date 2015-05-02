#include <Servo.h> 

Servo servoLeft, servoMiddle, servoRight; //create servo objects

int leftAngle = 0;
int middleAngle = 0;
int rightAngle = 0;
int angleIncrement = 1;


// constants won't change. They're used here to 
// set pin numbers:
const int leftUp = 5;     // the number of the pushbutton pin
const int leftDown = 2;     // the number of the pushbutton pin
const int middleUp = 6;     // the number of the pushbutton pin
const int middleDown = 3;     // the number of the pushbutton pin
const int rightUp = 7;     // the number of the pushbutton pin
const int rightDown = 4;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int leftUpButtonState = 0;
int leftDownButtonState = 0;
int middleUpButtonState = 0;
int  middleDownButtonState = 0;
int rightUpButtonState = 0;
int rightDownButtonState = 0;


void setup() {


  servoLeft.attach(9);  // attaches the servo on pin 9 to the servo object 
  servoMiddle.attach(10);  // attaches the servo on pin 9 to the servo object 
  servoRight.attach(11);  // attaches the servo on pin 9 to the servo object 

  pinMode(leftUp, INPUT); 
  pinMode(leftDown, INPUT); 
  pinMode(middleUp, INPUT); 
  pinMode(middleDown, INPUT); 
  pinMode(rightUp, INPUT); 
  pinMode(rightDown, INPUT); 

}

void loop(){

  // read the state of the pushbutton value:
  leftUpButtonState = digitalRead(leftUp);
  leftDownButtonState = digitalRead(leftDown);
  middleUpButtonState = digitalRead(middleUp);
  middleDownButtonState = digitalRead(middleDown);
  rightUpButtonState = digitalRead(rightUp);
  rightDownButtonState = digitalRead(rightDown);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (leftUpButtonState == HIGH) {     
    // turn LED on:    
    leftAngle+=angleIncrement;
  } 
  if (leftDownButtonState == HIGH) {     
    // turn LED on:    
    leftAngle-=angleIncrement;
  } 
  if (middleUpButtonState == HIGH) {     
    // turn LED on:    
    middleAngle+=angleIncrement;
  } 
  if (middleDownButtonState == HIGH) {     
    // turn LED on:    
    middleAngle-=angleIncrement;
  } 
  if (rightUpButtonState == HIGH) {     
    // turn LED on:    
    rightAngle+=angleIncrement;
  } 
  if (rightDownButtonState == HIGH) {     
    // turn LED on:    
    rightAngle-=angleIncrement;
  } 
  leftAngle = constrain(leftAngle,0,180);
  middleAngle = constrain(middleAngle,0,180);
  rightAngle = constrain(rightAngle,0,180);

  servoLeft.write(leftAngle);
  servoMiddle.write(middleAngle);
  servoRight.write(rightAngle);
  delay(10);
}


