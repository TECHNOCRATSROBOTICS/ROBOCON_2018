
byte motorPin11 = 22;                                                                   // Blue   - 28BYJ48 pin 1
byte motorPin12 = 24;                                                                   // Pink   - 28BYJ48 pin 2
byte motorPin13 = 26;                                                                  // Yellow - 28BYJ48 pin 3
byte motorPin14 = 28;                                                                  // Orange - 28BYJ48 pin 4
                                                                                      // Red    - 28BYJ48 pin 5 (VCC)
byte motorPin21 = 32;                                                                   // Blue   - 28BYJ48 pin 1
byte motorPin22 = 34;                                                                   // Pink   - 28BYJ48 pin 2
byte motorPin23 = 36;                                                                  // Yellow - 28BYJ48 pin 3
byte motorPin24 = 40;                                                                  // Orange - 28BYJ48 pin 4
                                                                                      // Red    - 28BYJ48 pin 5 (VCC)
byte motorPin31 = 42;                                                                   // Blue   - 28BYJ48 pin 1
byte motorPin32 = 44;                                                                   // Pink   - 28BYJ48 pin 2
byte motorPin33 = 46;                                                                  // Yellow - 28BYJ48 pin 3
byte motorPin34 = 48;                                                                  // Orange - 28BYJ48 pin 4
                                                                                      // Red    - 28BYJ48 pin 5 (VCC

#define sensor1 A0                                                                    //Sharp IR connection on the arduino
#define sensor2 A1
#define sensor3 A2
int motorSpeed = 1200;                                                                //variable to set stepper speed
int count1 = 0;                                                                        // count of steps made
int count2 = 0;
int count3 = 0;
int countsperrev1 =512;                                                                // number of steps per full revolution
int countsperrev2 =512;
int countsperrev3 =512; 

int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
byte buttonPin1=50;                                                                     //Pin to which the button is connected
byte buttonPin2=3;
byte buttonPin3=4;
byte pwm1=11;                                                                          //PWM1 pin of cytron for the rack motor
byte pwm2=13;
byte pwm3=5;
byte dir1=10;                                                                         //dir0 pin of the cytron for the rack motor
byte dir2=12;
byte dir3=52;
int button1;                                                                           //Variable to store the digital state value of the button
int button2;
int button3;
void setOutput1(int );                                                                 //Used to control the motion of the stepper for the rack mechanism
void setOutput2(int );
void setOutput3(int );
int flag1=1;                                                                           //Used to store the current position where the assembly is currentl
int flag2=1;
int flag3=1;

int step_count1=0;                                                                    //Stores the value of the position where the previous lock was made so the ball can be dropped and new step_count can be set thereafter
int step_count2=0;
int step_count3=0;
int success1=0;
int success2=0;
int success3=0;
int r1=5;
int r2=5;
int r3=5;
int extenderpin1=23;
int extenderpin2=25;
int rackpullpin1=27;
int rackpullpin2=29;
char stroke_state;
//////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(motorPin11, OUTPUT);
  pinMode(motorPin12, OUTPUT);
  pinMode(motorPin13, OUTPUT);
  pinMode(motorPin14, OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir1,OUTPUT);
  analogWrite(pwm1,0);
  pinMode(buttonPin1,INPUT);
  pinMode(motorPin21, OUTPUT);
  pinMode(motorPin22, OUTPUT);
  pinMode(motorPin23, OUTPUT);
  pinMode(motorPin24, OUTPUT);
  pinMode(sensor2,INPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir2,OUTPUT);
  analogWrite(pwm2,0);
  pinMode(buttonPin2,INPUT);
  pinMode(motorPin31, OUTPUT);
  pinMode(motorPin32, OUTPUT);
  pinMode(motorPin33, OUTPUT);
  pinMode(motorPin34, OUTPUT);
  pinMode(sensor3,INPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(dir3,OUTPUT);
  analogWrite(pwm3,0);
  pinMode(buttonPin3,INPUT);
  pinMode(extenderpin1,OUTPUT);
  pinMode(extenderpin2,OUTPUT);
  digitalWrite(extenderpin1,HIGH);
  digitalWrite(extenderpin2,HIGH);
  pinMode(rackpullpin1,OUTPUT);
  pinMode(rackpullpin2,OUTPUT);
  digitalWrite(rackpullpin1,HIGH);
  digitalWrite(rackpullpin2,HIGH);
  Serial.begin(9600);
}
//////////////////////////////////////////////////////////////////////////////
void loop()
{
  char input = 0;
  if(Serial.available())
  {
    input = Serial.read();
  }
  switch (input)
  {
    case 'a':
      rack1();
      delay(9000);
      break;
    case 'l':
      setPneumatic(extenderpin1,extenderpin2);
      break;
    case 'r':
      clearPneumatic(extenderpin1,extenderpin2);
      break;
    case 'i':
      setPneumatic(rackpullpin1,rackpullpin2);
      break;
    case 'o':
      setPneumatic(rackpullpin1,rackpullpin2);
      break;
    case 'b':
      rack2();
      delay(9000);
      break;
    case 'c':
      rack3();
      delay(9000);
      break;
    case 'k':
        if(r1>0){
          rack1();
          }
          else{
           rack2();
          }
          
      break;
  }
  input= 0;
}

//////////////////////////////////////////////////////////////////////////////
void rack1(){
  Serial.println("Rack 1 is now operating folks!");
  success1=0;
  r1=r1-1;
  while(success1==0){
  button1 = digitalRead(buttonPin1);
  Serial.println("Button:");
  Serial.print(digitalRead(buttonPin1));
  float volts = analogRead(sensor1)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  if(button1==0)
  {
    forward1();
  }
  else if (button1==1){
    Serial.println("Button Hitted");
    step_count1=flag1;
   flag1=0;
    for( ; ; ){
    if( count1 == 128 ){    
      break ;
    }    
  clockwise1();
  count1++ ;
    }
     backward1();
    while(flag1!=step_count1+1){
    Serial.println("Loop Execution Started");
   float volts = analogRead(sensor1)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.println("Distance is:");
  Serial.print(distance);
    while((distance>=4)&&(distance<10)){
      Serial.println("Distance has Reduced now");
      float volts = analogRead(sensor1)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
      if(distance>10){
        Serial.println("Hand Removed");
        flag1+=1;
        Serial.println("The position value now is:");
        Serial.print(flag1);
        break;
       }
     }
     
      Serial.println("Loop Executed");
      delay(200);
 }
    for( ; ; ){
    if( count1 == 256 ){
    break ;
    }
  anticlockwise1();
  count1++;  
  //Serial.print("Count:");
  //Serial.println(count);
 }
 count1 = 0 ;
 success1=1;
 halt1();
 Serial.println("Loop Execution finished");
 return;
  }
  }
}

void rack2(){
  Serial.println("Rack 2 is now operating folks!");
  success2=0;
  r2=r2-1;
  while(success2==0){
  button2 = digitalRead(buttonPin2);
  Serial.println("Button:");
  Serial.print(digitalRead(buttonPin2));
  float volts = analogRead(sensor2)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  if(button2==0)
  {
    forward2();
  }
  else if (button2==1){
    Serial.println("Button Hitted");
    step_count2=flag2;
   flag2=0;
    for( ; ; ){
    if( count2 == 128 ){    
      break ;
    }    
  clockwise2();
  count2++ ;
    }
     backward2();
    while(flag2!=step_count2+1){
    Serial.println("Loop Execution Started");
   float volts = analogRead(sensor2)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.println("Distance is:");
  Serial.print(distance);
    while((distance>=4)&&(distance<10)){
      Serial.println("Distance has Reduced now");
      float volts = analogRead(sensor2)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
      if(distance>10){
        Serial.println("Hand Removed");
        flag2+=1;
        Serial.println("The position value now is:");
        Serial.print(flag2);
        break;
       }
     }
     
      Serial.println("Loop Executed");
      delay(200);
 }
    for( ; ; ){
    if( count2 == 256 ){
    break ;
    }
  anticlockwise2();
  count2++;  
  //Serial.print("Count:");
  //Serial.println(count);
 }
 count2 = 0 ;
 success2=1;
 halt2();
 Serial.println("Loop Execution finished");
 return;
  }
  }
}
void rack3(){
  Serial.println("Rack 3 is now operating folks!");
  success3=0;
  r3=r3-1;
  while(success3==0){
  button3 = digitalRead(buttonPin3);
  Serial.println("Button:");
  Serial.print(digitalRead(buttonPin3));
  float volts = analogRead(sensor3)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  if(button3==0)
  {
    forward3();
  }
  else if (button3==1){
    Serial.println("Button Hitted");
    step_count3=flag3;
   flag3=0;
    for( ; ; ){
    if( count3 == 128 ){    
      break ;
    }    
  clockwise3();
  count3++ ;
    }
     backward3();
    while(flag3!=step_count3+1){
    Serial.println("Loop Execution Started");
   float volts = analogRead(sensor3)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.println("Distance is:");
  Serial.print(distance);
    while((distance>=4)&&(distance<10)){
      Serial.println("Distance has Reduced now");
      float volts = analogRead(sensor3)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
      if(distance>10){
        Serial.println("Hand Removed");
        flag3+=1;
        Serial.println("The position value now is:");
        Serial.print(flag3);
        break;
       }
     }
     
      Serial.println("Loop Executed");
      delay(200);
 }
    for( ; ; ){
    if( count3 == 256 ){
    break ;
    }
  anticlockwise3();
  count3++;  
  //Serial.print("Count:");
  //Serial.println(count);
 }
 count3 = 0 ;
 success3=1;
 halt3();
 Serial.println("Loop Execution finished");
 return;
  }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////
void anticlockwise1()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after
{
  for(int i = 0; i < 8; i++)
  {
    setOutput1(i);
    delayMicroseconds(motorSpeed);
  }
}
void anticlockwise2()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after
{
  for(int i = 0; i < 8; i++)
  {
    setOutput2(i);
    delayMicroseconds(motorSpeed);
  }
}
void anticlockwise3()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after
{
  for(int i = 0; i < 8; i++)
  {
    setOutput3(i);
    delayMicroseconds(motorSpeed);
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void clockwise1()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking
{
  for(int i = 8; i > 0; i--)
  {
    setOutput1(i);
    delayMicroseconds(motorSpeed);
  }
}
void clockwise2()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking
{
  for(int i = 8; i > 0; i--)
  {
    setOutput2(i);
    delayMicroseconds(motorSpeed);
  }
}
void clockwise3()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking
{
  for(int i = 8; i > 0; i--)
  {
    setOutput3(i);
    delayMicroseconds(motorSpeed);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void backward1()                                                                         //This function will tell the rack to move backward
{
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,250);
}
void backward2()                                                                         //This function will tell the rack to move backward
{
  digitalWrite(dir2,LOW);
  analogWrite(pwm2,250);
}
void backward3()                                                                         //This function will tell the rack to move backward
{
  digitalWrite(dir3,LOW);
  analogWrite(pwm3,250);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void forward1()                                                                           //This Function will tell the rack to move forward
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,250);
}
void forward2()                                                                           //This Function will tell the rack to move forward
{
  digitalWrite(dir2,HIGH);
  analogWrite(pwm2,250);
}
void forward3()                                                                           //This Function will tell the rack to move forward
{
  digitalWrite(dir3,HIGH);
  analogWrite(pwm3,250);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void halt1()
{
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,0);  
}
void halt2()
{
  digitalWrite(dir2,LOW);
  analogWrite(pwm2,0);  
}
void halt3()
{
  digitalWrite(dir3,LOW);
  analogWrite(pwm3,0);  
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setOutput1(int out)                                                                  //Used for controlling the stepper motor 
{
  digitalWrite(motorPin11, bitRead(lookup[out], 0));
  digitalWrite(motorPin12, bitRead(lookup[out], 1));
  digitalWrite(motorPin13, bitRead(lookup[out], 2));
  digitalWrite(motorPin14, bitRead(lookup[out], 3));
}
void setOutput2(int out)                                                                  //Used for controlling the stepper motor 
{
  digitalWrite(motorPin21, bitRead(lookup[out], 0));
  digitalWrite(motorPin22, bitRead(lookup[out], 1));
  digitalWrite(motorPin23, bitRead(lookup[out], 2));
  digitalWrite(motorPin24, bitRead(lookup[out], 3));
}
void setOutput3(int out)                                                                  //Used for controlling the stepper motor 
{
  digitalWrite(motorPin31, bitRead(lookup[out], 0));
  digitalWrite(motorPin32, bitRead(lookup[out], 1));
  digitalWrite(motorPin33, bitRead(lookup[out], 2));
  digitalWrite(motorPin34, bitRead(lookup[out], 3));
}
void setPneumatic(int pin1,int pin2)
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  delay(1000);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  Serial.println("pin2 High");
}
void clearPneumatic(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  delay(1000);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  Serial.println("pin1 High");
}

