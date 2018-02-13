#include<Servo.h>
//#include <SoftwareSerial.h>
Servo myservo;
int pwm1=4;                                                                          //PWM1 pin of cytron for the rack motor(Rack and Pinion
int dir1=A3;
int md1=A2;
int mp1=5;
int md2=8;
int mp2=7;
int md3=11;
int mp3=12;
int md4=9;
int mp4=10;
int servo_pin=13; 
int servo_state=0;
int pos=0;
byte extenderstate=0;
int pneumaticpin1=A4;
int pneumaticpin2=A0;
void setup()
{
  // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600);
  myservo.attach(servo_pin);
  myservo.write(0);
  
  pinMode(pneumaticpin1,OUTPUT);
  pinMode(pneumaticpin2,OUTPUT);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW); 
//  pinMode(LEDPIN, OUTPUT);
//  digitalWrite(LEDPIN, LOW);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  char input = 0;
  if(Serial.available())
  {
    input = Serial.read();
  }
  switch (input)
  {
    case 'f':
    Serial.println("Rack  ->>>");
      forward(dir1,pwm1);
      delay(2000);
      halt(dir1,pwm1);
      break;
    case 'r':
    Serial.println("Rack <<<-");
      backward(dir1,pwm1);
      delay(2000);
      halt(dir1,pwm1);
      break;
    case 'w':
    Serial.println("Forward");
      front();
      delay(2000);
      stopbase();
      break;
    case 's':
    Serial.println("Backward");
      back();
      delay(2000);
      stopbase();
      break;
    case 'a':
    Serial.println("Left");
      left();
      delay(2000);
      stopbase();
      break;
    case 'd':
    Serial.println("Right");
      right();
      delay(2000);
      stopbase();
      break;
    case'h':
    Serial.println("Servo Rotate");
      servomove();
      delay(2000);
      
  }
  input= 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void forward(int dir,int pwm)                                                                           //This Function will tell the rack to move forward
{                                                            //Used to store the current position where the assembly is currently       
  digitalWrite(dir,LOW);
  analogWrite(pwm,100);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void halt(int dir,int pwm)                                
{                                                               
  digitalWrite(dir,LOW);
  analogWrite(pwm,0);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void backward(int dir,int pwm)                                                                         //This function will tell the rack to move backward
{
  analogWrite(dir,255);
  analogWrite(pwm,100);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void extend()
{
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,HIGH);
  delay(1000);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
  Serial.println("pneumaticpin2 High");
  extenderstate=1;
  Serial.flush();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void contract()
{
  digitalWrite(pneumaticpin1,HIGH);
  digitalWrite(pneumaticpin2,LOW);
  delay(1000);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
  Serial.println("pneumaticpin1 LOW");
  extenderstate=0;
  Serial.flush();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void servomove(){
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 90; pos >=00; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void front(){
  forward(md1,mp1);
  forward(md2,mp2);
  forward(md3,mp3);
  forward(md4,mp4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void back(){
  backward(md1,mp1);
  backward(md2,mp2);
  backward(md3,mp3);
  backward(md4,mp4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void left(){
  forward(md1,mp1);
  backward(md2,mp2);
  forward(md4,mp4);
  backward(md3,mp3);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void right(){
  forward(md2,mp2);
  backward(md1,mp1);
  forward(md3,mp3);
  backward(md4,mp4);
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void stopbase(){
  halt(md1,mp1);
  halt(md2,mp2);
  halt(md3,mp3);
  halt(md4,mp4);
}

