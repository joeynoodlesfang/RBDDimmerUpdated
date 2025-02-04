// #include "Arduino.h"
#include <RBDdimmer.h>
#include <SoftwareSerial.h>

// #define USE_SERIAL  SerialUSB // Serial for boards with USB serial port


#define outputPin  PA0
#define zerocross  PA1 // For boards with CHANGEABLE input pins
// TODO: set serial pins as definitions
SoftwareSerial mySerial(PA4, PA5);
String myString = "";

// TODO: add initializations for delay pin..?
dimmerLamp dimmer(outputPin, zerocross); // Initialize dimmer for ESP8266, ESP32, Arduino Due
// dimmerLamp dimmer(outputPin); // Initialize dimmer for MEGA, Leonardo, UNO, Arduino M0, Arduino Zero

int outVal = 0;
int incomingByte = 0; // For incoming serial data

void setup() {
    mySerial.begin(9600);
    dimmer.begin(NORMAL_MODE, ON); // Dimmer initialization: name.begin(MODE, STATE)
    mySerial.println("Dimmer Program is starting...");
    mySerial.println("Set value");
    dimmer.setPower(70);
}

void printSpace(int val) {
    if ((val / 100) == 0) mySerial.print(" ");
    if ((val / 10) == 0) mySerial.print(" ");
}

void loop() {
    int preVal = outVal;

    if (mySerial.available()) {
        int buf = mySerial.read();
        myString += (char)buf;

        if (buf == '\r') {
            int val = myString.toInt();

            // mySerial.print("Setting dimmer value to: ");
            // mySerial.println(val);

            if (val < 101) {
                outVal = val;
            }

            myString = "";
            delay(200);
        }
    }

    dimmer.setPower(outVal); // setPower(0-100%)

    if (preVal != outVal) {
        mySerial.print("lampValue -> ");
        printSpace(dimmer.getPower());
        mySerial.print(dimmer.getPower());
        mySerial.println("%");
    }

    // mySerial.println(dimmer.getMyCounter());
    // delay(95);

    // while (1) {
    //     if (mySerial.available() > 0) {
    //         incomingByte = mySerial.read();
    //         mySerial.print("I received: ");
    //         mySerial.println(incomingByte, DEC);
    //     }
    //     delay(100);
    // }
}
