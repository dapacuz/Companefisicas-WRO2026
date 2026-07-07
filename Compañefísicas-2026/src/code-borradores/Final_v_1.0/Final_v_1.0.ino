//PROGRAMA FINAL DE JONNY CARRE BRAVO!!

//LIBRERÍAS 
#include <HUSKYLENS.h> //camarita
#include <Servo.h> //servo
#include <AFMotor.h> //motor 

//PINES
AF_DCMotor motor (3); //motor 3 en L293D shield
int trigPinL = A5;    // TRIG pin izquierda
int echoPinL = A4;    // ECHO pin izquierda
int trigPinR = A3;    // TRIG pin izquierda
int echoPinR = A2;    // ECHO pin izquierda
int trigPinF = A0;    // TRIG pin izquierda
int echoPinF = A1;    // ECHO pin izquierda
long duration_us_L;
float distance_cm_L;
long duration_us_R;
float distance_cm_R;

//direcciones del servo + grados
int turn_sl = 75;
int turn_sr = 105;
int turn_l = 55;
int turn_r = 125;
int turn_al = 30;
int turn_ar = 150;
int recto =90;

//sensores - distancias
float centered = 65; //centrado
float close = 51;
float veryclose = 31;
float far = 71;
float veryfar = 85;
float superfar = 101;
float supermegafar = 135; //distancia max antes de error
float supermegaclose = 0;
float superclose = 15;

// velocidades
int slow = 20;
int fast = 35;
int veryfast = 50;
int superfast = 70;
int supermegafast = 90;

//delays que no son delays pero yo los conozco como delays 
unsigned long previousMillis;
unsigned long currentMillis;
const long longinterval = 2000;
const long shortinterval = 1000;
const long turninterval = 500; 
const long SuperShortinterval = 100;
const long SuperLonginterval = 3000;


Servo myServo; //objeto servo

void setup() { //INICIO: comandos que se repiten 1 vez
  // begin serial port


  // configure the trigger pin to output mode
  pinMode(trigPinL, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPinL, INPUT);

    pinMode(trigPinR, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPinR, INPUT);
  //servo
  myServo.attach(10); //pin 10
  Serial.begin (9600); //actualizacion del programa
   //Switch the algorithm to object tracking
       } //FIN de los comandos iniciales


void loop() { //repeticiones
currentMillis = millis();
  // generate 10-microsecond pulse to TRIG pin

digitalWrite(trigPinL, LOW);
delayMicroseconds(2);
digitalWrite(trigPinL, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinL, LOW);
long duration_us_L = pulseIn(echoPinL, HIGH);
float distance_cm_L = duration_us_L * 0.034 / 2;


digitalWrite(trigPinR, LOW);
delayMicroseconds(2);
digitalWrite(trigPinR, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinR, LOW);
long duration_us_R = pulseIn(echoPinR, HIGH);
float distance_cm_R = duration_us_R * 0.034 / 2;

  // print the value to Serial Monitor
  Serial.print("distance left: ");
  Serial.print(distance_cm_L);
  Serial.println(" cm");
  Serial.print("distance right: ");
  Serial.print(distance_cm_R);
  Serial.println(" cm");




  if (distance_cm_L>=supermegafar || distance_cm_L>=supermegafar) { 
    motor.setSpeed(0); //para el carro
    }else if (distance_cm_L >= centered && distance_cm_L <= far && distance_cm_R >= centered && distance_cm_R <= far){ // va recto si +- centrado
      myServo.write(recto);
      if (currentMillis - previousMillis >= SuperShortinterval) {
        motor.setSpeed(180);
        previousMillis = currentMillis;
      }
      motor.setSpeed(50); 

    }else if (distance_cm_L >= far && distance_cm_L <= veryfar && distance_cm_R >= veryclose && distance_cm_R <= close){ //gira poquito left
       myServo.write(turn_sl);
        if (currentMillis - previousMillis >= SuperShortinterval) {
        motor.setSpeed(180);
        previousMillis = currentMillis;
      }
        motor.setSpeed(slow);
       }else if (distance_cm_L >= veryfar && distance_cm_L <= superfar && distance_cm_R >= superclose && distance_cm_R <= veryclose){ //gira left
         myServo.write(turn_l);
        if (currentMillis - previousMillis >= SuperShortinterval) {
        motor.setSpeed(180);
        previousMillis = currentMillis;
      }
          motor.setSpeed(50);
         }else if (distance_cm_L >= superfar && distance_cm_L <= supermegafar && distance_cm_R >= supermegaclose && distance_cm_R <= superclose){ //gira bastante left
             myServo.write(turn_al);
            if (currentMillis - previousMillis >= SuperShortinterval) {
              motor.setSpeed(180);
              previousMillis = currentMillis;
            }
              motor.setSpeed(50);

    }else if (distance_cm_R >= far && distance_cm_R <= veryfar && distance_cm_L >= veryclose && distance_cm_L <= close){ //gira poquito right
       myServo.write(turn_sr);
        if (currentMillis - previousMillis >= SuperShortinterval) {
        motor.setSpeed(180);
        previousMillis = currentMillis;
      }
        motor.setSpeed(50);
       }else if (distance_cm_R >= veryfar && distance_cm_R <= superfar && distance_cm_L >= superclose && distance_cm_L <= veryclose){ //gira right
         myServo.write(turn_r);
          if (currentMillis - previousMillis >= SuperShortinterval) {
            motor.setSpeed(180);
            previousMillis = currentMillis;
      }
          motor.setSpeed(50);
         }else if (distance_cm_R >= superfar && distance_cm_R <= supermegafar && distance_cm_L >= supermegaclose && distance_cm_L <= superclose){ //gira bastante right
             myServo.write(turn_ar);
              if (currentMillis - previousMillis >= SuperShortinterval) {
                motor.setSpeed(180);
                previousMillis = currentMillis;
              motor.setSpeed(50);
         }

  if (currentMillis - previousMillis >= longinterval) {
    motor.setSpeed(180);
    previousMillis = currentMillis;
}
         }
}

//FINAL DEL PROGARMA

//COSAS Q NO SE TOMARON EN CUENTA: esquinas, probar si gira
