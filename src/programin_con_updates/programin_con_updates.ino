// Include the library
#include <L298N.h>
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
int pos = 90; 
const unsigned long rectas = 2000;
float velocidad;
unsigned long tiempo;
unsigned long T;
unsigned long deltaT;
unsigned long deltaT2;
const unsigned long curvas = 1000;
// Pin definition
const unsigned int IN1 = 8;
const unsigned int IN2 = 7;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);

void setup()
{
  // Used to display information
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the Servo object
  // Wait for Serial Monitor to be opened
  while (!Serial)
  {
    //do nothing
  }
  // Set initial speed
  motor.setSpeed(70);
  tiempo = millis();
}

void loop() {

T = millis();
deltaT = T - tiempo;
printTime(deltaT,90,1000);


if (deltaT <= rectas){
  myservo.write(90); 
  printTime(deltaT,90, 1000);
  velocidad = 80;
  motor.setSpeed(velocidad);
 }else if (deltaT <= rectas + curvas){
  myservo.write(45); 
  printTime(deltaT,45, 1000);
  velocidad = 60;
  motor.setSpeed(velocidad); 

}
if (deltaT > rectas + curvas) {
  deltaT = 0;
}
}

int printTime(long Ti, int an, int de){ //definimos 3 variables q funcionan como parametros para la funcion (Ti, an, del). a printTime siempre hay q ponerle 2 valores, si no da error
  int i; //i es variable interna (contador)
  for (i=0;i>=de;i++){ //for es un loop -> i1 es ligeramente distinto q i2
    Serial.println(Ti);
    Serial.println(an);
    return 0;
  }
}