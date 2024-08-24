#include "esp32-hal.h"
#include <WiFi.h>
#ifndef websocketservesample_h
#define websocketservesample_h
namespace websocketservesample {
/**
*/
class Utils {
public:
  static unsigned int seconds();
  static void turnOnSignal(int pin);
};
/**
*/
class Pin {
public:
  Pin(int pin);
  void pinOutput();
  void pinInput();
  int read();
  int readAnalog();
  void write(int value);
  void writeAnalog(int value);
private:
  int pin;
};
/**
*/
class WifiManager {
public:
  WifiManager(char *ssid, char *passwd);
  void begin();
  const IPAddress *ip;
  const IPAddress *gateway;
private:
  char *ssid;
  char *passwd;
};
}
#endif