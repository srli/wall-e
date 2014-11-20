#include "BMSerial.h"

//Standard serial command syntax:
/* one byte controls both motors, so 
1 to 127 : channel 1 (1 = full reverse, 64 = neutral, 127 = full fwd)
128 to 255 : channel 2 (128 = full rev, 192 = neutral, 255 = full fwd)

Ensure Roboclaw is on mode 5, option 4

Plug in S1 on robo claw into UART TX (pin 0 is RX, 1 is TX on Arduino)
Connect the 5V and GND from the microcontroller to the roboclaw.

*/
BMSerial serialcomm(0,1); //connect to RX and TX pins

void setup() {
  serialcomm.begin(38400); //set baud rate
}

void loop() {
  serialcomm.write(1);
  serialcomm.write(-1);
  delay(2000);
  serialcomm.write(127);
  serialcomm.write(-127);
  delay(2000);
}
