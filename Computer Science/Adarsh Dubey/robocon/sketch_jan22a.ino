#include<SPI.h>
#include<Pixy.h>

//variables and functions for zone 3
int trigPin=9,echoPin=10; // trig to pin 9 and echo to pin 10
float tme(int pulse); // returns time taken by sound to reach the ball
bool Tz3(float t); // returns true if ball on the arm for Tz3
float dist;// how far the ball is, used to run the counter
float minDist,maxDist;//distance range acceptable to assume that ball for Tz3 has been transfered 


//variables and functions for pixy
bool Tz1=false;//if true go for throwing zone 1
bool Tz2=false;//if true go for throwing zone 2
int signGreen = 1;//give signature 1 in pixy to green ball
int signMagenta = 2;//give signature 2 in the pixy to magenta ball 
uint16_t blocks;
Pixy pixy;
bool isMagenta=false; //becomes true when magenta is recieved


//variables and functions for zone selection and transfer
int lsbPin = 6;//pin to communicate least significant bit
int msbPin = 7;//pin to communicate most significant bit
int Zone(); // function to decide which zone to go to
void Send(int n);//sends which zone is selected to the line following arduino


void setup()
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(lsbPin,OUTPUT);
  pinMode(lsbPin,OUTPUT);
  pixy.init(); // initiate pixy
  Serial.begin(9600);
  Serial.println("Begin..!");
}


void loop()
{
  if(Zone()>0)
  {
    Send(Zone());
  }
}


int Zone()
{
    blocks=pixy.getBlocks(); //gets the blocks from pixy
  //if blocks detected
  if(blocks and !Tz3())
  {
    int i;
    for(i=0;i<blocks;i++)
    {
      //if the green ball's signature is detected
      if(pixy.blocks[i].signature == signGreen)
      {
        if(isMagenta) // if magenta has already been given
        {
          Serial.println("Zone 2");
          return 2; // go to zone 2 with this green ball
        }
        else
      {
        Serial.println("Zone 1");
        return 1; // otherwise go to zone 1
      }
      }
      else if(pixy.blocks[i].signature == signMagenta) // when magenta ball is passed,
      {
        isMagenta=true; // make isMagenta as true and,
        Serial.println("Zone 2");
        return 2;       // select to go to zone 2
      }
    }
  }
  //else if the ball for zone three is passed, call the function to detect if the ball is present for zone3
  else if(Tz3())
  {
    Serial.println("Zone 3");
    return 3; // select to go for zone 3
  }
  else
  {
    Serial.println("Nothing...");
    return -1;
  }
}


float tme(int pulse){
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(pulse);
  digitalWrite(trigPin,LOW);
  float pTime= pulseIn(echoPin,HIGH)/2;
  return pTime;
}


bool Tz3()
{  
  dist=tme(10)/29;
  if(minDist<= dist or dist <=maxDist)// if distance is in range 
  return true;                        // return true
  return false;                       // else return false
   
}


void Send(int n)
{
  if(n==1){
    pinMode(lsbPin,HIGH);
    pinMode(msbPin,LOW);  
  }
  else if(n==2){
    pinMode(lsbPin,LOW);
    pinMode(msbPin,HIGH);
  }
  else if(n==3){
    pinMode(lsbPin,HIGH);
    pinMode(msbPin,HIGH);
  }
}

