/**
 * Step motor - direction control
 * Author: Francisco Igor
 * Email : franciscoigor@gmail.com
 * 
 * 
 */
#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins 2 through 5:
Stepper myStepper(stepsPerRevolution, 2, 4, 3, 5);


void setup() {
  // nothing to do inside the setup
}
void loop() {
  // read the potentiometer value:
  int sensorReading = analogRead(A0);
  
  // Map it to a range from -2 to 2
  int direction = map(sensorReading, 0, 1023, -2, 2);
  
  // set the motor speed and step direction
  myStepper.setSpeed(50);
  myStepper.step(direction);

  delay(10);
}
