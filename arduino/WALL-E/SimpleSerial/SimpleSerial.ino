#include "BMSerial.h"

//Arduino Due only supports using hardware uarts, pins 0/1, 14/15, 16/17 or 18/19.

BMSerial mySerial(5,6);

void setup() {
  mySerial.begin(19200);
}

void loop() {
  mySerial.write(50);
  mySerial.write(-50);
  delay(2000);
  mySerial.write(70);
  mySerial.write(-70);
  delay(2000);
}
