/*Control a stepper motor direction using a joystick
Learning themes: Including and using stepper library, map function*/

#include <Stepper.h>// include the servo library

int jspin = A0;// declaring an int named jspin that is equal to A0
int jsval;//declaring an int named jsval
int turn;//declaring an int named turn

Stepper steppermotor(32, 8, 9, 10, 11);// Create Instance of Stepper Class Specifing Pins used for motor coils and # of steps/revolution

void setup()
{
  Serial.begin(9600);//Begin the serial moniter
}

void loop()
{
   steppermotor.setSpeed(1000);    // set speed to 1000rpm   
jsval = analogRead(jspin); // read value at A0 and save to jsval
turn = map(jsval, 0, 1024, -225, 225);// map the jsval (A1) to the min value -225 and the max value 225 and save in spot turn

Serial.println(turn);// Print the vaalue of turn to the serial moniter
if (jsval <= 1024 && jsval >= 550){//If jsval is less than or equal to 1024, and greater than or equal to 550 then...
steppermotor.step(turn);//turn the stepper motor Turn values steps
}
if (jsval <= 500 && jsval >= 0){//If jsval is less than or equal to 500, and greater than or equal to 0 then...
steppermotor.step(turn);//turn the stepper motor Turn values steps
}
}