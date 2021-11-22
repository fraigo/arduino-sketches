/*
 * LED Display A1602 Example using library
 * 
 * LED Display connections:
 * 1 (VSS) to GND
 * 2 (VDD) to +5V
 * 3 (V0) to Potentiometer center (lcd matrix brightness)
 * 4 (RS) to pin 12 (Digital i/o)
 * 5 (RW) to GND
 * 6 (E) to pin 11 (Digital i/o)
 * 11 (D4) to pin 5
 * 12 (D5) to pin 4
 * 13 (D6) to pin 3
 * 14 (D7) to pin 2
 * 15 (A) to +5V through resistor 
 * 16 (K) to GND
 * 
 * Potentiometer:
 * End1 to +5V
 * End2 to GND
 * 
 * See also: 
 * https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/
 */

// include the library code:
#include <LiquidCrystal.h>

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Clears the LCD screen
  lcd.clear();
}

void loop() 
{
  
  // set the cursor to column 0, line 0 (first line)
  lcd.setCursor(0, 0);
  // Print a message to the LCD.
  lcd.print("Hello World");

  // set the cursor to column 0, line 1 (second line)
  lcd.setCursor(0, 1);
  // Get time elapsed (minutes/seconds/msec)
  long time = millis();
  long sec = (time / 1000) % 60;
  long mins = (time / 60000);
  char msg[16];
  // format message 00:00.000
  sprintf(msg,"%02ld:%02ld.%03ld",mins,sec,time%1000);
  lcd.print(msg);
}
