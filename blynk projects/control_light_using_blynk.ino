#define BLYNK_TEMPLATE_ID "your_blynk_template_id"
#define BLYNK_TEMPLATE_NAME "your_blynk_template_name"

#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "your_auth";
char ssid[] = "your_wifi_ssid";
char pass[] = "your_wifi_password";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(D2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}

BLYNK_WRITE(V1) {
  Serial.print(param.asInt());

  if (param.asInt() == 1)
  {
    digitalWrite(D2, HIGH);
  }
  else {
    digitalWrite(D2, LOW);
  }
}
