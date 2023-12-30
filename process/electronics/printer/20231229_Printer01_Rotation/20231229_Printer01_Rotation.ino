// #include "Adafruit_Thermal.h"
// #include "SoftwareSerial.h"
// #define TX_PIN 5 // Arduino transmit  YELLOW WIRE  labeled RX on printer
// #define RX_PIN 6 // Arduino receive   GREEN WIRE   labeled TX on printer

// SoftwareSerial mySerial(RX_PIN, TX_PIN); 
// Adafruit_Thermal printer(&mySerial); 

// long randStart;

// void setup (){
// mySerial.begin(19200);

// }

// void loop(){

// randStart = random(1,19);

// //1B 24 nL nH

// //mySerial.print("\x1B\x0E"); // wide font
// //mySerial.print("\x1B\x0E"); // wide font
// mySerial.println();
// //mySerial.println("\x1B\x56\x01"); // 90 deg rotation
// //mySerial.print("\x1B\x42\x01"); // set left position = 01 is min
// mySerial.print("\x1B\x42\randStart");
// mySerial.println("Hello");



// mySerial.print("\x1B\x42\x19"); // 19 is max
// //mySerial.print("\x1B\x14"); // normal font
// mySerial.println("Suka");
// mySerial.println();
// mySerial.println();
// delay(10000);



// }


#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN 5 // Arduino transmit YELLOW WIRE labeled RX on printer
#define RX_PIN 6 // Arduino receive GREEN WIRE labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor



void setup() {
  mySerial.begin(19200);  // Initialize SoftwareSerial
  printer.begin();        // Init printer

}

void loop() {
  // Set a random left position (between 1 and 18 characters from the original position)
  int randStart = random(1, 19);
  int randRot = random(0,90);

  // Print text at the specified left position
  setLeftPosition(randStart);
  setRandomRotation(randRot);
  printer.println("Hello, world!");

  // Delay for a while
  delay(200); // Adjust the delay as needed
}

void setLeftPosition(int n) {
  // Set left position using escape code sequence: ESC B n
  mySerial.write(27); // ESC
  mySerial.write('B'); // B
  mySerial.write(n);  // n (distance in characters)
}

void setRandomRotation(int n) {
  // Set left position using escape code sequence: ESC B n
  mySerial.write(27); // ESC
  mySerial.write('V'); // 
  mySerial.write(n);  // n 
}

// //mySerial.println("\x1B\x56\x01"); // 90 deg rotation