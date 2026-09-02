#include <Arduino.h>
#include <WiFi.h>

//Funciones
void limpiarBuffer() {
    while (Serial.available() > 0) {
        Serial.read();
    }
}

// Recordar borrar 
const char* ssid = "Wokwi-GUEST";
const char* password = "";

String targetIPStr = "";
IPAddress targetIP;
int puerto;
int inicial;
int fin;

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

    Serial.println("\n ------------- CONFIGURACION ------------- ");

    Serial.println("Introduce una ip (ejemplo: 192.168.0.3): ");
    while (Serial.available() == 0){
        delay(10);
    }

    targetIPStr = Serial.readStringUntil('\n'); //Lee todo el texto que escribiste en el Monitor Serie hasta que detecta un salto de línea (cuando presionas "Enviar").
    targetIPStr.trim(); // elimina los espacios en blanco
    targetIP.fromString(targetIPStr); // Convierte el String a formato IPAddress

    Serial.println("Introduce el puerto inicial (ejemplo 80):");
    while (Serial.available() == 0){
        delay(10);
    }
    inicial = Serial.parseInt();
    limpiarBuffer();

    Serial.println("introduce el puerto final (ejemplo 1024):");
    while (Serial.available() == 0){
        delay(10);
    }
    fin = Serial.parseInt();
    limpiarBuffer();
    
    Serial.println("[*] Scanner listo. Iniciando escaneo...\n");
    Serial.println("[*] Scanner listo.");

    WiFiClient client;
for (int puerto = inicial; puerto <= fin; puerto++) {
        if (client.connect(targetIP, puerto)) {
            Serial.print("[OPEN] Puerto ");
            Serial.println(puerto);
            client.stop(); // Desconectar para liberar el socket
        } else {
            // Serial.print("[CLOSE] Puerto "); Serial.println(puerto);
        }
        delay(2);
    }

    Serial.println("\n[*] Escaneo finalizado.");
}

void loop() {
 //Hacer codigo main 
}