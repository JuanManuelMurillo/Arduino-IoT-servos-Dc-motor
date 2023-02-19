//Variables are defined at "Cloud Variables" (Angulo,Angulo2,Angulo3,Angulo4,Velocidad)


#include "thingProperties.h"
#include <Servo.h>

//Define Dc motor pin as 2
#define MOTOR_PIN 2

//Add 5 servo objects 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
//Initialize Serial monitor 
  Serial.begin(9600);
  delay(1500); 

//Attach servos to pin 3,4,5,1,0
servo1.attach(3);
servo2.attach(4);
servo3.attach(5);
servo4.attach(1);
servo5.attach(0);

//Attach Dc motor to pin 2 as an output
pinMode(MOTOR_PIN,OUTPUT);

//Write 0 to the Dc motor
analogWrite(MOTOR_PIN,0);

//Initialize IoT
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

void onAnguloChange()  {
  servo1.write(angulo);
  servo2.write(angulo);
  Serial.println(angulo);
}

void onAngulo2Change()  {
  servo3.write(angulo2);
  Serial.println(angulo2);
 
}

void onAngulo3Change()  {
  servo4.write(angulo3);
  Serial.println(angulo3);
}

void onAngulo4Change()  {
  servo5.write(angulo4);
  Serial.println(angulo4);
}

void onVelocidadChange()  {
  analogWrite(MOTOR_PIN,velocidad);
  Serial.println(velocidad);
}