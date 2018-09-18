/*
 * 1-Digit led segment display controller
 * Author: Francisco Igor
 * Email : franciscoigor@gmail.com
 * 
 * Function:
 * Prints led display digits from 0 to 9 using an array of on/off pins
 * 
 * Components:
 *  - 1-Digit led display (10 pin, pin 3 & 8 common cathode)
 *  - Display Pins 3 and 8 (common cathode) connected to a 1K resistance
 *  - 1k resistance connected to GND
 *  - Pins 1,2,4 connected to D3, D4, D5 (lower display Segments)
 *  - Pins 10, 9, 7, 6 connected to D6, D7, D8, D9 (upper display segments)
 *  - Optionally (not used), pin 6 connected to D10 (decimal point)
 *  
 *  Led display pins:
 *  
 *      *
 *      * 
 * 10-9-8-7-6 
 *  | | | | |
 *   ooooooo
 *  o       o
 *  o       o
 *   ooooooo
 *  o       o
 *  o       o
 *   ooooooo  o
 *  | | | | |
 *  1-2-3-4-5  
 *      *
 *      *
 */
int a[10][10]={
               {0,0,0,1,1,1,0,1,1,1},  //0
               {0,0,0,0,0,1,0,0,0,1},  //1
               {0,0,0,1,1,0,1,0,1,1},  //2
               {0,0,0,0,1,1,1,0,1,1},  //3
               {0,0,0,0,0,1,1,1,0,1},  //4
               {0,0,0,0,1,1,1,1,1,0},  //5
               {0,0,0,1,1,1,1,1,1,0},  //6
               {0,0,0,0,0,1,0,0,1,1},  //7
               {0,0,0,1,1,1,1,1,1,1},  //8
               {0,0,0,0,1,1,1,1,1,1},};//9  
void setup(){  
  for (int i=3;i<=9;i++) {  
    pinMode(i,OUTPUT);  
  }  
  Serial.begin(9600);
}  

/**
 * printnum: prints a number in the led segment display
 * parameters:
 *  - num  : digit to print (0-9)
 *  - dly  : delay to apply by segment
 *  - onoff: enabled or disabled mode 
 */
void printnum(int num, int dly, int onoff){  
  for (int i=3;i<=9;i++){  
    digitalWrite(i,a[num][i]*onoff);  
    if (a[num][i]==1){
      delay(dly);
    }
  }  
}  

void loop(){  
  for (int i=0;i<=9;i++){  
    printnum(i, 50, 1);  
    delay(500); 
    printnum(i, 30, 0); 
    delay(500);  
  }  
}  
