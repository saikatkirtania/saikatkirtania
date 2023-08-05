#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID           "TMPL6skp4xWMP"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "a0aLRSPLhr6YpXncan1CTHlwc4HF3zhu"
#define BLYNK_PRINT Serial

char ssid[] = "saikat";
char pass[] = "saikat5511";

const int escPin = D3; // ESC signal pin

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Blynk.virtualWrite(V0, value);

  if (value == 1) {
    analogWrite(escPin, 1023); // Set ESC signal to maximum throttle
    Serial.println("Motor ON"); // Print status on Serial monitor
  } else {
    analogWrite(escPin, 0); // Set ESC signal to minimum throttle
    Serial.println("Motor OFF"); // Print status on Serial monitor
  }
}

void setup()
{
  pinMode(escPin, OUTPUT);
  Serial.println("output");

  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
  analogWriteFreq(500); // Set PWM frequency to 500 Hz
}

void loop()
{
  Blynk.run();
  timer.run();
}

void myTimerEvent()
{
  // This function is called periodically
  // You can add code here to perform tasks at specific intervals
}
