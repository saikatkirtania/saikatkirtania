#define BLYNK_TEMPLATE_ID           "TMPL6skp4xWMP"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "Vy8ua4nLu83eo71MMpqgU610qfZjMnR5"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "three_legend";
char pass[] = "saikat.s2002@##";

BlynkTimer timer;

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V0, value);

  if (value == 1) {
    digitalWrite(D1, HIGH);
  } else {
    digitalWrite(D1, LOW);
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V2, value);

  if (value == 1) {
    digitalWrite(D2, HIGH);
  } else {
    digitalWrite(D2, LOW);
  }
}

BLYNK_WRITE(V4)
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V4, value);

  if (value == 1) {
    digitalWrite(D3, HIGH);
  } else {
    digitalWrite(D3, LOW);
  }
}

BLYNK_CONNECTED()
{
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

void myTimerEvent()
{
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();
  
  // Print output to Serial monitor
  if (Serial.available()) {
    char c = Serial.read();
    Blynk.virtualWrite(V4, c);
  }
}
