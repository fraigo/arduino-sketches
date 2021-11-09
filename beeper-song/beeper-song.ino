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
 *  A song is played through the buzzer using note frequecies.
 *  When you rotate the potentiometer from min to max 
 *  you will hear the song in different velocities
 *  
 */

#define ANALOG_IN A0
#define BUZZER_OUT 3

const int DO = 262;
const int RE = 294;
const int MI = 330;
const int FA = 349;
const int SOL= 392;
const int LA = 440;
const int SIb = 469;
const int SI = 493;

int notes[]= {
  DO, RE, MI, FA, SOL, LA, SI
};


int song[] = {
  // mary had a little lamb
  // MI, RE, DO, RE, MI, MI, MI, 0, RE, RE, RE, 0, MI, SOL, SOL, 0, MI, RE, DO, RE, MI, MI, MI, MI, RE, RE, MI, RE, DO, DO, DO, 0
  // happy birthday
  // DO, DO, RE, DO, FA, MI, 0 , DO, DO, RE, DO, SOL, FA, 0, DO, DO, DO*2, LA, FA, FA, MI, RE, 0, SIb, SIb, LA, FA, SOL, FA, 0
  // twinkle twinkle
  DO, DO, RE, RE, MI, MI, DO, DO, DO, DO, RE, RE, MI, MI, DO, DO, MI, MI, FA, FA, SOL, SOL, SOL, SOL, MI, MI, FA, FA, SOL, SOL, SOL, SOL, SOL, LA, SOL, FA, MI, MI, DO, DO, SOL, LA, SOL, FA, MI, MI, DO, DO, RE, RE, SOL/2, SOL/2, DO, DO, DO, DO, RE, RE, SOL/2, SOL/2, DO, DO, DO, DO, 0
};

int pos;
int note;

void setup() {
  pos = 0;
  Serial.begin(9600);  
}

void loop() {

   int analorReading = analogRead(ANALOG_IN);
   int velocity = map(analorReading, 0, 1023, 1, 4);
   size_t size = sizeof(song)/sizeof(song[0]);
   
   tone(BUZZER_OUT, song[pos], 400 / velocity + 10);
   delay(400 / velocity );

   pos++;
   if (pos >= size){
    pos = 0;
   }
  
}
