/*Control a stepper motor direction and speed using a IR Remote
Learning themes: Including and using stepper library, using and including IR library, using switch case*/

#include <Stepper.h> // include the servo library
#include <IRremote.h> // include the servo library
#define RECEIVER  6 //Defining Reciever as 6

IRrecv irrecv(RECEIVER);//Creating a class of IRrecv called irrecv and specifing its connection to pin 6
decode_results results;//Creating an objec called results of the decode_results class
unsigned long key_value = 0;// declaring unsigned long called key_value
int stopper;// Declaring int called stopper 
int faster = 1000;// Declaring int called faster equal to 1000
Stepper steppermotor(32, 8, 9, 10, 11);// Create Instance of Stepper Class Specifing Pins used for motor coils and # of steps/revolution
void setup(){
  Serial.begin(9600);//Begin serial moniter
  irrecv.enableIRIn();//Call the function to start the reciever
  irrecv.blink13(true);//Call the function to blink the built-in LED 13 when the reciever gets a signal
}

void loop(){
steppermotor.setSpeed(faster);  // set speed to The value of faster (RPM)   
  if (irrecv.decode(&results)){// if the Reciever gets a signal then...
 
        if (results.value == 0XFFFFFFFF)//if the same signal is recieved twice/ repeated then...
          results.value = key_value;// results.value = 0

        switch(results.value){//if results.value is equal to the signal corresponding to the button, serial print the buttons name.
           case 0xFFA25D:
          Serial.println("ON/OFF");
          break;
          case 0xFF629D://if results.value is equal to the signal corresponding to the button, serial print the buttons name &...
          Serial.println("VOL+");
         faster = faster+100;// set faster equal to faster + 100
          break;
          case 0xFFE21D:
          Serial.println("STOP");
          break;
          case 0xFF22DD://if results.value is equal to the signal corresponding to the button, serial print the buttons name &...
          Serial.println("|<<");
          stopper = 0;// Set stopper equal to 0
          break;
          case 0xFF02FD:
          Serial.println("PLAY/PAUSE");
          break ;  
          case 0xFFC23D:
          Serial.println(">>|");//if results.value is equal to the signal corresponding to the button, serial print the buttons name &...
          stopper = 1;// Set stopper equal to 1
          break ;               
          case 0xFFE01F:
          Serial.println("DOWN");
          break ;  
          case 0xFFA857:
          Serial.println("VOL-");//if results.value is equal to the signal corresponding to the button, serial print the buttons name &...
          faster = faster-100;// set faster equal to faster - 100
          break ;  
          case 0xFF906F:
          Serial.println("UP");
          break ;  
          case 0xFF6897:
          Serial.println("0");
          break ;  
          case 0xFF9867:
          Serial.println("EQ");
          break ;
          case 0xFFB04F:
          Serial.println("REPT");
          break ;
          case 0xFF30CF:
          Serial.println("1");
          break ;
          case 0xFF18E7:
          Serial.println("2");
          break ;
          case 0xFF7A85:
          Serial.println("3");
          break ;
          case 0xFF10EF:
          Serial.println("4");
          break ;
          case 0xFF38C7:
          Serial.println("5");
          break ;
          case 0xFF5AA5:
          Serial.println("6");
          break ;
          case 0xFF42BD:
          Serial.println("7");
          break ;
          case 0xFF4AB5:
          Serial.println("8");
          break ;
          case 0xFF52AD:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }

  if (stopper == 0){//if stopper is 0...
    steppermotor.step(225);   //Turn the stepper motor 225 steps
  }
if (stopper == 1){//if stopper is 1...
    steppermotor.step(-225); //Turn the stepper motor -225 steps
  }
}
