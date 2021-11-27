#include <Servo.h>
 
Servo servoMotor;

int lastValue = 0;
 
void setup() {
  Serial.begin(9600);
  servoMotor.attach(3);
}
 
void loop() {

  float MAX = 1023.0;
  float SCALE = 180.0;
  int value = analogRead(A0) * SCALE / MAX ;

  Serial.println(value);

  if (lastValue != value) {
    servoMotor.write(value);
  }
  delay(50);
  lastValue = value;

}
