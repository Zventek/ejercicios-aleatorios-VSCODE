#include <Arduino.h>

// Definir el pin al que está conectado el LED
const int ledPin = 4; // Pin D4 en la placa ESP32 S3 N8R2

void setup() {
  // Configurar el pin como salida
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Encender el LED
  digitalWrite(ledPin, HIGH);
  delay(1000); // Esperar 1 segundo
  
  // Apagar el LED
  digitalWrite(ledPin, LOW);
  delay(1000); // Esperar 1 segundo
}
