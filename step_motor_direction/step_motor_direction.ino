/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 2 through 5:
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);
int stepCount = 0;  // number of steps the motor has taken
void setup() {
  // nothing to do inside the setup
}
void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  
  // map it to a range from 0 to 100:
  int direction = map(sensorReading, 0, 1023, -2, 2);
  // set the motor speed:
  myStepper.setSpeed(50);
  myStepper.step(direction);

  delay(10);
}
