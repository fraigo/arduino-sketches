/**
 * 
 * HC-SR04 Test program
 * 
 * Ultrasonic Sensor HC-SR04 read values
 * 
 * Author     : Francisco Igor <franciscoigor@gmail.com>
 * References : https://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/ (example)
 *              https://www.mouser.com/ds/2/813/HCSR04-1022824.pdf (manual)
 * 
 * Components
 * ----------
 * HC-SR04  - VCC  connected to 5V (+)
 *            TRIG connected to PIN 13 (trigPin)
 *            ECHO connected to PIN 12 (echoPin)
 *            GND  connected to GND (-)
 * 
 * Results
 * -------
 * Open serial monitor or Serial Plotter 
 * to view sensor reading (in cms of distance)
 * 
 */

#define trigPin 13
#define echoPin 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance<1000){
    Serial.println(distance);
  }

  delay(200);
  
}

