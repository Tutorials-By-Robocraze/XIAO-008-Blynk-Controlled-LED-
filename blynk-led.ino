#define BLYNK_TEMPLATE_ID "TMPL3R7Eok0H-"
#define BLYNK_TEMPLATE_NAME "WiFi Light Control"
#define BLYNK_AUTH_TOKEN "vgKmX7RuC1DM04qiTrrzq3F0LepGrX4x"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "TIF Labs Pvt Ltd";
char pass[] = "RoboTif@123";

#define LED_PIN 5   // D5 pin from pinout

BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.print("Blynk V0 value: ");
  Serial.println(value);
  digitalWrite(LED_PIN, value);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
