/* 
 * Ultrasonic sensor example 
 * It triggers a led light when distance is near the sensor
 * 
 * 1 US (ultrasonic sensor) HC-SR04 
 * 1 LED
 * 1 resistor
 * 6 cables 
 * 
 * 1 cable PW- to US-GND
 * 1 cable US-Echo to Digital Pin 6
 * 1 cable US-Trigger to Digital Pin 7
 * 1 cable PW+ to US-5V
 * 1 cable Pin 5 to Resistor
 * Resistor connected to LED+
 * 1 cable PW- to LED-
 */


const int triggerPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
const int ledPin = 5; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(echoPin, INPUT);
   pinMode(triggerPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
}

void loop() {
   long duration, cm;
   // clear trigger pin
   digitalWrite(triggerPin, LOW);
   delayMicroseconds(2);
   // activate trigger pin for 10ms
   digitalWrite(triggerPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(triggerPin, LOW);
   // get pulse duration
   duration = pulseIn(echoPin, HIGH);
   cm = duration / 60;
   // turn on the light if distance is less than N
   if (cm < 10) {
    digitalWrite(ledPin, HIGH);
   } else {
    digitalWrite(ledPin, LOW);
   }
   // print data for console/plotter
   Serial.print(duration);
   Serial.print(" ");
   Serial.print(cm);
   Serial.print("");
   Serial.println();
   delay(200);
}
