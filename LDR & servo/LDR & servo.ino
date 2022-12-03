/*Control a servo motor using an LDR
Learning themes: Including and using servo library, map function, using and calculating ohms, volts and bits across an LDR*/

#include <Servo.h>// include the servo library

Servo myservo;  // create servo object to control a servo
#define Mult (5.00/1023.00) //declares the float variable used to convert bits to volts 
#define rezpin A0 // analog pin used to connect the potentiometer
long nowtime;
long lasttime;
int angle ;
int Bits;    //declares the float variable used to save the value of volts
float Volts ;//declares the integer variable used to save the value of Volts
float Ohms ;//declares the float variable used to save the value of ohms

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);//begins serial communication and sets bit rate
}

void loop() {
  nowtime = millis();
  Bits = analogRead(rezpin);            // reads the value of the  (value between 0 and 1023)
  Volts = Mult * Bits; //calculates volts by multiplying mult and bits
  Ohms = (1650/Volts) - 330;//calculates ohms using this equation --> Vo = Vcc ( R / (R + Photocell) )
  angle = map(Bits, 3, 730, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
   myservo.write(angle);                  // sets the servo position according to the scaled value
   delay(15);                           // waits for the servo to get there

  if (nowtime - lasttime >= 2000) { //if 2 seconds has passed, then
    lasttime = nowtime;// save current time to lasttime
  Serial.println(Bits);//Print to moniter value of bits
  Serial.println(Volts);//Print to moniter value of Volts 
  Serial.println(Ohms);//Print to moniter value of ohms
  }
}

