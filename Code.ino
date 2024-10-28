#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "XXX"; // Replace with your WiFi network name
const char* password = "YYY"; // Replace with your WiFi password
const String googleSheetsUrl = "ZZZ"; // Replace with Google Apps Script URL

const int mq2Pin = 34; // Pin where the MQ2 sensor is connected

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  // Attempt to connect to WiFi
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  // Read MQ2 sensor value
  int mq2Value = analogRead(mq2Pin);

  // Print the MQ2 value to Serial Monitor
  Serial.print("MQ2 Sensor Value: ");
  Serial.println(mq2Value);

  // Send data to Google Sheets
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(googleSheetsUrl);
    http.addHeader("Content-Type", "application/json");

    // Create JSON data payload with only MQ2 sensor value
    String jsonData = "{\"mq2_value\":" + String(mq2Value) + "}";

    // Send POST request
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response from server: " + response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected");
  }

  delay(2000); // Delay 2 seconds between readings
}
