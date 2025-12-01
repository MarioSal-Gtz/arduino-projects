#include <Servo.h>

// Crear objetos servo
Servo servo1, servo2, servo3, servo4;

// Pines de los servos
int pinServo1 = 2;
int pinServo2 = 3;
int pinServo3 = 4;
int pinServo4 = 5;

// Variables para controlar el movimiento
int angulo1 = 0, angulo2 = 0, angulo3 = 0, angulo4 = 0;
int direccion1 = 1, direccion2 = 1, direccion3 = 1, direccion4 = 1;

// Control de tiempo sin delay
unsigned long ultimoTiempo = 0;
int velocidad = 50; // Milisegundos entre cada grado (más alto = más lento)

void setup() {
  // Conectar los servos a sus pines
  servo1.attach(pinServo1);
  servo2.attach(pinServo2);
  servo3.attach(pinServo3);
  servo4.attach(pinServo4);
  
  Serial.begin(9600);
  Serial.println("4 Servos iniciados - Movimiento continuo 180 grados");
  
  // Posición inicial
  servo1.write(angulo1);
  servo2.write(angulo2);
  servo3.write(angulo3);
  servo4.write(angulo4);
}

void loop() {
  unsigned long tiempoActual = millis();
  
  // Controlar velocidad sin bloquear
  if (tiempoActual - ultimoTiempo >= velocidad) {
    ultimoTiempo = tiempoActual;
    
    // Mover servo 1
    angulo1 += direccion1;
    if (angulo1 >= 180) {
      angulo1 = 180;
      direccion1 = -1;
    } else if (angulo1 <= 0) {
      angulo1 = 0;
      direccion1 = 1;
    }
    servo1.write(angulo1);
    
    // Mover servo 2
    angulo2 += direccion2;
    if (angulo2 >= 180) {
      angulo2 = 180;
      direccion2 = -1;
    } else if (angulo2 <= 0) {
      angulo2 = 0;
      direccion2 = 1;
    }
    servo2.write(angulo2);
    
    // Mover servo 3
    angulo3 += direccion3;
    if (angulo3 >= 180) {
      angulo3 = 180;
      direccion3 = -1;
    } else if (angulo3 <= 0) {
      angulo3 = 0;
      direccion3 = 1;
    }
    servo3.write(angulo3);
    
    // Mover servo 4
    angulo4 += direccion4;
    if (angulo4 >= 180) {
      angulo4 = 180;
      direccion4 = -1;
    } else if (angulo4 <= 0) {
      angulo4 = 0;
      direccion4 = 1;
    }
    servo4.write(angulo4);
    
    // Mostrar posiciones cada 30 grados
    if (angulo1 % 30 == 0) {
      Serial.print("Servos - Pin2: ");
      Serial.print(angulo1);
      Serial.print("° | Pin3: ");
      Serial.print(angulo2);
      Serial.print("° | Pin4: ");
      Serial.print(angulo3);
      Serial.print("° | Pin5: ");
      Serial.print(angulo4);
      Serial.println("°");
    }
  }
}