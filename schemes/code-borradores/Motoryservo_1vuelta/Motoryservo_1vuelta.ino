//Programa 

//LIBRERÍAS 
#include <AFMotor.h>
#include <Servo.h> //servo

//PINES
int trigPinL = A4;     // TRIG pin izquierda
int echoPinL = A5;    // ECHO pin izquierda
int trigPinR = A2;  // TRIG pin izquierda
int echoPinR = A3;    // ECHO pin izquierda
int trigPinF = A0;    // TRIG pin izquierda
int echoPinF = A1;    // ECHO pin izquierda

//FLOAT
//float sensores
float duration_us_L, distance_cm_L;
float duration_us_R, distance_cm_R;

//direcciones
int turn_sl = 75;
int turn_sr = 105;
int turn_l = 55;
int turn_r = 125;
int turn_al = 30;
int turn_ar = 150;
int recto =90;

// distancias
int centered = 65;
int close = 51;
int veryclose = 31;
int far = 71;
int veryfar = 85;
int superfar = 101;
int supermegafar = 135;
int supermegaclose = 0;
int superclose = 15;

// velocidades
int slow = 20;
int fast = 35;
int veryfast = 50;
int superfast = 70;
int supermegafast = 90;

Servo myServo;
AF_DCMotor motor(3);

int pos = 0;

void setup() { //INICIO: comandos que se repiten 1 vez
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(trigPinL, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPinL, INPUT);

    pinMode(trigPinR, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPinR, INPUT);
  //servo
  myServo.attach(10);
  //motor
    motor.setSpeed(70);

    motor.run(RELEASE);

       } //FIN de los comandos iniciales

void loop() { //repeticiones infinitas

  motor.run(FORWARD);
  delay (1000);
  myServo.write(turn_r);
  delay (200);
    myServo.write(recto);
  delay (2000);
  myServo.write(turn_r);
  delay (200);
    myServo.write(recto);
  delay (2000);
    myServo.write(turn_r);
  delay (200);
    myServo.write(recto);
  delay (2000);
    myServo.write(turn_r);
  delay (200);
    myServo.write(recto);

  delay (1000);
  motor.setSpeed(0);
  delay(60000);
}

