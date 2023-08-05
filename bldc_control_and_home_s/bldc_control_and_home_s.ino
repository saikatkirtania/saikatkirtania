#define BLYNK_TEMPLATE_ID           "TMPL6skp4xWMP"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "Vy8ua4nLu83eo71MMpqgU610qfZjMnR5"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "saikat";
char pass[] = "saikat5511";

const int escPin = 5;
const int armedThreshold = 1000;

BlynkTimer timer;

BLYNK_WRITE(V0) // sw1 = pin D1
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V0, value);

  if (value == 1)
  {
    digitalWrite(D1, LOW);
  }
  else
  {
    digitalWrite(D1, HIGH);
  }
}

BLYNK_WRITE(V1) // sw2 = pin D2
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V2, value);

  if (value == 1)
  {
    digitalWrite(D2, LOW);
  }
  else
  {
    digitalWrite(D2, HIGH);
  }
}

BLYNK_WRITE(V6) // sw3 pin = D3
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V6, value);

  if (value == 1)
  {
    digitalWrite(D3, LOW);
  }
  else
  {
    digitalWrite(D3, HIGH);
  }
}

BLYNK_CONNECTED()
{
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
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
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  timer.run();

  int escValue = pulseIn(escPin, HIGH, 25000);

  if (escValue < armedThreshold)
  {
    int speed = map(escValue, 1000, armedThreshold, 0, 100);
    Blynk.virtualWrite(V4, speed);
    Serial.print("Speed: ");
    Serial.println(speed);
    // Your code here for speed control using the received speed value
    // For example, you can use an analog output to control the speed of a motor
  }

  delay(1000);
}
