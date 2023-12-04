#include <Adafruit_Thermal.h>

//#include "tc_01.h"
//#include "tc_02.h"
//#include "tc_04.h"
//#include "tc_06.h"
//#include "tc_08.h"

// Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
// If using hardware serial instead, comment out or remove these lines:

#include <SoftwareSerial.h>
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor
// Then see setup() function regarding serial & printer begin() calls.

// Here's the syntax for hardware serial (e.g. Arduino Due) --------------
// Un-comment the following line if using hardware serial:

//Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.

// -----------------------------------------------------------------------

void setup() {
  randomSeed(analogRead(5));

  // This line is for compatibility with the Adafruit IotP project pack,
  // which uses pin 7 as a spare grounding point.  You only need this if
  // wired up the same way (w/3-pin header into pins 5/6/7):
  pinMode(7, OUTPUT); digitalWrite(7, LOW);

  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
  mySerial.begin(19200);  // Initialize SoftwareSerial
  //Serial1.begin(19200); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)
  //start serial connection
  Serial.begin(9600);
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);

}

void loop() {
  //read the pushbutton value into a variable
  int sensorVal = digitalRead(2);
  //print out the value of the pushbutton
  Serial.println(sensorVal);

  // Keep in mind the pullup means the pushbutton's
  // logic is inverted. It goes HIGH when it's open,
  // and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (sensorVal == LOW) {
    digitalWrite(13, LOW);
  int image = random(5);
  //if (image == 0) printer.printBitmap(tc1_width, tc1_height, tc1_data);
  //if (image == 1) printer.printBitmap(tc_02_width, tc_02_height, tc_02_data);
  //if (image == 2) printer.printBitmap(tc_04_width, tc_04_height, tc_04_data);
  //if (image == 3) printer.printBitmap(tc_06_width, tc_06_height, tc_06_data);
  //if (image == 4) printer.printBitmap(tc_08_width, tc_08_height, tc_08_data);
  
  printer.println(F(" "));
  printer.justify('C');
  printer.boldOn();
  printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
  printer.println(F("Type]Media "));

  printer.println(F("TypeCooker @ Open Day 2022"));
  printer.boldOff();
  
  printer.justify('L');

  printer.println(F(" "));
  printer.setSize('S');
  int weightValue = random(3);
  if (weightValue == 0) {
      printer.boldOn();
      printer.println(F("Weight: Light"));
      printer.boldOff();
      printer.println(F("All strokes are light,\nbut not extremely."));    
   }

  if (weightValue == 1) {
      printer.boldOn();
      printer.println(F("Weight: Plain"));
      printer.boldOff();
      printer.println(F("All strokes are plain. Not\ntoo light, not too heavy."));    
   }   

  if (weightValue == 2) {
      printer.boldOn();
      printer.println(F("Weight: Bold"));
      printer.boldOff();
      printer.println(F("All strokes are heavy."));    
   } 

  printer.println(F(" "));

  int widthtValue = random(3);
  if (widthtValue == 0){
      printer.boldOn();
      printer.println(F("Width: Narrow"));
      printer.boldOff();
      printer.println(F("Not much overall width."));     
    }
  if (widthtValue == 1){
      printer.boldOn();
      printer.println(F("Width: Normal"));
      printer.boldOff();;
      printer.println(F("A normal width."));     
    }
  if (widthtValue == 2){
      printer.boldOn();
      printer.println(F("Width: Extended"));
      printer.boldOff();
      printer.println(F("The overall width is larger than\nnormal. (But what is normal)"));     
    }

  printer.println(F(" "));

  int strokeValue = random(2);
  if (strokeValue == 0){
      printer.boldOn();
      printer.println(F("Stroke Endings: Straight,NoSerif"));
      printer.boldOff();
      printer.println(F("The strokes do not end in serifs"));     
    }
  if (strokeValue == 1){
      printer.boldOn();
      printer.println(F("Stroke Endings: Serifs"));
      printer.boldOff();
      printer.println(F("The strokes end in serifs."));     
    }


  printer.println(F(" "));

  int constructionValue = random(2);
  if (strokeValue == 0){
      printer.boldOn();
      printer.println(F("Constructions: Roman"));
      printer.boldOff();
      printer.println(F("Construct the letters as\nlowercase romans."));     
    }
  if (strokeValue == 1){
      printer.boldOn();
      printer.println(F("Constructions: Capitals"));
      printer.boldOff();
      printer.println(F("Construct the letters as\ncapitals."));     
    }

  printer.println(F(" "));

  int contrastAmountValue = random(2);
  if (strokeValue == 0){
      printer.boldOn();
      printer.println(F("Contrast Amount: Low"));
      printer.boldOff();
      printer.println(F("Thicks are similar to thins."));     
    }
  if (strokeValue == 1){
      printer.boldOn();
      printer.println(F("Contrast Amount: Some"));
      printer.boldOff();
      printer.println(F("Thicks are similar to thins\nbut you can tell the difference."));     
    }
  if (strokeValue == 2){
      printer.boldOn();
      printer.println(F("Contrast Amount: A lot"));
      printer.boldOff();
      printer.println(F("Thicks are a lot thicker than the thins."));     
    }
    
  printer.println(F(" "));

  printer.println(F("www.typemedia.org"));
  printer.println(F(" "));
  printer.println(F(" "));
  printer.println(F(" "));
  printer.println(F(" "));
  printer.setDefault(); // Restore printer to defaults

    delay(5000);   
    
  }
}
