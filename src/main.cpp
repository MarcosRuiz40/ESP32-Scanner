#include <Arduino.h>
#include <WiFi.h>

// Recordar borrar 
const char* ssid = "Wokwi-GUEST";
const char* password = "";

IPAddress ip(192, 168, 0, 181);
int puerto = 80;

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

    WiFiClient client;

    if (client.connect(ip, puerto)){
        Serial.println("[OPEN] Puerto abierto");
    } else {
        Serial.println("[CLOSE] Puerto cerrado");
    }
}

void loop() {
 //Hacer codigo main 
}