# Arduino Projects Collection

Colección de proyectos y librerías para desarrollo con ESP32, enfocados en displays TFT y animaciones gráficas.

## 📁 Contenido del Repositorio

### 🎨 Sketches (Proyectos Arduino)

- **01-07**: Proyectos demostrativos con displays circulares
  - Text and Number Display
  - Shapes on Circular Display
  - Animated Eyes (múltiples variantes)
  - Image Display
  - Clock

- **Animated GIF Memory**: Proyectos para mostrar GIFs animados
  - Variante para ESP32-S3
  - Optimizado para displays pequeños

- **Libraries**: Librerías personalizadas para los proyectos

### 📚 TFT_eSPI170

Librería completa TFT_eSPI para displays TFT con ESP32. Incluye:

- **Soporte para múltiples controladores**: ILI9341, ILI9488, ST7789, GC9A01, y más
- **Drivers optimizados** para ESP32, ESP32-S3, ESP32-C3, ESP8266, RP2040, STM32
- **Fuentes personalizadas** (GFXFF, TrueType, Custom)
- **Ejemplos extensos** organizados por resolución de pantalla
- **Extensiones**: Sprites, botones, fuentes suavizadas, touch

## 🔧 Hardware Compatible

- **ESP32** (todas las variantes)
- **ESP32-S3** ⭐ (recomendado para proyectos con GIF)
- **ESP32-C3**
- **RP2040**
- **Displays TFT**: 0.71", 1.3", 1.54", 2.0", 2.4", 2.8", 3.5", etc.

## 🚀 Comenzar

### Requisitos

1. **Arduino IDE** (versión 1.8.x o 2.x)
2. **Soporte para ESP32**:
   ```
   File > Preferences > Additional Board Manager URLs:
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
3. **Instalar placas ESP32**:
   ```
   Tools > Board > Boards Manager > buscar "ESP32" > Install
   ```

### Instalación de TFT_eSPI

**Opción 1: Manual (recomendado para este repo)**
```bash
# Copiar la carpeta TFT_eSPI170 a tu carpeta de librerías Arduino
cp -r TFT_eSPI170 ~/Documents/Arduino/libraries/
```

**Opción 2: Library Manager**
```
Sketch > Include Library > Manage Libraries > buscar "TFT_eSPI"
```

### Configuración de TFT_eSPI

Antes de usar, debes configurar tu pantalla:

1. Abre `TFT_eSPI170/User_Setup.h`
2. Comenta/descomenta la sección de tu pantalla
3. Configura los pines según tu hardware

O usa los setup preconfigurados en `User_Setups/`:
- `Setup70b_ESP32_S3_ILI9341.h`
- `Setup206_LilyGo_T_Display_S3.h`
- `Setup200_GC9A01.h` (pantallas circulares)
- Y muchos más...

## 📖 Uso de los Sketches

### Ejemplo Básico

1. Abre Arduino IDE
2. File > Open > selecciona un sketch de la carpeta `sketches/`
3. Configura tu placa: Tools > Board > ESP32 > ESP32S3 Dev Module
4. Conecta tu ESP32
5. Upload

### Proyectos Destacados

#### 🎨 Animated Eyes
```bash
sketches/03_Animated_Eye1/
sketches/04_Animated_Eye2/
sketches/05_Animated_Eye12/
```
Animaciones de ojos realistas con parpadeo y seguimiento.

#### 🕐 Clock
```bash
sketches/07_Clock/
```
Reloj analógico con manecillas animadas.

#### 🖼️ GIF Player
```bash
sketches/animated_gif_memory_esp32s3/
```
Reproduce GIFs animados desde memoria. Requiere ESP32-S3 con PSRAM.

## 🎯 Ejemplos de TFT_eSPI

La librería incluye +100 ejemplos organizados por resolución:

### 160x128 (Pantallas pequeñas)
- Clock, Rainbow, Print Test, Graphics Test

### 320x240 (Pantallas medianas)
- Keypad, Mandelbrot, Matrix, Pie Chart, Terminal
- Free Fonts Demo, String Align

### 480x320 (Pantallas grandes)
- 3D Cube, Graph, Touch Controller Demo
- Ring Meter, Cellular Automata

### Ejemplos Especiales
- **DMA Test**: Optimizaciones con DMA (Bouncy Circles, Boing Ball)
- **GUI Widgets**: Botones, sliders, gráficas, medidores
- **Generic**: Ojos animados, gradientes, fuentes locales

## ⚡ Optimización

### Para ESP32-S3
- Usar PSRAM para buffers grandes
- DMA para transferencias rápidas
- 16-bit parallel mode para máximo rendimiento

### Configuración recomendada en Arduino IDE:
```
Tools >
  Board: "ESP32S3 Dev Module"
  USB CDC On Boot: "Enabled"
  PSRAM: "OPI PSRAM"
  Flash Size: "16MB (128Mb)"
  Partition Scheme: "16M Flash (3MB APP/9.9MB FATFS)"
```

## 📝 Notas Importantes

- **User_Setup.h**: Siempre configura según tu hardware antes de compilar
- **Memoria**: Los GIFs requieren mucha RAM, usa ESP32-S3 con PSRAM
- **Velocidad SPI**: Puedes ajustar en User_Setup.h (hasta 80MHz en algunos ESP32)
- **Rotación**: Usa `tft.setRotation(x)` donde x = 0, 1, 2, o 3

## 🐛 Troubleshooting

**Pantalla blanca o sin respuesta:**
- Verifica las conexiones de pines
- Revisa la configuración en User_Setup.h
- Prueba con ejemplo básico primero

**Error de compilación:**
- Asegúrate de tener TFT_eSPI instalada correctamente
- Verifica la versión de ESP32 board support (recomendado 2.0.x)

**Colores invertidos:**
- Cambia `#define TFT_INVERSION_ON` a `OFF` (o viceversa)

## 🔗 Recursos

- [TFT_eSPI GitHub Original](https://github.com/Bodmer/TFT_eSPI)
- [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
- [ESP32-S3 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-s3_datasheet_en.pdf)

## 📄 Licencia

- **Sketches propios**: Uso libre
- **TFT_eSPI**: Ver licencia en TFT_eSPI170/license.txt

## 🤝 Contribuir

¡Las contribuciones son bienvenidas! Si tienes un sketch interesante:

1. Fork el proyecto
2. Crea tu rama (`git checkout -b feature/CoolSketch`)
3. Commit tus cambios (`git commit -m 'Add cool sketch'`)
4. Push (`git push origin feature/CoolSketch`)
5. Abre un Pull Request

## 📧 Contacto

Para preguntas o soporte sobre los proyectos, abre un issue en GitHub.

---

⚡ Desarrollado con ESP32 y mucha cafeína ☕
