int pin1=5;
int pin2=6;
char stroke_state;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available())
  {
    Serial.println("Connection Established");
  stroke_state=Serial.read();
  Serial.println(stroke_state);
  // put your main code here, to run repeatedly:
if(stroke_state=='r')
{
digitalWrite(pin1,LOW);
digitalWrite(pin2,HIGH);
delay(1000);
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
Serial.println("pin2 High");
}
else if(stroke_state=='l')
{
digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);
delay(1000);
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
Serial.println("pin1 LOW");
}
/*digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
delay(1000);
digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);*/
  }


}
