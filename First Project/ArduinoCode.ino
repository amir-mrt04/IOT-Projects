#include <Adafruit_Sensor.h> 

#include <DHT.h> 

#include <DHT_U.h> 

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// WiFi credentials
const char* ssid = "Irancell-TD-GP2101-366447";          // Replace with your WiFi SSID
const char* password = "asad1234";  // Replace with your WiFi Password

// DHT11 Sensor setup
#define DHTPIN D4           // D4 pin (GPIO2)
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  bool i=false;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (i==false){
    Serial.print("Trying to connect to the Wifi");
    i=true;
    }else Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Initialize DHT sensor
  dht.begin();
}

void loop() {
  // Wait for a client to connect
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("New client");
  bool i=false;
  while (!client.available()) {
    delay(1);
    if (i==false){
    Serial.print("Waiting to receive a message from the client");
    i=true;
    }
  }
  while (client.connected() || client.available() ){
  // Read data from DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Prepare the data to send
  String data = "Temp:" + String(t) + ",Hum:" + String(h);
  Serial.println(data);
  client.println(data);

  // Give the client time to receive the data
  delay(100);
  }
  while (!client.connected()){
  Serial.println("Client disconnected");
  }
}
