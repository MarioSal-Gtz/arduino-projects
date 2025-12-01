# Eye Animation para ESP32-S3-Touch-LCD (Optimizado)

Versión optimizada para placas ESP32-S3 pequeñas.

## Optimizaciones realizadas:
- ✅ Eliminado código del servo (ESP32Servo)
- ✅ Reducido BUFFER_SIZE de 1024 a 256 bytes
- ✅ Eliminado DMA (no necesario para pantalla pequeña)
- ✅ Código más limpio y simple
- ✅ Menor uso de memoria flash y RAM

## Librerías necesarias:
1. TFT_eSPI (configura para tu pantalla en User_Setup.h)
2. AnimatedGIF

## Para usar:
1. Abre `eye_esp32s3_small.ino` en Arduino IDE
2. Configura TFT_eSPI para tu pantalla
3. Sube el código a tu ESP32-S3-Touch-LCD

## Notas:
- El GIF `eye8.h` ya está incluido en la carpeta images/
- Ajusta `tft.setRotation(2)` si necesitas rotar la pantalla
- Si tu ESP32-S3 tiene memoria limitada, este código debería funcionar bien

## Proyecto original guardado en:
`animated_gif_memory-RESPALDO-20251103/`
