#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Configuración de Wi-Fi
const char* ssid = "TuSSID";
const char* password = "TuContraseña";

// Configuración del pin del relé
const int relePin = 23;

// Crear servidor web en el puerto 80
AsyncWebServer server(80);

void setup() {
  // Iniciar el monitor serial
  Serial.begin(115200);

  // Configurar el pin del relé como salida
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW); // Asegurarse de que el relé esté apagado inicialmente

  // Conectar a la red Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a la red Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Manejar la solicitud para abrir el portón
  server.on("/abrir", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relePin, HIGH); // Activar el relé
    request->send(200, "text/plain", "Portón abierto");
    delay(5000); // Mantener abierto durante 5 segundos
    digitalWrite(relePin, LOW); // Desactivar el relé
  });

  // Manejar la solicitud para cerrar el portón
  server.on("/cerrar", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(relePin, LOW); // Desactivar el relé
    request->send(200, "text/plain", "Portón cerrado");
  });

  // Iniciar el servidor
  server.begin();
}

void loop() {
  // No es necesario para este ejemplo
}
