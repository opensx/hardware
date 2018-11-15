/*

 SX_Belegt_Ser_84.ino

 (C) Michael Blank, IBM Klub BB Modellbahn
 16 Oct 2018, Rev. 1.1

 collect A/D data from 8 analog inputs with ATtiny84 and sends the 
 (filtered reading) as ASCII text to main-processor, format
 "S04840000\n" (Channel0 first)

 Arduino IDE Settings 
 ATtiny84, 8Mhz internal clock, EEPROM retained, BOD disabled, clockwise Pin-Map.
 Current consumption: ~13mA
 
*/

#include <SendOnlySoftwareSerial.h>
#define TX  8   // Physical 5 / PB2
SendOnlySoftwareSerial serOut(TX);  // , true) // inverted

#define N  8

int inp[N] = { A0, A1, A2, A3, A4, A5, A6, A7 };
uint16_t sum[N] = { 0, 0, 0, 0, 0, 0, 0, 0};
uint16_t tmp = 0;
uint16_t out = 0;

// the setup function runs once when you power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
  serOut.begin(9600);
  analogReference(INTERNAL1V1);
}

// the loop function runs over and over again forever
// aprox. every 100msec here
void loop() {
 
  delay(10);         

  // collect data for the 8 input channels and filter
  // 22k => output value =6 (5..7)
  // 10k => output value =9
  for (int i=0 ; i < N; i++) {
    delay(10);
    tmp = 0;
    for (int j = 0; j < 16; j++) {  
      tmp += analogRead(inp[i]);   // average
    }
    tmp = tmp / 32;  // effectivly dividing by 2
    if (tmp > 12) tmp = 12;  // limit for filter response
    sum[i] = ( 3 * sum[i] + tmp ) / 4;   // LP filter
  }
  
  // output to serial port
  serOut.print('S');
  for (int i=N-1 ; i >= 0; i--) {
    out = sum[i];
    if (out > 9) {
      serOut.print(9);
    } else {
      serOut.print(out);
    }  
  }
  serOut.print('\n');


}
