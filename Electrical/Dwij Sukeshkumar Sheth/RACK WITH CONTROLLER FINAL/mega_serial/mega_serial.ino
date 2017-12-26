byte motorPin1 = 22;                                                                   // Blue   - 28BYJ48 pin 1
byte motorPin2 = 23;                                                                   // Pink   - 28BYJ48 pin 2
byte motorPin3 = 24;                                                                  // Yellow - 28BYJ48 pin 3
byte motorPin4 = 25;                                                                  // Orange - 28BYJ48 pin 4
                                                                                      // Red    - 28BYJ48 pin 5 (VCC)
#define sensor A3                                                                     //Sharp IR connection on the arduino
int motorSpeed = 1200;                                                                //variable to set stepper speed
int count = 0;                                                                        // count of steps made
int countsperrev =512;                                                                // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
byte buttonPin=2;                                                                     //Pin to which the button is connected
byte pwm1=7;                                                                          //PWM1 pin of cytron for the rack motor
byte dir1=6;                                                                         //dir0 pin of the cytron for the rack motor
int button;                                                                           //Variable to store the digital state value of the button
void setOutput(int );                                                                 //Used to control the motion of the stepper for the rack mechanism
int flag=1;                                                                           //Stores the value of the position where the previous lock was made so the ball can be dropped and new step_count can be set thereafter
int buttonState;
int success=0;
int step_count=0;
int x=0;    // does nothing
int pneumaticpin1=5;
int pneumaticpin2=6;
byte rackstate=0;
//////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir1,OUTPUT);
  analogWrite(pwm1,0);
  pinMode(buttonPin,INPUT);
  buttonState=0;
  pinMode(pneumaticpin1,OUTPUT);
  pinMode(pneumaticpin2,OUTPUT);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
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
    case 'L':
      if(rackstate==0){
          liftup();
        }
      else if(rackstate==1){
          pushdown();
        }
    case 'R':
      rack1();
      }
  input= 0;
}

//////////////////////////////////////////////////////////////////////////////
void rack1(){
  success=0;
 // button=1;
  while(success==0){
  button = digitalRead(buttonPin);
  Serial.println("Button:");
  Serial.print(digitalRead(buttonPin));
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  if(button==0)
  {
    forward();
  }
  else if (button==1){
    Serial.println("Button Hitted");
    step_count=flag;
   flag=0;
    for( ; ; ){
    if( count == 128 ){    
      break ;
    }    
  clockwise();
  count++ ;
    }
     backward();
    while(flag!=step_count+1){
    Serial.println("Loop Execution Started");
   float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.println("Distance is:");
  Serial.print(distance);
    while((distance>=4)&&(distance<10)){
      Serial.println("Distance has Reduced now");
      float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  int distance = 13*pow(volts, -1); // worked out from datasheet graph
      if(distance>10){
        Serial.println("Hand Removed");
        flag+=1;
        Serial.println("The position value now is:");
        Serial.print(flag);
        break;
       }
     }
     
      Serial.println("Loop Executed");
      delay(200);
 }
    for( ; ; ){
    if( count == 256 ){
    break ;
    }
  anticlockwise();
  count++;  
  //Serial.print("Count:");
  //Serial.println(count);
 }
 count = 0 ;
 success=1;
 halt();
 Serial.println("Loop Execution finished");
 return;
  }
  }
}


////////////////////////////////////////////////////////////////////////////////////////////////
void liftup()
{
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,HIGH);
  delay(1000);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
  Serial.println("pneumaticpin2 High");
  rackstate=1;
  Serial.flush();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void pushdown()
{
  digitalWrite(pneumaticpin1,HIGH);
  digitalWrite(pneumaticpin2,LOW);
  delay(1000);
  digitalWrite(pneumaticpin1,LOW);
  digitalWrite(pneumaticpin2,LOW);
  Serial.println("pneumaticpin1 LOW");
  rackstate=0;
  Serial.flush();
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void anticlockwise()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after
{
  for(int i = 0; i < 8; i++)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void clockwise()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking
{
  for(int i = 8; i > 0; i--)
  {
    setOutput(i);
    delayMicroseconds(motorSpeed);
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////
void backward()                                                                         //This function will tell the rack to move backward
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,250);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void forward()                                                                           //This Function will tell the rack to move forward
{                                                            //Used to store the current position where the assembly is currently
int step_count=0;         
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,250);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void halt()
{
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,0);  
  Serial.flush();
}
void setOutput(int out)                                                                  //Used for controlling the stepper motor 
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
