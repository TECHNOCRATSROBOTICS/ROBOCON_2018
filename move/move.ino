const byte dir1 = 4;
const byte pwm1 = 5;
const byte dir2 = 6;
const byte pwm2 = 9;
const byte dir3 = 8;
const byte pwm3 = 10;
const byte dir4 = 13;
const byte pwm4 = 11;
char a;
void setup() {
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(pwm3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(pwm4,OUTPUT);
  digitalWrite(pwm1,LOW);
  digitalWrite(pwm2,LOW);
  digitalWrite(pwm3,LOW);
  digitalWrite(pwm4,LOW);
//  digitalWrite(dir1,HIGH);//RF
//  digitalWrite(dir2,LOW);//LF
//  digitalWrite(dir3,LOW);//LB
//  digitalWrite(dir4,HIGH);//RB
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    analogWrite(pwm1,255);
    analogWrite(pwm2,255);
    analogWrite(pwm3,255);
    analogWrite(pwm4,255);
    digitalWrite(dir1,LOW);//RF
    digitalWrite(dir2,LOW);//LF
    digitalWrite(dir3,LOW);//LB
    digitalWrite(dir4,LOW);//RB
    delay(385);
    while(true)
    {
      analogWrite(pwm1,0);
    analogWrite(pwm2,0);
    analogWrite(pwm3,0);
    analogWrite(pwm4,0);
    }
    }

