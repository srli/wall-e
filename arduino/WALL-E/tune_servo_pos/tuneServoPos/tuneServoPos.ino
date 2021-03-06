
#include <VarSpeedServo.h>

VarSpeedServo rArm;

int pos = 90; //stores servo position; set at neutral = 90 deg

void setup(){
    Serial.begin(9600);
    rArm.attach(5);
    rArm.write(90,255,true);

}

void loop() {
    if (Serial.available() > 0){
        int inByte = Serial.read();

        switch(inByte){
        case 'i':
            pos +=1;
            Serial.println("increment");
            break;
        case 'l':
            pos -=1;
            Serial.println("decrement");
            break;
        default:
            pos = 90;
            Serial.println("neutral");
        }
        rArm.write(pos);
        Serial.print(pos);
    }
}
