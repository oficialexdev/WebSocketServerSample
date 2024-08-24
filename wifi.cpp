#include "esp32-hal.h"
#include "websocketservesample.h"
#include <WiFi.h>
#include <Esp.h>

namespace websocketservesample {
WifiManager::WifiManager(char *ssid, char *passwd) {
  this->ssid = ssid;
  this->passwd = passwd;
}

void WifiManager::begin() {
  WiFi.config(IPAddress(192, 168, 1, 180), IPAddress(8, 8, 8, 8));
  WiFi.begin(ssid, passwd);
  WiFi.setAutoReconnect(true);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (websocketservesample::Utils::seconds() > 10) {
      if (Serial.availableForWrite()) {
        Serial.println("Error on connect network!");
      }
      ESP.restart();
      return;
    }
  }
  const IPAddress address = WiFi.gatewayIP();
  const IPAddress ip = WiFi.localIP();
  this->gateway = &address;
  this->ip = &ip;
  if (Serial.availableForWrite()) {
    Serial.println(ip);
  }
}
}