const float Kp =0.3;  //0.48;   // Kp value that you have to change 0.45
const float Kd =30;//195;  // 20 ; //195
//kd=1;// Kd value that you have to change 150
const float setPoint = 35;    // Middle point of sensor array
const float baseSpeed = 200;    // Base speed for your motors
const float maxSpeed = 240;   // Maximum speed for your motors

const byte rx = 0;    // Defining pin 0 as Rx
const byte tx = 1;    // Defining pin 1 as Tx
const byte serialEn = 2;    // Connect UART output enable of LSA08 to pin 2
const byte junctionPulse = 3;   // Connect JPULSE of LSA08 to pin 4
const byte dir1 = 4;
const byte pwm1 = 5; // rf
const byte dir2 = 6;
const byte pwm2 = 9; // lf
const byte dir3 = 8;
const byte pwm3 = 10; // lb
const byte dir4 = 13;
const byte pwm4 = 11; // rb
void setup() {
  pinMode(serialEn,OUTPUT);   // Setting serialEn as digital output pin
  pinMode(junctionPulse,INPUT);   // Setting junctionPulse as digital input pin

  // Setting pin 10 - 13 as digital output pin
  for(byte i=4;i<=13;i++) {
    pinMode(i,OUTPUT);
  }

  // Setting initial condition of serialEn pin to HIGH
  digitalWrite(serialEn,HIGH);

  // Setting the initial condition of motors
  // make sure both PWM pins are LOW
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(pwm3,LOW);
  digitalWrite(pwm4,LOW);
  // State of DIR pins are depending on your physical connection
  // if your robot behaves strangely, try changing thses two values
  digitalWrite(dir1,LOW);  //LF
  digitalWrite(dir2,LOW);  //LB
  digitalWrite(dir3,HIGH); //RB
  digitalWrite(dir4,HIGH); //RF
  

  // Begin serial communication with baudrate 9600
  Serial.begin(9600);

}

float lastError = 0;    // Declare a variable to store previous error

void loop() {
  
  digitalWrite(serialEn,LOW);   // Set serialEN to LOW to request UART data
  while(Serial.available() <= 0);   // Wait for data to be available
  int positionVal = Serial.read();    // Read incoming data and store in variable positionVal
  digitalWrite(serialEn,HIGH);    // Stop requesting for UART data
  Serial.println(positionVal);

  // If no line is detected, stay at the position
  if(positionVal == 255) {
    analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    analogWrite(pwm3,0);
    analogWrite(pwm4,0);
  }

  // Else if line detected, calculate the motor speed and apply
  else {
    float error = positionVal - setPoint;   // Calculate the deviation from position to the set point
    float motorSpeed = Kp * error + Kd * (error - lastError);   // Applying formula of PID
    lastError = error;    // Store current error as previous error for next iteration use

    // Adjust the motor speed based on calculated value
    // You might need to interchange the + and - sign if your robot move in opposite direction
    float leftMotorSpeed = baseSpeed + motorSpeed;
    float rightMotorSpeed = baseSpeed - motorSpeed;

    // If the speed of motor exceed max speed, set the speed to max speed
    if(rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;
    if(leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;

    // If the speed of motor is negative, set it to 0
    if(rightMotorSpeed < 0) rightMotorSpeed = 0;
    if(leftMotorSpeed < 0) leftMotorSpeed = 0;
  Serial.print(rightMotorSpeed);
  Serial.print(" ");
  Serial.println(leftMotorSpeed);
    // Writing the motor speed value as output to hardware motor
    analogWrite(pwm1,leftMotorSpeed);
    analogWrite(pwm4,rightMotorSpeed);
    analogWrite(pwm3,rightMotorSpeed);
    analogWrite(pwm2,leftMotorSpeed);
  }   
  

}
