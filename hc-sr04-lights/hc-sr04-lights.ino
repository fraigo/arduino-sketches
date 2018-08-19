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
 *            Green Led connected (+) to PIN 9 through 330K resistor
 *            Red Led connected (+) to PIN 11 through 330K resistor
 * 
 * Results
 * -------
 * Open serial monitor or Serial Plotter 
 * to view sensor reading (in cms of distance)
 * 
 */

#define trigPin 13
#define echoPin 12

#define redLed 11
#define greenLed 9

void setup() {
  Serial.begin (9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  long duration, distance, prev;
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance<1000 ){
    Serial.println(distance);
  }

  
  
  if (distance<15 ){
    analogWrite(redLed,255 - (distance*15));
    analogWrite(greenLed,0);
  }
  else if (distance<80 ){
    analogWrite(greenLed,255-(distance*3));
    analogWrite(redLed,0);
  }else {
    analogWrite(redLed,0);
    analogWrite(greenLed,0);
  }

  prev = distance;

  delay(50);
  
}

