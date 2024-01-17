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
  // Print text with a custom font for lowercase 'a' (75x75 px)
  String text = "a";
  for (int i = 0; i < text.length(); i++) {
    printCustomCharacter(text[i]);
    delay(200);  // Adjust the delay as needed
  }
  printer.println();  // Move to the next line
  delay(200);         // Adjust the delay as needed
}

void printCustomCharacter(char c) {

  // Define a custom font for lowercase 'a' (75x75 px)
  const uint8_t customFont[][75] = {
    { // Define custom font for lowercase 'a'
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xf8, 0x07, 0xff, 0xe0,
      0xff, 0xff, 0xff, 0xff, 0xfe, 0x1c, 0xf8, 0x07, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xff,
      0x70, 0x07, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0x30, 0x0f, 0xff, 0xe0, 0xff, 0xff,
      0xff, 0xff, 0xc7, 0xff, 0xb0, 0x0f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xa0, 0x1f,
      0xff, 0xe0, 0xff, 0xff, 0xff, 0xfe, 0x1f, 0xff, 0xa0, 0x1f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xfc,
      0x3f, 0xff, 0xa0, 0x1f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0x80, 0x3f, 0xff, 0xe0,
      0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0x80, 0x3f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff,
      0x80, 0x3f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xe0, 0xff, 0xff,
      0xff, 0x81, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xe0, 0xff, 0xff, 0xff, 0x03, 0xff, 0xff, 0x00, 0xff,
      0xff, 0xe0, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0x00, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xfe, 0x07,
      0xff, 0xfe, 0x00, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xfc, 0x07, 0xff, 0xfe, 0x01, 0xff, 0xff, 0xe0,
      0xff, 0xff, 0xf8, 0x0f, 0xff, 0xfe, 0x01, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xfc,
      0x01, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xe0, 0xff, 0xff,
      0xe0, 0x1f, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xe0, 0x3f, 0xff, 0xf8, 0x07, 0xff,
      0xff, 0xe0, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xc0, 0x3f,
      0xff, 0xf0, 0x07, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x80, 0x7f, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xe0,
      0xff, 0xff, 0x80, 0x7f, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xe0,
      0x0f, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xe0, 0xff, 0xfe,
      0x00, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xe0, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xa0, 0x1f, 0xff,
      0xff, 0xe0, 0xff, 0xfe, 0x00, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xe0, 0xff, 0xfc, 0x00, 0xff,
      0xff, 0x40, 0x3f, 0xff, 0xff, 0xe0, 0xff, 0xfc, 0x00, 0xff, 0xfe, 0x40, 0x7f, 0xff, 0xff, 0xe0,
      0xff, 0xfc, 0x01, 0xff, 0xfe, 0x80, 0x7f, 0xff, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0xfd, 0x80,
      0x7f, 0xef, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0xf9, 0x00, 0xff, 0xcf, 0xff, 0xe0, 0xff, 0xf8,
      0x01, 0xff, 0xfb, 0x00, 0xff, 0xdf, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0xf7, 0x00, 0xff, 0xbf,
      0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0xe6, 0x01, 0xff, 0x3f, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff,
      0xee, 0x01, 0xff, 0x7f, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0xdc, 0x03, 0xfe, 0xff, 0xff, 0xe0,
      0xff, 0xf8, 0x01, 0xff, 0xbc, 0x03, 0xfc, 0xff, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xff, 0x3c, 0x03,
      0xf9, 0xff, 0xff, 0xe0, 0xff, 0xf8, 0x01, 0xfe, 0x78, 0x07, 0xf3, 0xff, 0xff, 0xe0, 0xff, 0xf8,
      0x00, 0xfc, 0xf8, 0x07, 0xe7, 0xff, 0xff, 0xe0, 0xff, 0xf8, 0x00, 0xf9, 0xf8, 0x07, 0xcf, 0xff,
      0xff, 0xe0, 0xff, 0xfc, 0x00, 0x67, 0xf8, 0x07, 0x9f, 0xff, 0xff, 0xe0, 0xff, 0xfe, 0x00, 0x0f,
      0xf8, 0x04, 0x7f, 0xff, 0xff, 0xe0, 0xff, 0xff, 0x00, 0x1f, 0xf8, 0x00, 0xff, 0xff, 0xff, 0xe0,
      0xff, 0xff, 0x80, 0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0}};

  // Map ASCII values to indices in the custom font
  int index = c - 'a';
  if (index >= 0 && index < 26) {
    printer.printBitmap(75, 75, customFont[index]);
  } else {
    // If the character is not in the custom font, print a space
    printer.printBitmap(75, 75, (uint8_t*)"                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      "
                                          "                                      ");
  }
}