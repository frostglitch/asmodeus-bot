#include <Wire.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

//----------------------------

#define BLYNK_PRINT Serial

char auth[] = "vmRY34A6Gz5NyeAYQc52k5ujUtorMHzD";
char ssid[] = "Jarda";
char pass[] = "YUdsb2FRPT0=";

//#include <SoftwareSerial.h>
//SoftwareSerial EspSerial(0, 1); // RX, TX

#define ESP8266_BAUD 115200
ESP8266 wifi(&Serial);

//-----------------------------

volatile int myData[3] = {0,0,0}; // 0 joystick X       1 joystick Y      2 camera



void setup() {
  Wire.begin(6);
  Wire.onRequest(requestEvent);
  
  Serial.begin(9600);
  delay(10);
  Serial.begin(ESP8266_BAUD);
  delay(10);
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop() {
  Blynk.run();
}

void requestEvent() {
  Wire.write((byte *) myData, 6);
}

BLYNK_WRITE(V0)
{
  myData[0] = param[0].asInt();
  myData[1] = param[1].asInt();
}

BLYNK_WRITE(V1)
{
  myData[3] = param.asInt();
}
