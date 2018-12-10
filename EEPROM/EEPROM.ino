#include <EEPROM.h>
#include <Time.h>

int read, idx;
int address = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  read = EEPROM.read(address);
  Serial.print("Last value: ");
  Serial.println(read);
  while(true){
    time_t timer = time(null);
    Serial.println(timer);
    EEPROM.write(address, timer );
    break;
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
