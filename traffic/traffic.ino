/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  Components:
  1 green led  - connected (+) to PIN 11 (ledg) and ground (-)
  1 yellow led - connected (+) to PIN 09 (ledy) and ground (-)
  1 red led    - connected (+) to PIN 06 (ledy) and ground (-)

  Result:
  Each led is fading-in and fading-out in sequence

  
*/

int ledr = 6;           // the PWM pin the LED is attached to
int ledy = 9;           // the PWM pin the LED is attached to
int ledg = 11;           // the PWM pin the LED is attached to
int leds[] = { ledg, ledy, ledr};

int brightness = 0;    // how bright the LED is
int fadeAmount = 10;    // how many points to fade the LED by
int fadeFactor = 1;
int ledNum= 0;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

  if (brightness<0) {
    brightness=0;
  }
  if (brightness>255) {
    brightness=255;
  }
  // set the brightness of pin 9:
  analogWrite(leds[ledNum], brightness);
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount * fadeFactor;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeFactor = -fadeFactor;
  }

  if (brightness <= 0){
    analogWrite(leds[ledNum], 0);
    ledNum++;
    if (ledNum==3){
      ledNum = 0;
    }
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

