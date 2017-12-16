
#include <ESP8266WiFi.h>
#include "WiFiClientSecure.h"
#include <ArduinoJson.h>


const char* ssid     = "MakerPT";
const char* password = "aveiro2017";

const int httpPort = 443;
const char* host = "api.coinbase.com";
const char* url = "/v2/prices/EUR/spot";

WiFiClientSecure client;

String line = "";
String vv = "";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);

 WiFi.mode(WIFI_STA);
 Serial.println("A ligar...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
}

Serial.println("Ligado!");

}

void GetBTC(){

 int cc = client.connect(host, httpPort);

  if ( cc != 1) {
    Serial.printf("connection failed: %d\n", cc);
    return;
  }

  
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP32VS\r\n" +
               "Accept: */*\r\n" +
               "Connection: close\r\n\r\n");

  while (client.available()) {
    vv = client.readStringUntil('\r');
    if (vv.indexOf("EUR") != -1)
      line += vv;
  }

  Serial.print(line);
               
}

void loop() {
  // put your main code here, to run repeatedly:

}
