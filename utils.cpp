#include "esp32-hal.h"
#include "websocketservesample.h"
#include <WiFi.h>
#include <Esp.h>

namespace websocketservesample {
unsigned int Utils::seconds() {
  return (unsigned int)(millis() / 1000);
}
void Utils::turnOnSignal(int pin) {
  Pin incorporatedLed(pin);
  incorporatedLed.pinOutput();
  incorporatedLed.write(HIGH);
  delay(200);
  incorporatedLed.write(LOW);
  delay(1000);
  incorporatedLed.write(HIGH);
  delay(1000);
  incorporatedLed.write(LOW);
}
}