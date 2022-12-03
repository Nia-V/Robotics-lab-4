/*control speed and direction of a dc motor using a joystick and an L29. chip 
Learning themes: L29. chip, map function, Using digital write to sswitch ground and 5V*/



#define joypin A0 //Defines the joystick pin as A1
int joyval;//Saves a spot in memory called joyval
int speed; //Saves a spot in memory called speed

void setup() {
pinMode(5,OUTPUT);// pin 5 connected to L29. pin1 (Enable for inputs 1 & 2) is an output
pinMode(4,OUTPUT);// pin 4 connected to L29. pin2 (Input 1) is an output
pinMode(3,OUTPUT);}// pin 3 connected to L29. pin7 (Input 2) is an output

void loop() {
joyval = analogRead(joypin);//read value of A1 and save is spot joyval
  if (joyval <= 575){//if joyval is greater than 575 then..
      digitalWrite(4, 0);//make pin 4 gnd (Input 1)
      digitalWrite(3, 1);// make pin 3 +5V(Input 2)
      speed = map(joyval, 575, 1024, 50, 225);// map the joyval (A1) to the min value 50 and the max value 255 and save in spot speed
      analogWrite(5,speed);}//output the value of speed to pin 5 (Enable)

  if(joyval >= 450){//if joyval is lesser than 450 then..
      digitalWrite(3, 0);// make pin 3 gnd(Input 2)
      digitalWrite(4, 1);//make pin 4 +5V (Input 1)
      speed = map(joyval, 0, 450, 225, 50);// map the joyval (A1) to the min value 50 and the max value 255 and save in spot speed
      analogWrite(5,speed);}//output the value of speed to pin 5 (Enable)
}