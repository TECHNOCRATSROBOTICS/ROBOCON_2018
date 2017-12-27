
 /*
 * uncomment ps2
 * change rx and tx pins
 * 
*/
#include<Servo.h>
#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
int Select=1,Start=1,Ps2_UP=1,Ps2_LEFT=1,Ps2_DOWN=1,Ps2_RIGHT=1,Ps2_LEFT1=1,Ps2_LEFT2=1,Ps2_RIGHT1=1,Ps2_RIGHT2=1,Ps2_TRIANGLE=1,Ps2_CIRCLE=1,Ps2_CROSS=1,Ps2_SQUARE=1;
Cytron_PS2Shield ps2(2,3);
Servo servo1;
//Cytron_PS2Shield ps2;
byte pwm1=5;                                                                          //PWM1 pin of cytron for the rack motor
byte dir1=4;
byte servo_pin=A0; 
byte servo_state=0;
byte extenderstate=0;
int pneumaticpin1=A1;
int pneumaticpin2=A2;

unsigned int servo_angle=0;
void setup()
{
  ps2.begin(9600); 
  // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600);
  servo1.attach(servo_pin);
  delay(2000);
  Serial.println("Initialized");
  
  pinMode(pneumaticpin1,OUTPUT);
  pinMode(pneumaticpin2,OUTPUT);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW); 
//  pinMode(LEDPIN, OUTPUT);
//  digitalWrite(LEDPIN, LOW);
}


void loop()
{
  Select=ps2.readButton(PS2_SELECT);
  Start=ps2.readButton(PS2_START);
  Ps2_UP=ps2.readButton(PS2_UP);
  Ps2_DOWN=ps2.readButton(PS2_DOWN);
  Ps2_RIGHT=ps2.readButton(PS2_RIGHT);
  Ps2_LEFT=ps2.readButton(PS2_LEFT);
  Ps2_LEFT1=ps2.readButton(PS2_LEFT_1);
  Ps2_LEFT2=ps2.readButton(PS2_LEFT_2);
  Ps2_RIGHT1=ps2.readButton(PS2_RIGHT_1);
  Ps2_RIGHT2=ps2.readButton(PS2_RIGHT_2);
  Ps2_TRIANGLE=ps2.readButton(PS2_TRIANGLE);
  Ps2_CIRCLE=ps2.readButton(PS2_CIRCLE);
  Ps2_CROSS=ps2.readButton(PS2_CROSS);
  Ps2_SQUARE=ps2.readButton(PS2_SQUARE);
  if(Ps2_LEFT== 0)
  Serial.println("PS2_LEFT");
  else if(Ps2_RIGHT== 0)
  Serial.println("PS2_RIGHT");
  else if(Ps2_UP== 0)
  Serial.println("PS2_UP");
  else if(Ps2_DOWN== 0)
  Serial.println("PS2_DOWN");
  else if(Ps2_LEFT1== 0)
  {
   Serial.println("PS2 LEFT1");
  Serial.write('L');
  delay(1000);
  }
  else if(Ps2_LEFT2== 0)
  Serial.println("PS2_LEFT2");
  else if(Ps2_LEFT2== 0){
  Serial.println("PS2_LEFT2");//motor transfer
  forward();
  }
  else if(Ps2_RIGHT1== 0){
    if(extenderstate==0){
    extend();
    }
  else if(extenderstate==1){
    contract();
    }
  }
  Serial.println("PS2_RIGHT1");
  else if(Ps2_RIGHT2== 0){
  Serial.println("PS2_RIGHT2");//motor transfer
  backward();
  }
  else if(Ps2_CIRCLE==0)
  Serial.println("CIRCLE");
  else if(Ps2_TRIANGLE== 0)
  Serial.println("PS2_TRIANGLE");
  else if(Ps2_CROSS== 0){
  Serial.println("PS2_CROSS");//Servo motor
  if(servo_state==0){servo_extend();}
  else { servo_retract();}
  }
  else if(Ps2_SQUARE== 0)
  { 
  Serial.println("PS2_SQUARE");
  Serial.write('R');
  delay(1000);
  }
 
}
void forward()                                                                           //This Function will tell the rack to move forward
{                                                            //Used to store the current position where the assembly is currently       
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,250);
}
void backward()                                                                         //This function will tell the rack to move backward
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,250);
}
void extend()
{
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,HIGH);
  delay(1000);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
  Serial.println("pneumaticpin2 High");
  extenderstate=1;
  //Serial.flush();
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
  //Serial.flush();
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void servo_extend(){

  int i=0;
  for(i=servo_angle;i<90;i++)
  {
    servo1.write(i);
  }
  servo_state=1;
  servo_angle=90;
}

void servo_retract(){
  int i;
  for(i=servo_angle;i>0;i--)
  {
    servo1.write(i);
  }
  servo_state=0;
  servo_angle=0;
}


