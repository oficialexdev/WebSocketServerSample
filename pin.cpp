#include "esp32-hal.h"
#include "websocketservesample.h"
namespace websocketservesample {
Pin::Pin(int pin) {
  this->pin = pin;
}
void Pin::pinOutput() {
  
  pinMode(pin, OUTPUT);
}
void Pin::pinInput() {
  pinMode(pin, INPUT);
}
int Pin::read() {
  return digitalRead(pin);
}
int Pin::readAnalog() {
  return analogRead(pin);
}
void Pin::write(int value) {
  digitalWrite(pin, value);
}
void Pin::writeAnalog(int value) {
  analogWrite(pin, value);
}
}