# Animated GIF for ESP32-S3-Touch-LCD-1.28

Proyecto configurado para **ESP32-S3-Touch-LCD-1.28** (Waveshare)

## 🔧 Hardware
- **Board**: ESP32-S3-Touch-LCD-1.28
- **Display**: GC9A01A (240x240 Round LCD)
- **Touch**: CST816S (I2C)
- **IMU**: QMI8658 (opcional)

## 📌 GPIO Pinout (Display SPI)

| Pin Function | GPIO |
|--------------|------|
| TFT_MOSI     | 11   |
| TFT_SCLK     | 10   |
| TFT_CS       | 9    |
| TFT_DC       | 8    |
| TFT_RST      | 14   |
| TFT_BL       | 2    |

## ⚙️ Configuración TFT_eSPI

Edita el archivo `User_Setup.h` en la carpeta de TFT_eSPI y agrega:

```cpp
#define GC9A01_DRIVER

#define TFT_WIDTH  240
#define TFT_HEIGHT 240

#define TFT_MOSI 11
#define TFT_SCLK 10
#define TFT_CS   9
#define TFT_DC   8
#define TFT_RST  14
#define TFT_BL   2

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF

#define SMOOTH_FONT

#define SPI_FREQUENCY  80000000
```

## 📦 Arduino IDE - Board Manager

**IMPORTANTE**: Usa **esp32 by Espressif Systems versión 2.0.13**

1. File → Preferences → Additional Board Manager URLs:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```

2. Tools → Board → Boards Manager → busca "esp32" e instala versión **2.0.13**

3. Tools → Board → ESP32 Arduino → **ESP32S3 Dev Module**

## 📚 Librerías Requeridas

1. **TFT_eSPI** (by Bodmer)
2. **AnimatedGIF** (by Larry Bank)

## 🎨 Uso

El código muestra GIFs animados guardados en memoria del programa. Los archivos .h con los GIFs están en la carpeta `images/`.

Para cambiar el GIF, edita la línea:
```cpp
#define GIF_IMAGE eye6
```

![Usage](https://github.com/thelastoutpostworkshop/animated_gif_memory/blob/main/images/doc/Animated%20GIF.png)