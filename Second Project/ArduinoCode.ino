#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

#define DHTPIN D4 // Pin where DHT11 is connected
#define DHTTYPE DHT11 // DHT 11 sensor type

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "SSID";          // Replace with your WiFi SSID
const char* password = "Password";  // Replace with your WiFi Password

WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  // Connecting to WiFi
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

}

void loop() {
  float h = dht.readHumidity(); // Read humidity
  float t = dht.readTemperature(); // Read temperature

  if (isnan(h) || isnan(t)) {
    Serial.println("Error reading from DHT sensor!");
    return;
  }

  // Print temperature and humidity to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  
  // Send data to Node-RED
  sendDataToNodeRED(t, h);

  delay(10000); // Send data every 10 seconds
}

void sendDataToNodeRED(float temperature, float humidity) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Replace with your Node-RED IP and port
    String serverPath = "http://[YOUR_IP]:1880/your-endpoint";

    // Create JSON data
    String jsonData = "{\"temperature\":";
    jsonData += temperature;
    jsonData += ", \"humidity\":";
    jsonData += humidity;
    jsonData += "}";

    // Initialize HTTPClient with the client and server path
    http.begin(client, serverPath);
    http.addHeader("Content-Type", "application/json"); // Specify content type as JSON
    
    // Send HTTP POST request
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      // If the request was successful, print the response
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      // Print error if there was an issue with the HTTP request
      Serial.println("Error sending HTTP request");
    }
    
    http.end(); // End the connection
  }
}
