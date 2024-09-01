#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Ping.h>

// credenciales de la red a la cual nos conectaremos
const char* ssid = "IZZI-529C";
const char* password = "fcygTm9hEMGHxanXLk";

// Dirección IP de Google (DNS de Google)
const IPAddress pingAddr(8, 8, 8, 8); 

void setup() {
  Serial.begin(115200);

  // Nos conectamos a la red 
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Conectado a la red con la IP:  ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {
  if(WiFi.status() == WL_CONNECTED)
  {
    // Realizamos ping a Google
    if(Ping.ping(pingAddr)) {
      Serial.println("Ping a Google OK");
    } else {
      Serial.println("Ping a Google fallido");
    }
  }

  while(true){}
}
