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

#define TX_PIN 5  // Arduino transmit YELLOW WIRE labeled RX on printer
#define RX_PIN 6  // Arduino receive GREEN WIRE labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN);  // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);      // Pass addr to printer constructor



void setup() {
  mySerial.begin(19200);  // Initialize SoftwareSerial
  printer.begin();        // Init printer
}

void loop() {
  // Print each letter with a random left position and rotated by 90 degrees
  String text = "Hello, world!";
  for (int i = 0; i < text.length(); i++) {
    int randStart = random(25, 47);
    int rotLetter = 1.49;

    setRotateLetter(rotLetter);
    setLeftPosition(randStart);
    printer.setSize('L'); 
    // Print the current letter
    printer.print(text[i]);
    printer.println();  // Move to the next line
    delay(200);         // Adjust the delay as needed
  }
}

void setLeftPosition(int n) {
  // Set left position using escape code sequence: ESC B n
  mySerial.write(27);   // ESC
  mySerial.write('B');  // B
  mySerial.write(n);    // n (distance in characters)
}

void setRotateLetter(int n) {
  // Set rotation using escape code sequence: ESC V n
  mySerial.write(27);   // ESC
  mySerial.write('V');  // V
  mySerial.write(n);    // n (rotation in degrees)
}
