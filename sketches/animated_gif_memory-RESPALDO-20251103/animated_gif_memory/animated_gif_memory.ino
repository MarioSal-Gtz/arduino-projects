// Animated GIF with Round Display
//
// ESP32 40MHz SPI single frame rendering performance

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
// #define GIF_IMAGE colortest
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
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42
// Possible PWM GPIO pins on the ESP32-S3: 0(used by on-board button),1-21,35-45,47,48(used by on-board LED)
// Possible PWM GPIO pins on the ESP32-C3: 0(used by on-board button),1-7,8(used by on-board LED),9-10,18-21
 
int servoPin = 21;
 
TFT_eSPI tft = TFT_eSPI();
void setup() {
  	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	myservo.setPeriodHertz(50);    // standard 50 hz servo
	myservo.attach(servoPin, 1000, 2000); 
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(2);     // Adjust Rotation of your screen (0-3)
  tft.fillScreen(TFT_BLACK);
  // tft.setSwapBytes(true);
  gif.begin(BIG_ENDIAN_PIXELS);
}

void loop()
{
  // for (pos = 30; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
	// 	// in steps of 1 degree
	// 	myservo.write(pos);    // tell servo to go to position in variable 'pos'
	// 	delay(15);             // waits 15ms for the servo to reach the position
	// }
  if (gif.open((uint8_t *)GIF_IMAGE, sizeof(GIF_IMAGE), GIFDraw))
  {
    Serial.printf("Successfully opened GIF; Canvas size = %d x %d\n", gif.getCanvasWidth(), gif.getCanvasHeight());
    tft.startWrite();
    while (gif.playFrame(true, NULL))
    {
      yield();
    }
    gif.close();
    tft.endWrite(); 
  }
  //   tft.fillScreen(TFT_BLACK);

 
  // for (pos = 100; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
	// 	myservo.write(pos);    // tell servo to go to position in variable 'pos'
	// 	delay(15);             // waits 15ms for the servo to reach the position
	// }
  // delay(2000);
}