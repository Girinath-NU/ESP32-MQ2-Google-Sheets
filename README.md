# ESP32 MQ2 Sensor Data Logging to Google Sheets

This project logs data from an MQ2 gas sensor connected to an ESP32 to Google Sheets. The ESP32 connects to WiFi, reads the gas sensor values, and sends them to a specified Google Apps Script URL, which appends the data to a Google Sheet.

## Project Overview

The MQ2 sensor measures the presence of gases in the environment, which the ESP32 reads and sends to Google Sheets for logging and monitoring. This project can be used for applications like gas leakage monitoring and air quality tracking.

## Components

- **ESP32 microcontroller**
- **MQ2 gas sensor**
- **WiFi network** with internet access
- **Google Sheets** and **Google Apps Script**

## Features

- Connects to WiFi and sends MQ2 gas sensor values to Google Sheets.
- Uses a simple JSON data structure for seamless data integration.

## Code Explanation

### Libraries

- **WiFi.h**: Manages WiFi connections.
- **HTTPClient.h**: Handles HTTP requests.

### Constants

- `ssid` and `password`: Stores the WiFi network credentials.
- `googleSheetsUrl`: The Google Apps Script URL that receives sensor data.
- `mq2Pin`: The ESP32 analog pin where the MQ2 sensor is connected (set to GPIO 34 in this code).

### Setup Function

1. **Initialize Serial Communication**: Sets up the serial monitor at 9600 baud rate for debugging.
2. **WiFi Connection**: Connects the ESP32 to the specified WiFi network. If unsuccessful, it retries until a connection is established.

### Loop Function

1. **Read Sensor Value**: Reads the MQ2 sensor value from the specified pin.
2. **Send Data to Google Sheets**:
   - Creates an HTTP client and prepares a POST request.
   - Sets the request header to "application/json".
   - Formats the sensor data as a JSON payload with the structure `{"mq2_value": sensorValue}`.
   - Sends the request to the Google Sheets URL and prints the server response.
3. **Error Handling**: If the request fails, prints the HTTP error code.
4. **Delay**: A 2-second delay between each reading.

## Usage Instructions

1. **Set Up Google Sheets and Google Apps Script**:
   - Create a Google Sheet and open Google Apps Script (Extensions > Apps Script).
   - Use a script to receive and log the incoming data (e.g., using `doPost(e)` in Apps Script).

2. **Modify Constants**:
   - Replace `"XXX"` with your WiFi network name.
   - Replace `"YYY"` with your WiFi password.
   - Replace `"ZZZ"` with the URL of your Google Apps Script.

3. **Upload the Code**:
   - Connect your ESP32 to your computer and upload this code.

4. **Monitor Output**:
   - Open the Serial Monitor in the Arduino IDE to see WiFi connection status, MQ2 sensor values, and server responses.

## Sample Output
Connecting to WiFi... Connected to WiFi! MQ2 Sensor Value: 512 Response from server: Success


## Notes

- Ensure your Google Apps Script is deployed as a web app and set to "Anyone with the link" to receive data from the ESP32.
- The `mq2Pin` may vary depending on your ESP32 board and sensor configuration.

## Troubleshooting

- **WiFi Connection Issues**: Check your WiFi credentials and network stability.
- **HTTP Errors**: Verify the Google Apps Script URL and ensure the Google Script is deployed as a web app.
- **No Data in Google Sheets**: Ensure that the Google Apps Script is correctly set up to handle incoming data.

---

This project offers a practical way to monitor gas levels and log them in real time. Use it for educational purposes, safety projects, or as a building block for more complex IoT applications.


