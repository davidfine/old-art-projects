

#include "WProgram.h"
void setup();
void loop();
int ADC0;
int ADC1;

void setup(){

Serial.begin(57600);
}

void loop(){
delay(500);
  ADC0 = analogRead(0); //Send reading from Analog Pin 0 once each round.
  ADC0 = map(ADC0,0,1023,0,63);
  Serial.print(ADC0,BYTE);  //Flag bits already 00 
delay(500);
ADC1 = analogRead(1); //Send reading from Analog Pin 1 once each round.
 ADC1 = map(ADC1,0,1023,0,63);
 Serial.print(ADC1|64,BYTE);  //This time we bitwise 'or' with 64 to set the flag bits to 01xxxxxx
}
int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

