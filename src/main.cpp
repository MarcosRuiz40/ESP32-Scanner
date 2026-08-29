#include <Arduino.h>
#include <WiFi.h>

// Recordar borrar 
const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup() {

    Serial.begin(115200);
    delay(1000);

    Serial.println("--------------------------------");
    Serial.println("ESP32 Port Scanner");
    Serial.println("--------------------------------");

    Serial.println("[*] Inicializando ESP32...");
    Serial.println("[*] Conectando a Wi-Fi...");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("[+] Wi-Fi conectado");
    Serial.print("[+] IP: ");
    Serial.println(WiFi.localIP());

    Serial.println("[*] Scanner listo.");
}

void loop() {
 //Hacer codigo main 
}