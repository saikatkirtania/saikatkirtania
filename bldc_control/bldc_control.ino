#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#define BLYNK_TEMPLATE_ID           "TMPL6skp4xWMP"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "a0aLRSPLhr6YpXncan1CTHlwc4HF3zhu"
#define BLYNK_PRINT Serial

char ssid[] = "saikat";
char pass[] = "saikat5511";

const int escPin = D3; // ESC signal pin

Servo esc; // Create a servo object for ESC control

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Blynk.virtualWrite(V0, value);

  if (value == 1) {
    esc.writeMicroseconds(2000); // Set ESC signal to maximum throttle
  } else {
    esc.writeMicroseconds(1000); // Set ESC signal to minimum throttle
  }
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  esc.attach(escPin); // Attach the servo object to the ESC signal pin
  esc.writeMicroseconds(1000); // Set initial throttle to minimum
}

void loop()
{
  Blynk.run();
}
