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
float duration_us_L, distance_cm_L;
float duration_us_R, distance_cm_R;
float turn_sl = 75;
float turn_sr = 105;
float turn_l = 55;
float turn_r = 125;
float turn_al = 30;
float turn_ar = 150;
float recto =90;

float centered = 65;
float close = 51;
float veryclose = 31;
float far = 71;
float veryfar = 85;
float superfar = 101;
float supermegafar = 135;
float supermegaclose = 0;
float superclose = 15;



float slow = 20;
float fast = 35;
float veryfast = 50;
float superfast = 70;
float supermegafast = 90;

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
    motor.setSpeed(200);

    motor.run(RELEASE);

       } //FIN de los comandos iniciales

void loop() { //repeticiones

  motor.run(FORWARD);
  delay (1000);
  myServo.write(180);
  delay (200);
    myServo.write(90);
  delay (2000);
  myServo.write(180);
  delay (200);
    myServo.write(90);
  delay (2000);
    myServo.write(180);
  delay (200);
    myServo.write(90);
  delay (2000);
    myServo.write(180);
  delay (200);
    myServo.write(90);

  delay (1000);
  motor.setSpeed(0);
  delay(60000);
}

