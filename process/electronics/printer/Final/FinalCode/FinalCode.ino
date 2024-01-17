
#include "Adafruit_Thermal.h"

#include "poem00.h"
#include "poem01.h"
#include "poem02.h"
#include "poem03.h"
#include "poem04.h"
#include "poem05.h"
#include "poem06.h"
#include "poem07.h"

#include "SoftwareSerial.h"
#define TX_PIN 11
#define RX_PIN 10

SoftwareSerial mySerial(RX_PIN, TX_PIN);  // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);      // Pass addr to printer constructor


#define poems_width 384
#define poems_height 550




void setup() {

  mySerial.begin(9600);  // Initialize SoftwareSeria

  printer.begin();  // Init printer (same regardless of serial type)

  // ajouter une ligne

  printer.println();

  // printer.feed(2);

  // //randomSeed(analogRead(0));
  // uint8_t index = random(1);  // le nombre de poemes
  // // en fonction de la valeur choisie aleatoirement
  // switch (index) {
  //   case 0:
  //     // imprimer ce poeme
  //     printer.printBitmap(poems_width, poems_height, poem07_data);
  //     break;  // fin des instructions
  //   // case 1:
  //   //   printer.printBitmap(poems_width, poems_height, poem01_data);
  //   //   break;
  //   // case 2:
  //   //   printer.printBitmap(poems_width, poems_height, poem02_data);
  //   //   break;
  //   // case 3:
  //   //   printer.printBitmap(poems_width, poems_height, poem03_data);
  //   //   break;
  //   // case 4:
  //   //   printer.printBitmap(poems_width, poems_height, poem04_data);
  //   //   break;
  //   // case 5:
  //   //   printer.printBitmap(poems_width, poems_height, poem05_data);
  //   //   break;
  //   // case 6:
  //   //   printer.printBitmap(poems_width, poems_height, poem06_data);
  //   //   break;
  //   // case 7:
  //   //   printer.printBitmap(poems_width, poems_height, poem07_data);
  //   //   break;
  //   default:
  //     break;
  // }


  printer.printBitmap(poems_width, poems_height, poem07_data);  //poem00 pour la demo




  // ajouter une ligne
  printer.println();

  // gros espace
  printer.feed(10);

  printer.sleep();       // Tell printer to sleep
  delay(3000L);          // Sleep for 3 seconds
  printer.wake();        // MUST wake() before printing again, even if reset
  printer.setDefault();  // Restore printer to defaults
}

void loop() {
}
