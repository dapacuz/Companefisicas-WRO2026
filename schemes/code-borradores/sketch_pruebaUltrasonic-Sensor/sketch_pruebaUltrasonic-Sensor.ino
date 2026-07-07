// DEFINITIONS
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // setup code here, to run once:
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);

  Serial.begin (9600);

}

void loop() {
  // main code here, to run repeatedly:
  digitalWrite (trigPin, LOW);
  delayMicroseconds (2);
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);

  long duration = pulseIn (echoPin, HIGH);

  float distance = duration * 0.034 / 2;
  Serial.print ("Distancia: ");
  Serial.print (distance);
  Serial.println (" cm");

  delay(500);
  
}
