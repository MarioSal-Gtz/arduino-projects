// Animated GIF Eye for ESP32-S3-Touch-LCD (Optimized)
// Simplified version for smaller ESP32-S3 boards

#include <SPI.h>
#include <TFT_eSPI.h>       // Install from Arduino IDE Library Manager
#include <AnimatedGIF.h>    // Install from Arduino IDE Library Manager

AnimatedGIF gif;

// Include the eye animation
#include "images/eye8.h"

#define GIF_IMAGE eye8

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(2);       // Adjust rotation (0-3) based on your display
  tft.fillScreen(TFT_BLACK);
  gif.begin(BIG_ENDIAN_PIXELS);

  Serial.println("ESP32-S3 Eye Animation Ready!");
}

void loop() {
  if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw)) {
    Serial.printf("GIF opened: %d x %d\n", gif.getCanvasWidth(), gif.getCanvasHeight());
    tft.startWrite();
    while (gif.playFrame(true, NULL)) {
      yield();
    }
    gif.close();
    tft.endWrite();
  }
}
