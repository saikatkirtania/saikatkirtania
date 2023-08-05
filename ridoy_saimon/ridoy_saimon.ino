#define BLYNK_TEMPLATE_ID           "TMPL6skp4xWMP"
#define BLYNK_TEMPLATE_NAME         "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "a0aLRSPLhr6YpXncan1CTHlwc4HF3zhu"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <EEPROM.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "saikat";
char pass[] = "saikat5511";

int relay1 = D1;
int relay2 = D2;
int relay3 = D3;
int relay4 = D4;
int val1, val2, val3;

void setup()
{
  EEPROM.begin(800);
  Serial.begin(115200);

  val1 = EEPROM.read(1);
  val2 = EEPROM.read(2);
  val3 = EEPROM.read(3);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);

  digitalWrite(relay1, !val1);
  digitalWrite(relay2, !val2);
  digitalWrite(relay3, !val3);

  EEPROM.put(1, val1);
  EEPROM.put(2, val2);
  EEPROM.put(3, val3);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  val1 = !param.asInt();
  Serial.print("val 1: ");
  Serial.println(!val1);
  digitalWrite(relay1, val1);
  EEPROM.put(1, val1);
  EEPROM.commit();
}

BLYNK_WRITE(V1)
{
  val2 = !param.asInt();
  Serial.print("val 2: ");
  Serial.println(!val2);
  digitalWrite(relay2, !val2);
  EEPROM.put(2,val2);
  EEPROM.commit();
}

BLYNK_WRITE(V6)
{
  val3 = !param.asInt();
  Serial.print("val 3: ");
  Serial.println(!val3);
  digitalWrite(relay3, !val3);
  EEPROM.put(3, val3);
  EEPROM.commit();
}

BLYNK_WRITE(V4)
{
  int escValue = param.asInt();
  Serial.print("ESC value: ");
  Serial.println(escValue);

  // Map the received value from 0-255 to the appropriate range for your ESC
  int escPWM = map(escValue, 0, 255*2, 0, 2*180); // Adjust the mapping range based on your ESC requirements
    
  // Set the ESC control signal
  analogWrite(D4, escPWM);
}
