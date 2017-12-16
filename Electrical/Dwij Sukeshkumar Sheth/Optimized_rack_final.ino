byte motorPin1 = 8;                                                                   // Blue   - 28BYJ48 pin 1
byte motorPin2 = 9;                                                                   // Pink   - 28BYJ48 pin 2
byte motorPin3 = 10;                                                                  // Yellow - 28BYJ48 pin 3
byte motorPin4 = 11;                                                                  // Orange - 28BYJ48 pin 4
                                                                                      // Red    - 28BYJ48 pin 5 (VCC)
#define sensor A3                                                                     //Sharp IR connection on the arduino
int motorSpeed = 1200;                                                                //variable to set stepper speed
int count = 0;                                                                        // count of steps made
int countsperrev =512;                                                                // number of steps per full revolution
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};
byte buttonPin=6;                                                                     //Pin to which the button is connected
byte pwm1=7;                                                                          //PWM1 pin of cytron for the rack motor
byte dir1=A0;                                                                         //dir0 pin of the cytron for the rack motor
int button;                                                                           //Variable to store the digital state value of the button
void setOutput(int );                                                                 //Used to control the motion of the stepper for the rack mechanism
int flag=1;                                                                           //Used to store the current position where the assembly is currently
int step_count=0;                                                                     //Stores the value of the position where the previous lock was made so the ball can be dropped and new step_count can be set thereafter
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
  Serial.begin(9600);
}

//////////////////////////////////////////////////////////////////////////////
void loop(){
  button = digitalRead(buttonPin);                                                    //Stores the Value of the current state of the button
  if(button==1){                                                                      //Button==1 means the button is not pressed
    forward();
  }
  else if (button==0){                                                                //Button==0 Means the button is pressed
              step_count=flag;                                                        //step_count is storing the position from which the ball was taken
              flag=0;                                                                 //Now we set flag valus to zero to count the number of barriers it will pass during the reverse motion
              for( ; ; )
              {                                                                       //This for loop is for moving the flap up once the ball is handed over to the transfer mechanism
                if( count == 128 ){
                  break ;
                }
              clockwise();
              count++ ;                                                                //This count value is of the stepper motor count value
              }
              backward();                                                              //Backward function is called to tell the Rack mechanism to reverse its direction of motion now
          while(flag!=step_count+1){                                                   //Now We are checking the number of barriers passed through before stopping and locking the flap for the next call
              float volts = analogRead(sensor)*0.0048828125;                           //Now we are reading the sharp ir value from the SHARP IR Sensor=>value from sensor * (5/1024)
              int distance = 13*pow(volts, -1);                                        //This will use the voltage value so got from the analog pin to convert it into the distance  =>  worked out from datasheet graph
              while((distance>=4)&&(distance<10))
              {                                                                        //Now the  Comparison for the distance starts to detect the barrier
                  float volts = analogRead(sensor)*0.0048828125;                       //This line is declared here again so that we can get the instantaneous values
                  int distance = 13*pow(volts, -1);
                  if(distance>10)
                  {                                                                    //This condition checks that the barrier has been past and now we can say that one barrier has been successfully passed and we can increment the counter by 1
                      flag+=1;
                      break;
                  }
              }
                  delay(200);
         }
          for( ; ; ){                                                                  //This for loop will now move the stepper in order to lock the flap for the next ball push
              if( count == 256 )
              {
              break ;
              }
            anticlockwise();
            count++;
         }
         count = 0 ;                                                                   //Resetting the stepper motor count for the next rotation
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////
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
  digitalWrite(dir1,LOW);
  analogWrite(pwm1,200);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void forward()                                                                           //This Function will tell the rack to move forward
{
  digitalWrite(dir1,HIGH);
  analogWrite(pwm1,200);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
void setOutput(int out)                                                                  //Used for controlling the stepper motor 
{
  digitalWrite(motorPin1, bitRead(lookup[out], 0));
  digitalWrite(motorPin2, bitRead(lookup[out], 1));
  digitalWrite(motorPin3, bitRead(lookup[out], 2));
  digitalWrite(motorPin4, bitRead(lookup[out], 3));
}
