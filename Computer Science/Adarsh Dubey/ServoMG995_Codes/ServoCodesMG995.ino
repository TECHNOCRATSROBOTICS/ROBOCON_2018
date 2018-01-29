//for servo mg995
#include <Servo.h>

Servo myservo;  //create an object of class servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  //the servo rotates clockwise for 0<value<90 and -ve clockwise from 90<value<180
  //apply apropriate delay to gain desiered angle
 myservo.write(0);
 delay(200);
 myservo.write(90);
 delay(200);
 myservo.write(180);
 delay(200);
}

