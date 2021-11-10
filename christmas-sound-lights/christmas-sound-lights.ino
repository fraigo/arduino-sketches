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

const int DO = 2620;
const int RE = 2940;
const int MIB = 3110;
const int MI = 3300;
const int FA = 3490;
const int SOL= 3920;
const int LA = 4400;
const int SIb = 4690;
const int SIB = 4690;
const int SI = 4930;

const double octave = 1;

int notes[]= {
  DO, RE, MI, FA, SOL, LA, SI
};


int song[] = {
  // silent night
  /* */
  FA+3, SOL, FA+2, RE+5, 0, 
  FA+3, SOL, FA+2, RE+5, 0, 
  DO*2+3, 0, DO*2+2,  LA+5, 0,
  SIB+3, 0, SIB+2,  FA+5, 0,
  SOL+3, 0, SOL+2,  SIB+3, LA, SOL+2, FA+3, SOL, FA+2, RE+5, 0,
  SOL+3, 0, SOL+2,  SIB+3, LA, SOL+2, FA+3, SOL, FA+2, RE+5, 0,
  DO*2+3, 0, DO*2+2, MIB*2+3, DO*2, LA+2, SIB+6, RE*2+4 , 0, 0,
  SIB+3, FA, RE+2, FA+3, MIB, DO+2, SIB/2+6, SIB/2+2, 0+2,
  /* */
  DO*2+4, RE*2, DO*2, SIB, LA, SIB+4, 
  DO*2, SIB, LA, SOL, LA+4,
  SIB, LA, SOL, FA, SOL+3, DO, DO, 0+2,
  FA+2, SOL+2, LA+2, SIB+2, LA+4, SOL+4,   
  DO*2+4, RE*2, DO*2, SIB, LA, SIB+4, 
  DO*2, SIB, LA, SOL, LA+4,
  SIB, LA, SOL, FA, SOL+3, DO, DO, 0+2,
  FA+2, SOL+2, LA+2, SIB+2, LA+4, SOL+3, FA+6, 0+2,  
  /* */
};

int pos;
int note;

void setup() {
  pos = 0;
  Serial.begin(9600);  
}

void loop() {

   int analorReading = analogRead(ANALOG_IN);
   int velocity = map(analorReading, 0, 1023, 1, 5);
   Serial.print(velocity);
   Serial.println();
   size_t size = sizeof(song)/sizeof(song[0]);
   int note = song[pos] / 10;
   int duration = max(1,(song[pos] % 10)) * 400;
   tone(BUZZER_OUT, note * octave, duration / velocity + 10);
   delay(duration / velocity );

   pos++;
   if (pos >= size){
    pos = 0;
   }
  
}
