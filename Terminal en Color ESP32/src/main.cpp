#include <Arduino.h>


void setup() {
  Serial.begin(115200);

  // Esperar un momento para la conexión del monitor serial
  delay(1000);

  // Mensaje en color rojo
  Serial.print("\033[31m"); // Código de escape ANSI para rojo
  Serial.println("Este es un mensaje en ROJO");
  
  // Mensaje en color verde
  Serial.print("\033[32m"); // Código de escape ANSI para verde
  Serial.println("Este es un mensaje en VERDE");

  // Mensaje en color amarillo
  Serial.print("\033[33m"); // Código de escape ANSI para amarillo
  Serial.println("Este es un mensaje en AMARILLO");

  // Mensaje en color azul
  Serial.print("\033[34m"); // Código de escape ANSI para azul
  Serial.println("Este es un mensaje en AZUL");

  // Mensaje en color magenta
  Serial.print("\033[35m"); // Código de escape ANSI para magenta
  Serial.println("Este es un mensaje en MAGENTA");

  // Mensaje en color cian
  Serial.print("\033[36m"); // Código de escape ANSI para cian
  Serial.println("Este es un mensaje en CIAN");

  // Mensaje en color blanco
  Serial.print("\033[37m"); // Código de escape ANSI para blanco
  Serial.println("Este es un mensaje en BLANCO");

  // Resetear el color de vuelta al predeterminado
  Serial.print("\033[0m");
  Serial.println("Este es un mensaje en el color predeterminado");
}

void loop() {
  // No se hace nada en el loop en este ejemplo
}


