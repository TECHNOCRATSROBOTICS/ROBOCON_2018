

const int motorPin1  = 2;  
const int motorPin2  = 3;  



void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    
    
    
  
}
void loop()
{
  

    //This code  will turn Motor A clockwise for 2 sec.
    analogWrite(motorPin1, 120);
    analogWrite(motorPin2, 0);
    
    delay(2000);
    
    analogWrite(motorPin1,0);
    analogWrite(motorPin2,0);
    delay(1000);
     
    //This code will turn Motor A counter-clockwise for 2 sec.
   analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 120);
    delay(2000);
    
    analogWrite(motorPin1,0);
    analogWrite(motorPin2,0);
  delay(1000); 
  
  
  }



