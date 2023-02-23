/*!
 * @file Datarecorder.ino
 * @brief Three-axis AccelerationRecorder
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @author Pai Da Xing
 * @version  V1.0
 * @date  2023-2-20
 * @url 
 */
#include <Arduino.h>
#include "SD.h"
#include "DFRobot_ICG20660L.h"
#ifdef ARDUINO_BBC_MICROBIT
#define CS_PIN 4
#else
#define CS_PIN 4
#endif
DFRobot_ICG20660L_SPI icg(/*csPin=*/CS_PIN, &SPI);

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_MOSI D7
#define OLED_CLK D5
#define OLED_DC D2
#define OLED_CS D10
#define OLED_RESET D3

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
                         OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);




void setup() {

  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  if (!SD.begin()) {
    Serial.print(".");
  }
  while (!Serial) {
  }
  Serial.print("Initialization sensor...");
  while (icg.begin(/*mode=*/icg.eRegMode) != 0) {
    Serial.println("failed. Please check whether the hardware connection is wrong.");
    delay(1000);
    Serial.print("Initialization sensor...");
  }
  Serial.println("done.");
  Serial.print("ICG20660L Device ID: 0x");
  Serial.println(icg.readID(), HEX);
  icg.enableSensor(icg.eAccelAxisXYZ);
  icg.configAccel(icg.eFSR_A_16G, icg.eAccel_DLPF_99_1KHZ);
  icg.setSampleDiv(19);
}


void loop() {

  String directionx = String(icg.getAccelDataX());
  String directiony = String(icg.getAccelDataY());
  String directionz = String(icg.getAccelDataZ());
  String runningtime = String(millis() / 1000);

  const char* directionsx = directionx.c_str();
  const char* directionsy = directiony.c_str();
  const char* directionsz = directionz.c_str();
  const char* runningtimes = runningtime.c_str();

  File file = SD.open("/tess.csv", FILE_APPEND);
  file.printf(directionsx);
  file.printf(",");
  file.printf(directionsy);
  file.printf(",");
  file.printf(directionsz);
  file.printf(",");
  file.printf(runningtimes);
  file.printf(",\r\n");
  file.close();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(6, 0);
  display.println("X:");
  display.setCursor(28, 0);
  display.println(directionsx);
  display.setCursor(92, 0);
  display.println("g");

  display.setCursor(6, 21);
  display.println("Y:");
  display.setCursor(28, 21);
  display.println(directionsy);
  display.setCursor(92, 21);
  display.println("g");

  display.setCursor(6, 42);
  display.println("Z:");
  display.setCursor(28, 42);
  display.println(directionsz);
  display.setCursor(92, 42);
  display.println("g");
  display.display();

  delay(500);
}
