#include <Servo.h>
 
Servo servoMotor;
 
void setup() {
  Serial.begin(9600);
  servoMotor.attach(3);
}
 
void loop() {
  
  servoMotor.write(90);
  delay(500);
  
  servoMotor.write(0);
  delay(500);
  
  servoMotor.write(90);
  delay(500);

  servoMotor.write(180);
  delay(500);

}
