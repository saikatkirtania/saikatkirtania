#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <ESP8266PWM.h>

char ssid[] = "saikat";
char pass[] = "saikat5511";
const int motorPin = D1; // Control pin for the BLDC motor

BLYNK_WRITE(V0) // sw1 = pin = D1
{
  int value = param.asInt();
  // Update state
  Blynk.virtualWrite(V0, value);

  if (value == 1)
  {
    analogWrite(motorPin, 1023); // Apply maximum PWM signal to the motor
  }
  else
  {
    analogWrite(motorPin, 0); // Stop the motor by applying no PWM signal
  }
}

void setup()
{
  pinMode(motorPin, OUTPUT);
  Serial.begin(115200);

  Blynk.begin("YourAuthToken", ssid, pass);
}

void loop()
{
  Blynk.run();
}
