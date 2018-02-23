byte motorPin11 = 32;                                                                   // Blue   - 28BYJ48 pin 1

byte motorPin12 = 34;                                                                   // Pink   - 28BYJ48 pin 2

byte motorPin13 = 36;                                                                  // Yellow - 28BYJ48 pin 3

byte motorPin14 = 40;                                                                  // Orange - 28BYJ48 pin 4

// Red    - 28BYJ48 pin 5 (VCC)
void backward1();

int rackFlag = 0, servoFlag = 0;

int underRackpin1 = 5, underRackpin2 = 52;

byte motorPin21 = 42;                                                                   // Blue   - 28BYJ48 pin 1

byte motorPin22 = 44;                                                                   // Pink   - 28BYJ48 pin 2

byte motorPin23 = 46;                                                                  // Yellow - 28BYJ48 pin 3

byte motorPin24 = 48;                                                                  // Orange - 28BYJ48 pin 4

// Red    - 28BYJ48 pin 5 (VCC)

byte motorPin31 = 16;                                                                   // Blue   - 28BYJ48 pin 1

byte motorPin32 = 17;                                                                   // Pink   - 28BYJ48 pin 2

byte motorPin33 = 18;                                                                  // Yellow - 28BYJ48 pin 3

byte motorPin34 = 19;                                                                  // Orange - 28BYJ48 pin 4

// Red    - 28BYJ48 pin 5 (VCC



#define sensor1 A1                                                                     //Sharp IR connection on the arduino

#define sensor2 A2

#define sensor3 A5

int motorSpeed = 1200;                                                                //variable to set stepper speed

int count1 = 0;                                                                        // count of steps made

int count2 = 0;

int count3 = 0;

int countsperrev1 = 512;                                                               // number of steps per full revolution

int countsperrev2 = 512;

int countsperrev3 = 512;



int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

byte buttonPin1 = 4;                                                                   //Pin to which the button is connected

byte buttonPin2 = 3;

byte buttonPin3 = 44;

byte pwm1 = 11;                                                                        //PWM1 pin of cytron for the rack motor

byte pwm2 = 13;

byte pwm3 = 6;

byte dir1 = 10;                                                                       //dir0 pin of the cytron for the rack motor

byte dir2 = 12;

byte dir3 = A2;

int button1;                                                                           //Variable to store the digital state value of the button

int button2;

int button3;

void setOutput1(int );                                                                 //Used to control the motion of the stepper for the rack mechanism

void setOutput2(int );

void setOutput3(int );

int flag1 = 1;                                                                         //Used to store the current position where the assembly is currentl

int flag2 = 1;

int flag3 = 1;

//int rack1();

//int rack2();

//int rack3();

int step_count1 = 0;                                                                  //Stores the value of the position where the previous lock was made so the ball can be dropped and new step_count can be set thereafter

int step_count2 = 0;

int step_count3 = 0;

int success1 = 0;

int success2 = 0;

int success3 = 0;

int r1 = 5;

int r2 = 5;

int r3 = 5;

void clockwise1();
void anticlockwise1();
void forward1();
void backward1();
void halt1();
void eextend();
void ccontract();
void stepper_1_close();
void stepper_1_open();
//////////////////////////////////////////////////////////////////////////////

void setup() {

  pinMode(motorPin11, OUTPUT);

  pinMode(motorPin12, OUTPUT);

  pinMode(motorPin13, OUTPUT);

  pinMode(motorPin14, OUTPUT);

  pinMode(sensor1, INPUT);

  pinMode(pwm1, OUTPUT);

  pinMode(dir1, OUTPUT);

  analogWrite(pwm1, 0);

  pinMode(buttonPin1, OUTPUT);

  pinMode(motorPin21, OUTPUT);

  pinMode(motorPin22, OUTPUT);

  pinMode(motorPin23, OUTPUT);

  pinMode(motorPin24, OUTPUT);

  pinMode(sensor2, INPUT);

  pinMode(pwm2, OUTPUT);

  pinMode(dir2, OUTPUT);

  analogWrite(pwm2, 0);

  pinMode(buttonPin2, INPUT);

  pinMode(motorPin31, OUTPUT);

  pinMode(motorPin32, OUTPUT);

  pinMode(motorPin33, OUTPUT);

  pinMode(motorPin34, OUTPUT);

  pinMode(sensor3, INPUT);

  pinMode(pwm3, OUTPUT);

  pinMode(dir3, OUTPUT);

  analogWrite(pwm3, 0);

  pinMode(buttonPin3, INPUT);
  pinMode(underRackpin1, OUTPUT);
  pinMode(underRackpin2, OUTPUT);
  analogWrite(buttonPin1,0);
  Serial.begin(9600);

}

//////////////////////////////////////////////////////////////////////////////

void loop()

{

  char input = 0;

  if (Serial.available())

  {

    input = Serial.read();
    Serial.println(input);
  }

  switch (input)

  {

    case 'A':
      forward1();
      delay(200);
      halt1();
      Serial.println("Forward");
      break;
    case 'B':
      backward1();
      delay(200);
      halt1();
      Serial.println("Reverse");
      break;
    case 'C':
      stepper_1_close();
      delay(100);
      Serial.println("Stepper close");
      break;
    case 'D':
      stepper_1_open();
      delay(100);
      Serial.println("Stepper Open");
      break;

    case 'E':
      forward2();
      delay(200);
      halt2();
      Serial.println("Forward");
      break;
    case 'F':
      backward2();
      delay(200);
      halt2();
      Serial.println("Reverse");
      break;
    case 'G':
      stepper_2_close();
      delay(100);
      Serial.println("Stepper close");
      break;
    case 'H':
      stepper_2_open();
      delay(100);
      Serial.println("Stepper Open");
      break;

    case 'R':

      rack1();

      delay(9000);

      break;

    case 'I':

      rack2();

      delay(9000);

      break;

    case 'L':

      rack3();

      delay(9000);

      break;

    case 'K':
      if (rackFlag == 0)
        eextend();
      else if (rackFlag == 1)
        ccontract();
      break;
      input = 0;

  }

}

//////////////////////////////////////////////////////////////////////////////


void rack1() {

  Serial.println("Rack 2 is now operating folks!");

  success1 = 0;

  r1 = r1 - 1;

  while (success1 == 0) {

    button1 = digitalRead(buttonPin1);

    Serial.println("Button:");

    Serial.print(digitalRead(buttonPin1));

    float volts = analogRead(sensor1) * 0.0048828125; // value from sensor * (5/1024)

    int distance = 13 * pow(volts, -1); // worked out from datasheet graph

    if (button1 == 0)

    {

      forward1();

    }

    else if (button1 == 1) {

      Serial.println("Button Hitted");

      step_count1 = flag1;

      flag1 = 0;

      for ( ; ; ) {

        if ( count1 == 128 ) {

          break ;

        }

        clockwise1();

        count1++ ;

      }

      backward1();

      while (flag1 != step_count1 + 1) {

        Serial.println("Loop Execution Started");

        float volts = analogRead(sensor1) * 0.0048828125; // value from sensor * (5/1024)

        int distance = 13 * pow(volts, -1); // worked out from datasheet graph

        Serial.println("Distance is:");

        Serial.print(distance);

        while ((distance >= 4) && (distance < 10)) {

          Serial.println("Distance has Reduced now");

          float volts = analogRead(sensor1) * 0.0048828125; // value from sensor * (5/1024)

          int distance = 13 * pow(volts, -1); // worked out from datasheet graph

          if (distance > 10) {

            Serial.println("Hand Removed");

            flag1 += 1;

            Serial.println("The position value now is:");

            Serial.print(flag1);

            break;

          }

        }



        Serial.println("Loop Executed");

        delay(200);

      }

      success1 = 1;

      halt1();

      Serial.println("Loop Execution finished");

      return;

    }

  }

}





void rack2() {
  Serial.println("Rack 2 is now operating folks!");
  success2 = 0;
  r2 = r2 - 1;
  while (success2 == 0) {
    button2 = digitalRead(buttonPin2);
    Serial.println("Button:");
    Serial.print(digitalRead(buttonPin2));
    float volts = analogRead(sensor2) * 0.0048828125; // value from sensor * (5/1024)
    int distance = 13 * pow(volts, -1); // worked out from datasheet graph
    if (button2 == 1)
    {
      forward2();
    }
    else if (button2 == 1) {
      Serial.println("Button Hitted");
      step_count2 = flag2;
      flag2 = 0;
      for ( ; ; ) {
        if ( count2 == 128 ) {
          break ;
        }
        clockwise2();
        count2++ ;
      }
      backward2();
      while (flag2 != step_count2 + 1) {
        Serial.println("Loop Execution Started");
        float volts = analogRead(sensor2) * 0.0048828125; // value from sensor * (5/1024)
        int distance = 13 * pow(volts, -1); // worked out from datasheet graph
        Serial.println("Distance is:");
        Serial.print(distance);
        while ((distance >= 4) && (distance < 10)) {
          Serial.println("Distance has Reduced now");
          float volts = analogRead(sensor2) * 0.0048828125; // value from sensor * (5/1024)
          int distance = 13 * pow(volts, -1); // worked out from datasheet graph
          if (distance > 10) {
            Serial.println("Hand Removed");
            flag2 += 1;
            Serial.println("The position value now is:");
            Serial.print(flag2);
            break;
          }
        }
        Serial.println("Loop Executed");

        delay(200);

      }
      success2 = 1;
      halt2();
      Serial.println("Loop Execution finished");
      return;
    }
  }
}

void rack3() {

  Serial.println("Rack 3 is now operating folks!");

  success3 = 0;

  r3 = r3 - 1;

  while (success3 == 0) {

    button3 = digitalRead(buttonPin3);

    Serial.println("Button:");

    Serial.print(digitalRead(buttonPin3));

    float volts = analogRead(sensor3) * 0.0048828125; // value from sensor * (5/1024)

    int distance = 13 * pow(volts, -1); // worked out from datasheet graph

    if (button3 == 1)

    {

      forward3();

    }

    else if (button3 == 0) {

      Serial.println("Button Hitted");

      step_count3 = flag3;

      flag3 = 0;

      for ( ; ; ) {

        if ( count3 == 128 ) {

          break ;

        }

        clockwise3();

        count3++ ;

      }

      backward3();
      while (flag3 != step_count3 + 1) {
        Serial.println("Loop Execution Started");
        float volts = analogRead(sensor3) * 0.0048828125; // value from sensor * (5/1024)
        int distance = 13 * pow(volts, -1); // worked out from datasheet graph
        Serial.println("Distance is:");
        Serial.print(distance);
        while ((distance >= 4) && (distance < 10)) {
          Serial.println("Distance has Reduced now");
          float volts = analogRead(sensor3) * 0.0048828125; // value from sensor * (5/1024)
          int distance = 13 * pow(volts, -1); // worked out from datasheet graph
          if (distance > 10) {
            Serial.println("Hand Removed");
            flag3 += 1;
            Serial.println("The position value now is:");
            Serial.print(flag3);
            break;
          }
        }
        Serial.println("Loop Executed");
        delay(200);
      }
      for ( ; ; ) {
        if ( count3 == 256 ) {
          break ;
        }
        anticlockwise3();
        count3++;
        //Serial.print("Count:");
        //Serial.println(count);
      }
      count3 = 0 ;
      success3 = 1;

      halt3();

      Serial.println("Loop Execution finished");

      return;

    }

  }

}



////////////////////////////////////////////////////////////////////////////////////////////////

void anticlockwise1()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after

{

  for (int i = 0; i < 8; i++)

  {

    setOutput1(i);

    delayMicroseconds(motorSpeed);

  }

}

void anticlockwise2()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after

{

  for (int i = 0; i < 8; i++)

  {

    setOutput2(i);

    delayMicroseconds(motorSpeed);

  }

}

void anticlockwise3()                                                                   //This function will give the closing of the flap to lock the flap for throwing the next ball there after

{

  for (int i = 0; i < 8; i++)

  {

    setOutput3(i);

    delayMicroseconds(motorSpeed);

  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void clockwise1()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking

{

  for (int i = 8; i > 0; i--)

  {

    setOutput1(i);

    delayMicroseconds(motorSpeed);

  }

}

void clockwise2()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking

{

  for (int i = 8; i > 0; i--)

  {

    setOutput2(i);

    delayMicroseconds(motorSpeed);

  }

}

void clockwise3()                                                                        //This Function will open up the flap when the ball is dropped and we start moving backward for the next bal locking

{

  for (int i = 8; i > 0; i--)

  {

    setOutput3(i);

    delayMicroseconds(motorSpeed);

  }

}

//////////////////////////////////////////////////////////////////////////////////////////////////

void backward1()                                                                         //This function will tell the rack to move backward

{

  digitalWrite(dir1, LOW);

  analogWrite(pwm1, 200);

}

void backward2()                                                                         //This function will tell the rack to move backward

{

  digitalWrite(dir2, LOW);

  analogWrite(pwm2, 200);

}

void backward3()                                                                         //This function will tell the rack to move backward

{

  digitalWrite(dir3, LOW);

  analogWrite(pwm3, 200);

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void forward1()                                                                           //This Function will tell the rack to move forward

{

  digitalWrite(dir1, HIGH);

  analogWrite(pwm1, 200);

}

void forward2()                                                                           //This Function will tell the rack to move forward

{

  digitalWrite(dir2, HIGH);

  analogWrite(pwm2, 200);

}

void forward3()                                                                           //This Function will tell the rack to move forward

{

  digitalWrite(dir3, HIGH);

  analogWrite(pwm3, 200);

}

///////////////////////////////////////////////////////////////////////////////////////////////////

void halt1()

{

  digitalWrite(dir1, LOW);

  analogWrite(pwm1, 0);

}

void halt2()

{

  digitalWrite(dir2, LOW);

  analogWrite(pwm2, 0);

}

void halt3()

{

  digitalWrite(dir3, LOW);

  analogWrite(pwm3, 0);

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


void eextend()
{
  Serial.println("eextend");
  digitalWrite(5, LOW);
  digitalWrite(52, HIGH);
  delay(1000);
  digitalWrite(5, LOW);
  digitalWrite(52, LOW);
  rackFlag = 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void ccontract()
{
  Serial.println("Ccontract");
  digitalWrite(5, HIGH);
  digitalWrite(52, LOW);
  delay(1000);
  digitalWrite(5, LOW);
  digitalWrite(52, LOW);
  rackFlag = 0;
}
void stepper_1_open()
{
  analogWrite(buttonPin1,168);
  count1=0;
  for ( ; ; ) {

    if ( count1 == 50 ) {

      break ;

    }

    clockwise1();

    count1++ ;

  }
  analogWrite(buttonPin1,0);
}
void stepper_1_close()
{
  analogWrite(buttonPin1,168);
   for ( ; ; ) {
    if ( count1 == 100 ) {
      break ;
    }
    anticlockwise1();
    count1++;
    //Serial.print("Count:");
    //Serial.println(count);
  }
  count1 = 0 ;
  analogWrite(buttonPin1,0);
}
void stepper_2_open()
{
  analogWrite(buttonPin1,168);
  count2=0;
  for ( ; ; ) {

    if ( count2 == 50 ) {

      break ;

    }

    clockwise2();

    count2++ ;

  }
  analogWrite(buttonPin1,0);
}
void stepper_2_close()
{
  analogWrite(buttonPin1,168);
  for ( ; ; ) {
    if ( count2 == 100 ) {
      break ;
    }
    anticlockwise2();
    count2++;
    //Serial.print("Count:");
    //Serial.println(count);
  }
  count2 = 0 ;
  analogWrite(buttonPin1,0);
}
