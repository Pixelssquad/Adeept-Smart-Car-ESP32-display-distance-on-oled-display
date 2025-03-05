/**********************************************************************
  Description : Ultrasonic ranging.
  Auther      : www.Adeept.com
  Modification: 2025/03/05 by Pellacani "Diegooz" Diego - Added Oled distance display
**********************************************************************/
#include <Arduino.h>
#include "Adeept_Ultrasonic_For_ESP32.h"

#include <Wire.h>
#include <SSD1306Wire.h>

// OLED pin definition.
#define SDA   13
#define SCL   14
SSD1306Wire OLED_display(0x3c, SDA, SCL);


float distance;

void setup() {
  Serial.begin(115200);//Open the serial port and set the baud rate to 115200
  Ultrasonic_Setup();  //Ultrasonic module initialization.
  OLED_display.init(); // Initialize the OLED.
  OLED_display.flipScreenVertically();  // The screen flips 180° to display.
}

void loop() {
  distance = Get_Sonar();  // get ultrasonic distance value.
  Serial.print("Distance: " + String(distance) + " cm\n");//Print ultrasonic distance
  
  OLED_display.clear();  // clear screen.
    OLED_display.setFont(ArialMT_Plain_16);  // set font size 10,16,24.
    OLED_display.drawString(20, 10, "ESP32 Car");
    OLED_display.setFont(ArialMT_Plain_16);  // set font size 10,16,24.
    OLED_display.drawString(0, 30, "Dist:" + String(distance)+ " cm\n" );    
    OLED_display.setFont(ArialMT_Plain_10);
    OLED_display.drawString(20,50,"www.adeept.com");
    OLED_display.display(); // display characters.
    delay(500);
}
