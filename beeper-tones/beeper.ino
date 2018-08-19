/**
 * Beeper - Musical notes 
 * Author: Francisco Igor
 *         franciscoigor@gmail.com
 * 
 * Components
 * 
 *    Buzer connected 
 *       (+) to Analog Output 3
 *       (-) to GND
 *    Potentiometer 
 *       (left pin)  connected to +5V
 *       (right pin) connected to GND
 *       (cente pin) connected to Analog input 0
 *       
 *       
 * Results
 *  
 *  When you rotate the potentiometer from min to max you will hear a musical scale, 
 *  this scale is translated from min and max analog potentiometer value to note positions (0 to 7)
 *  
 */

#define ANALOG_IN A0
#define BUZZER_OUT 3


int notes[]= {
  262, 294, 330, 349, 392, 440, 493 , 523 
};

int note ;

void setup() {
  // put your setup code here, to run once:

}

void loop() {

   int analorReading = analogRead(ANALOG_IN);
   int note = map(analorReading, 0, 1023, 0, 7);

   
   tone(BUZZER_OUT, notes[note], 110);
   delay(100);
  
}
