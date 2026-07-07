#include <AFMotor.h>                 // Incluir libreria de Adafruit Motor Shield
AF_DCMotor motor1(1);                // Crear objeto motor1

unsigned char velocidad1 = 0x00;    // Controlar velocidad para motor1 (8 bits)

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  velocidad1 = 0xFF;             // Guardar valor de velocidad maxima 
  motor1.setSpeed(velocidad1);   // Establecer velocidad1 en motor1
  motor1.run(FORWARD);           // Activar motor1 hacia adelante
  delay(2000);                   // Esperar 2 segundos

  velocidad1 = 0x00;            // Guardar valor de velocidad cero
  motor1.setSpeed(velocidad1);  // Establecer velocidad1 en motor1
  motor1.run(RELEASE);           // Detener Motor
  delay(10);                     // Esperar 10 microsegundos


  velocidad1 = 0xFF;            // Guardar valor de velocidad maxima
  motor1.setSpeed(velocidad1);  // Establecer velocidad1 en motor1
  motor1.run(BACKWARD);          // Activar motor1 hacia atras
  delay(2000);                   // Esperar 2 segundos

  velocidad1 = 0x00;            // Guardar valor de velocidad cero
  motor1.setSpeed(velocidad1);  // Establecer velocidad1 en motor1
  motor1.run(RELEASE);           // Detener Motor
  delay(10);                     // Esperar 10 microsegundos

}
