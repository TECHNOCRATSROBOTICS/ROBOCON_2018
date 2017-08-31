int out=8;

void setup() {
  pinMode(out,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //duration = pulseIn(echoPin, HIGH);
  Serial.println(out);
  delay(1000);
}
