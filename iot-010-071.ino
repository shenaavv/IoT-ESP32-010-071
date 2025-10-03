#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "ITS-WIFI-TW2";      
const char* password = "itssurabaya"; 
String apiKey = "OCQE8TM2NRXIFD8W"; 
const char* serverName = "http://api.thingspeak.com/update";

const int trigPin = 16;     
const int echoPin = 27;
#define ONBOARD_LED 4         
#define SOUND_SPEED 0.034

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ONBOARD_LED, OUTPUT); 

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  long duration;
  float distanceCm;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED / 2;
  
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  if (distanceCm <= 10) {
    digitalWrite(ONBOARD_LED, HIGH);
  } else {
    digitalWrite(ONBOARD_LED, LOW);  
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(serverName) + "?api_key=" + apiKey + "&field1=" + String(distanceCm);
    
    Serial.println("Generated URL: " + url); 

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpCode);
    } else {
      Serial.print("Error sending GET request; HTTP code: ");
      Serial.println(httpCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  Serial.println("Waiting 20 seconds to send next update...");
  delay(20000); 
}
