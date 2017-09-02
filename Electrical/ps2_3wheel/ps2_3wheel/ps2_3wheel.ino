#include <PS2X_lib.h>
PS2X ps2x;

#define PS2_DAT        13 
#define PS2_CMD        11 
#define PS2_SEL        10  
#define PS2_CLK        12  

int green=0; int red=0; int blue=0; int pink=0;
int L1=0; int L2=0; int R1=0; int R2=0;
int UP=0; int DOWN=0; int LEFT=0; int RIGHT=0;
int SELECT=0; int START=0;



int dir_left=2;
int dir_right=4;
int dir_f=7;
int pwm_left=3;
int pwm_right=5;
int pwm_f=6;

int lf=40;

void setup() {
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  Serial.begin(9600);
  
}

void loop() {
   ps2x.read_gamepad();
   
   green=ps2x.ButtonPressed(PSB_GREEN);
   red=ps2x.ButtonPressed(PSB_RED);
   blue=ps2x.ButtonPressed(PSB_BLUE);
   pink=ps2x.ButtonPressed(PSB_PINK);
   L1=ps2x.ButtonPressed(PSB_L1);
   L2=ps2x.ButtonPressed(PSB_L2);
   R1=ps2x.ButtonPressed(PSB_R1);
   R2=ps2x.ButtonPressed(PSB_R2);
   UP=ps2x.ButtonPressed(PSB_PAD_UP);
   DOWN=ps2x.ButtonPressed(PSB_PAD_DOWN);
   LEFT=ps2x.ButtonPressed(PSB_PAD_LEFT);
   RIGHT=ps2x.ButtonPressed(PSB_PAD_RIGHT);
   SELECT=ps2x.ButtonPressed(PSB_SELECT);
   START=ps2x.ButtonPressed(PSB_START);
   
   
   if(green==1 && R1==0){
   Serial.println("Triangle just pressed");
   red=0;
   }
   
   if(red==1){
   Serial.println("Circle just pressed");
   blue=0;
   }
   
   if(blue==1){
   Serial.println("X just pressed");
   pink=0;
   }
   
   if(pink==1)
   Serial.println("Square just pressed");
   
   if(L1==1 && R2==0){
   Serial.println("L1 just pressed");
   R1=0;
   }
   
   if(L2==1 && LEFT==0){
   Serial.println("L2 just pressed");
   R2=0;
   }
   
   if(R1==1 && green==1)
   {lf = lf+1;
   Serial.println("R1 just pressed");
   }
   if(R2==1 && L1==1){
   Serial.println("R2 just pressed");
   lf=lf-1;
   }
   
   if(UP==1 && START==0){
   Serial.println("UP just presses");
   RIGHT==0;
   }
   
   if(DOWN==1 && RIGHT==0){
   Serial.println("DOWN just presses");
   LEFT=0;
   }
   
   if(LEFT==1 && L2==1)
   Serial.println("LEFT just presses");
   
   if(RIGHT==1 && DOWN==1)
   Serial.println("RIGHT just presses");
   
   if(SELECT==1 )
   Serial.println("SELECT just presses");
   if(START==1 )
   Serial.println("START just presses");
   /*if(ps2x.Analog(PSS_LX)<110)
   {
      
   }*/
   //Serial.print("Left Stick:");
   int l_axis=(114-ps2x.Analog(PSS_LY));
   int r_axis=(114-ps2x.Analog(PSS_RY));
   
   if((l_axis>50)&&(r_axis>50))
   {
    digitalWrite(dir_left,LOW);
    analogWrite(pwm_left,lf);
     digitalWrite(dir_right,LOW);
    analogWrite(pwm_right,50);
   Serial.println("GO FRONT");
   }
   else if((l_axis<-50)&&(r_axis<-50))
   {
     digitalWrite(dir_left,HIGH);
    analogWrite(pwm_left,lf);
     digitalWrite(dir_right,HIGH);
    analogWrite(pwm_right,50);
   Serial.println("GO BACK");
   
   
   }
  /* Serial.print(ps2x.Analog(PSS_LY));
   Serial.print("      Right Stick:");
   Serial.print(ps2x.Analog(PSS_RX));
   Serial.print(",");
   Serial.println(ps2x.Analog(PSS_RY));*/

   
   else if((r_axis>100)&&(l_axis>-145))
   {
     digitalWrite(dir_left,HIGH);
    analogWrite(pwm_left,100);
     digitalWrite(dir_right,LOW);
    analogWrite(pwm_right,100);
     digitalWrite(dir_f,HIGH);
    analogWrite(pwm_f,100);
     
   Serial.println("GO LEFT");
   }
   else if((r_axis>-145)&&(l_axis>100))
   {
    digitalWrite(dir_left,LOW);
    analogWrite(pwm_left,100);
     digitalWrite(dir_right,HIGH);
    analogWrite(pwm_right,100);
     digitalWrite(dir_f,LOW);
    analogWrite(pwm_f,100);
   Serial.println("GO RIGHT");
   }
   
else
{
  digitalWrite(dir_left,HIGH);
    analogWrite(pwm_left,0);
     digitalWrite(dir_right,LOW);
    analogWrite(pwm_right,0);
     digitalWrite(dir_f,LOW);
    analogWrite(pwm_f,0);
  
  
  
  
  }
  
   
   
   
 
 }
