/*
       Dir  Pwm   Motor
   M1   8    9      rf
   M2   A0    7     rb
   M3   A2    3     lb
   M4    4    5     lf

*/
#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
#include<Servo.h>

Servo myservo;
int pos = 0;
int servo_pin = 12;
int servo_state = 0;

//PS2Shield ps2;
int Select = 1, Start = 1, Ps2_UP = 1, Ps2_LEFT = 1, Ps2_DOWN = 1, Ps2_RIGHT = 1, Ps2_LEFT1 = 1, Ps2_LEFT2 = 1, Ps2_RIGHT1 = 1, Ps2_RIGHT2 = 1, Ps2_TRIANGLE = 1, Ps2_CIRCLE = 1, Ps2_CROSS = 1, Ps2_SQUARE = 1;
int pwmx = 0, pwmy = 0, rx = 0, ly = 0;
int rackFlag = 0, servoFlag = 0;
int underRackpin1=18,underRackpin2=19;
int k=0;
void eextend();
void ccontract();
void servomove();
Cytron_PS2Shield ps2(10, 11);

//Class Definition for Base Motors(MAnual Bot)
class BaseMotor
{
  public:
    int lf, lb, rf, rb, dlf, drf, dlb, drb;
    int dir_lf = 4, dir_rf = 8, dir_lb = A2, dir_rb = A0, pwm_lf = 5, pwm_rf = 9, pwm_lb = 3, pwm_rb = 7;
    void moveMotor(int lf, int lb, int rf, int rb, int dlf, int drf, int dlb, int drb);
} m;

class transferMechanism
{
  public:
    int rackDir = A3, rackPwm = 2, pneumaticPin1 = A4, pneumaticPin2 = A5;
    void servoMotion();
    void forward();
    void backward();
    void halt();
    void rackPinion();
    void extend();
    void contract();
    void force_ground();
    int extenderstate = 0;
} t;

void setup()
{
  ps2.begin(9600);
  Serial.begin(9600);
  myservo.attach(servo_pin);
  myservo.write(90);
  pinMode(underRackpin1, OUTPUT);
  pinMode(underRackpin2, OUTPUT);
  pinMode(t.pneumaticPin1, OUTPUT);
  pinMode(t.pneumaticPin2, OUTPUT);
}

void loop()
{
  Select = ps2.readButton(PS2_SELECT);
  Start = ps2.readButton(PS2_START);
  Ps2_UP = ps2.readButton(PS2_UP);
  Ps2_DOWN = ps2.readButton(PS2_DOWN);
  Ps2_RIGHT = ps2.readButton(PS2_RIGHT);
  Ps2_LEFT = ps2.readButton(PS2_LEFT);
  Ps2_LEFT1 = ps2.readButton(PS2_LEFT_1);
  Ps2_LEFT2 = ps2.readButton(PS2_LEFT_2);
  Ps2_RIGHT1 = ps2.readButton(PS2_RIGHT_1);
  Ps2_RIGHT2 = ps2.readButton(PS2_RIGHT_2);
  Ps2_TRIANGLE = ps2.readButton(PS2_TRIANGLE);
  Ps2_CIRCLE = ps2.readButton(PS2_CIRCLE);
  Ps2_CROSS = ps2.readButton(PS2_CROSS);
  Ps2_SQUARE = ps2.readButton(PS2_SQUARE);
  rx = 128 - ps2.readButton(PS2_JOYSTICK_RIGHT_X_AXIS);
  ly = 128 - ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
  pwmx = map(rx, 0, 128, 0, 100);
  pwmy = map(ly, 0, 128, 0, 100);
  ps2.vibrate(1,0);
  if(Select==0 )
  {
  ps2.vibrate(1,1);
  delay(200);
  k=1;
  while(k==1){
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
  if(Select==0){
    Serial.println("Select");
    k=0;
    }
   else if(Ps2_RIGHT== 0){
  Serial.write('H');
  delay(200);
   }
  else if(Ps2_UP== 0){
  Serial.write('E');
  delay(200);
  }
  else if(Ps2_DOWN== 0){
  Serial.write('F');
  delay(200);
  }
  else if(Ps2_LEFT== 0){
  Serial.write('G');
  delay(200);
  }
  /*else if(Ps2_LEFT1== 0)
  Serial.println("2--PS2_LEFT1");
  else if(Ps2_LEFT2== 0)
  Serial.println("2--PS2_LEFT2");
  else if(Ps2_RIGHT1== 0)
  Serial.println("2--PS2_RIGHT1");
  else if(Ps2_RIGHT2== 0)
  Serial.println("2--PS2_RIGHT2");*/
  else if(Ps2_CIRCLE==0){
  Serial.write('D');
  delay(200);
  }
  else if(Ps2_TRIANGLE== 0){
  Serial.write('A');
  delay(200);
  }
  else if(Ps2_CROSS== 0){
  Serial.write('B');
  delay(200);
  }
  else if(Ps2_SQUARE== 0){
  Serial.write('C');
  delay(200);
  }
  }
  delay(200);
  }
  else if (Ps2_LEFT == 0)
    m.moveMotor(150, 150, 150, 150, 0, 0, 1, 1);
  else if (Ps2_RIGHT == 0)
    m.moveMotor(150, 150, 150, 150, 1, 1, 0, 0);
  else if (Ps2_UP == 0)
    m.moveMotor(30, 30, 30, 30, 1, 1, 0, 0);
  else if (Ps2_DOWN == 0)
    m.moveMotor(30, 30, 30, 30, 0, 0, 1, 1);
  else if (Ps2_SQUARE == 0)
  {
    Serial.write('R');
    delay(1000);
  }
  else if (Ps2_TRIANGLE == 0)
  {
    
    Serial.write('I');
    delay(1000);
  }
  else if (Ps2_CIRCLE == 0)
  {
    Serial.write('L');
    delay(1000);
  }
  else if (Ps2_CROSS == 0)
  {
    if (t.extenderstate == 0)
      t.extend();
    else if (t.extenderstate == 1)
      t.contract();
  }
  else if (Ps2_LEFT1 == 0)
  {
    t.force_ground();
    Serial.write('K');
    delay(1000);
  }
  else if (Ps2_LEFT2 == 0)
    servomove();
  else if (Ps2_RIGHT1 == 0)
    t.forward();
  else if (Ps2_RIGHT2 == 0)
    t.backward();
  else if (pwmy > 10)
    m.moveMotor(pwmy, pwmy, pwmy, pwmy, 255, 255, 0, 0);
  else if (pwmy < -10)
    m.moveMotor(-pwmy, -pwmy, -pwmy, -pwmy, 0, 0, 255, 255);
  else if (pwmx > 10)
    m.moveMotor(pwmx, pwmx, pwmx, pwmx, 0, 0, 0, 0);
  else if (pwmx < -10)
    m.moveMotor(-pwmx, -pwmx, -pwmx, -pwmx, 255, 255, 255, 255);
  else
  {
    m.moveMotor(0, 0, 0, 0, 0, 0, 0, 0);
    t.halt();
  }
}

void BaseMotor::moveMotor(int lf, int lb, int rf, int rb, int dlf, int drf, int dlb, int drb)
{
  analogWrite(dir_lf, dlf);
  analogWrite(pwm_lf, lf); // Left Forward

  analogWrite(dir_rf, drf);
  analogWrite(pwm_rf, rf); // Right Forward

  analogWrite(dir_lb, dlb);
  analogWrite(pwm_lb, lb); // Left Backward

  analogWrite(dir_rb, drb);
  analogWrite(pwm_rb, rb); // Right Backward
}

void transferMechanism::forward()                                                                           //This Function will tell the rack to move forward
{ //Used to store the current position where the assembly is currently
  Serial.println("kikikikikikikiki");
  digitalWrite(transferMechanism::rackDir, LOW);
  analogWrite(transferMechanism::rackPwm, 100);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void transferMechanism::backward()                                                                         //This function will tell the rack to move backward
{
  Serial.println("hihihihihihi");
  analogWrite(transferMechanism::rackDir, 255);
  analogWrite(transferMechanism::rackPwm, 100);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void transferMechanism::halt()
{
  digitalWrite(transferMechanism::rackDir, LOW);
  analogWrite(transferMechanism::rackPwm, 0);
  Serial.flush();
  myservo.write(90);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void transferMechanism::extend()
{
  digitalWrite(transferMechanism::pneumaticPin1, LOW);
  digitalWrite(transferMechanism::pneumaticPin2, HIGH);
  delay(1000);
  digitalWrite(transferMechanism::pneumaticPin1, LOW);
  digitalWrite(transferMechanism::pneumaticPin2, LOW);
  transferMechanism::extenderstate = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void transferMechanism::contract()
{
  digitalWrite(transferMechanism::pneumaticPin1, HIGH);
  digitalWrite(transferMechanism::pneumaticPin2, LOW);
  delay(1000);
  digitalWrite(transferMechanism::pneumaticPin1, LOW);
  digitalWrite(transferMechanism::pneumaticPin2, LOW);
  transferMechanism::extenderstate = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////


void servomove()
{
  if (servoFlag == 0)
  {
    myservo.write(0);
    servoFlag = 1;
  }
  if (servoFlag == 1)
  {
    myservo.write(90);
    servoFlag = 0;
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void eextend()
{
  Serial.println("eextend");
  digitalWrite(underRackpin1, LOW);
  digitalWrite(underRackpin2, HIGH);
  delay(1000);
  digitalWrite(underRackpin1, LOW);
  digitalWrite(underRackpin2, LOW);
  rackFlag = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ccontract()
{
  Serial.println("Ccontract");
  digitalWrite(underRackpin1, HIGH);
  digitalWrite(underRackpin2, LOW);
  delay(1000);
  digitalWrite(underRackpin1, LOW);
  digitalWrite(underRackpin2, LOW);
  rackFlag = 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void transferMechanism::force_ground()
{
  digitalWrite(transferMechanism::pneumaticPin1, LOW);
  digitalWrite(transferMechanism::pneumaticPin2, LOW);
}

