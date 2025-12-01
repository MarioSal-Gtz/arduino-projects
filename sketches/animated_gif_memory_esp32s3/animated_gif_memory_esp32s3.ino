// ===================================================================
// Animated GIF Player for ESP32-S3-Touch-LCD-1.28
// ===================================================================
// Hardware: ESP32-S3 with 1.28" Round Display (240x240)
// Display Driver: GC9A01A
// Touch: CST816S
//
// IMPORTANTE: Configura TFT_eSPI con estos pines en User_Setup.h:
// #define TFT_MOSI 11
// #define TFT_SCLK 10
// #define TFT_CS   9
// #define TFT_DC   8
// #define TFT_RST  14
// #define TFT_BL   2
//
// Board Manager: esp32 by Espressif Systems versión 2.0.13
// ===================================================================

#include <SPI.h>
#include <TFT_eSPI.h>     // Install this library with the Arduino IDE Library Manager
                          // Don't forget to configure the driver for the display!

#include <AnimatedGIF.h>  // Install this library with the Arduino IDE Library Manager
AnimatedGIF gif;

 
#include "images/eye8.h"

// Uncomment the image to display
// You could run out of program memory if you load more than one image
// You can also increase the program memory by changing the partition of the ESP32
// See this tutorial to increase program memory: https://youtu.be/NTbiKssK8_8
//
//#define GIF_IMAGE colortest
// #define GIF_IMAGE hyperspace
#define GIF_IMAGE eye8
// #define GIF_IMAGE nostromo
// #define GIF_IMAGE darthvader
// #define GIF_IMAGE hud_1
// #define GIF_IMAGE hud_2
// #define GIF_IMAGE hud_5
// #define GIF_IMAGE hud_6
// #define GIF_IMAGE hud_7
// #define GIF_IMAGE x_wing

// SERVO DESACTIVADO - Descomentar si necesitas usar servo
// #include <ESP32Servo.h>
// Servo myservo;
// int pos = 0;
// int servoPin = 21;
 
TFT_eSPI tft = TFT_eSPI();
void setup() {
  // SERVO DESACTIVADO - Descomentar si necesitas
  // ESP32PWM::allocateTimer(0);
  // ESP32PWM::allocateTimer(1);
  // ESP32PWM::allocateTimer(2);
  // ESP32PWM::allocateTimer(3);
  // myservo.setPeriodHertz(50);
  // myservo.attach(servoPin, 1000, 2000);

  Serial.begin(115200);
  delay(500); // Esperar a que inicie el serial
  Serial.println("Iniciando ESP32-S3-Touch-LCD-1.28...");
  Serial.println("Display: GC9A01 240x240 Round");

  tft.begin();
  tft.setRotation(0);     // Adjust Rotation of your screen (0-3)
  tft.fillScreen(TFT_BLACK);
  // tft.setSwapBytes(true);
  gif.begin(BIG_ENDIAN_PIXELS);

  Serial.println("Display inicializado!");
}

void loop()
{
  Serial.println("Intentando abrir GIF...");

  if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw))
  {
    Serial.printf("GIF abierto! Tamaño: %d x %d\n", gif.getCanvasWidth(), gif.getCanvasHeight());
    tft.startWrite();
    while (gif.playFrame(true, NULL))
    {
      yield(); // Importante para el watchdog
    }
    gif.close();
    tft.endWrite();
    Serial.println("GIF terminado, reiniciando...");
  }
  else
  {
    Serial.println("ERROR: No se pudo abrir el GIF!");
    delay(5000); // Esperar 5 segundos antes de reintentar
  }

  delay(100); // Pequeño delay entre loops
}