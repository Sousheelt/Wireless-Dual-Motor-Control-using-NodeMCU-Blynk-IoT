#define BLYNK_TEMPLATE_ID "TMPL3chxFv1g"
#define BLYNK_TEMPLATE_NAME "Motor Control"
#define BLYNK_AUTH_TOKEN "TEZdbCQndx4TwcwjOBwo6BDIItmgYAL8"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "Sousheel";
char pass[] = "soush123";


// Motor control pins (using GPIO numbers directly)
#define M1F 4   // GPIO4 = D2
#define M1R 2   // GPIO2 = D4
#define M2F 5   // GPIO5 = D1
#define M2R 0   // GPIO0 = D3

int motor1Speed = 0;
int motor2Speed = 0;
int m1Forward = 0;
int m1Reverse = 0;
int m2Forward = 0;
int m2Reverse = 0;

// Blynk Virtual Pins (matching your template)
BLYNK_WRITE(V1) {
  motor1Speed = param.asInt(); // Motor 1 speed from slider
}

BLYNK_WRITE(V2) {
  motor2Speed = param.asInt(); // Motor 2 speed from slider
}

BLYNK_WRITE(V3) {
  m1Forward = param.asInt(); // Motor 1 forward direction from button
}

BLYNK_WRITE(V4) {
  m1Reverse = param.asInt(); // Motor 1 reverse direction from button
}

BLYNK_WRITE(V5) {
  m2Forward = param.asInt(); // Motor 2 forward direction from button
}

BLYNK_WRITE(V6) {
  m2Reverse = param.asInt(); // Motor 2 reverse direction from button
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting....");

  // Set motor pins as output
  pinMode(M1F, OUTPUT);
  pinMode(M1R, OUTPUT);
  pinMode(M2F, OUTPUT);
  pinMode(M2R, OUTPUT);

  // Connect to Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run(); // Run Blynk to keep the app connected

  // Motor 1 control logic based on direction and speed
  if (m1Forward == 1 && m1Reverse == 0) {
    analogWrite(M1F, motor1Speed); // Move motor 1 forward
    analogWrite(M1R, 0); // Stop reverse motion
  } else if (m1Forward == 0 && m1Reverse == 1) {
    analogWrite(M1F, 0); // Stop forward motion
    analogWrite(M1R, motor1Speed); // Move motor 1 reverse
  } else {
    analogWrite(M1F, 0); // Stop forward motion
    analogWrite(M1R, 0); // Stop reverse motion
  }

  // Motor 2 control logic based on direction and speed
  if (m2Forward == 1 && m2Reverse == 0) {
    analogWrite(M2F, motor2Speed); // Move motor 2 forward
    analogWrite(M2R, 0); // Stop reverse motion
  } else if (m2Forward == 0 && m2Reverse == 1) {
    analogWrite(M2F, 0); // Stop forward motion
    analogWrite(M2R, motor2Speed); // Move motor 2 reverse
  } else {
    analogWrite(M2F, 0); // Stop forward motion
    analogWrite(M2R, 0); // Stop reverse motion
  }
}
