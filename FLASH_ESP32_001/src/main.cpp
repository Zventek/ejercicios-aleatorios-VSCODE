#include <Arduino.h>
#include <Preferences.h>

// Creamos un objeto Preferences
Preferences preferences;

void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(115200);

  // Esperamos unos segundos para ver el resultado en el monitor serial
  delay(1000);

  // Abrimos las preferencias (NVS)
  preferences.begin("my-app", false);

  // Verificamos si ya hemos guardado la palabra "nihao"
  String storedValue = preferences.getString("greeting", "");

  if (storedValue == "") {
    // Si no se ha guardado, la guardamos y luego reiniciamos
    Serial.println("Guardando 'nihao' en memoria flash...");
    preferences.putString("greeting", "nihao");
    
    // Cerramos las preferencias
    preferences.end();

    // Reiniciamos la placa para simular un reinicio
    Serial.println("Reiniciando...");
    delay(1000);
    ESP.restart();
  } else if (storedValue == "nihao") {
    // Si ya se ha guardado, la leemos e imprimimos
    Serial.print("Palabra guardada en memoria: ");
    Serial.println(storedValue);

    // Ahora que hemos leído el valor, borramos la clave
    preferences.remove("greeting");
    Serial.println("Palabra 'nihao' eliminada de la memoria flash.");

    // Cerramos las preferencias
    preferences.end();

    // Reiniciamos nuevamente para comprobar que se ha borrado
    Serial.println("Reiniciando nuevamente...");
    delay(1000);
    ESP.restart();
  } else {
    // Si el valor ya ha sido borrado, mostramos un mensaje de que no hay nada almacenado
    Serial.println("No hay palabra guardada en memoria.");

    // Cerramos las preferencias
    preferences.end();
  }
}

void loop() {
  // No hacemos nada en el loop
}
