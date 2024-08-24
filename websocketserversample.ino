//SET IMPORTS
#include "websocketservesample.h"
#include <WebSocketsServer.h>
//SET NAMESPACES
using namespace websocketservesample;
//GLOBALS
Pin incorporatedLed(2);
WifiManager wifi("YOUR_SSID", "YOUR_PASSWD");
WebSocketsServer ws = WebSocketsServer(80);

void onWebSocketEvent(u_int8_t num, WStype_t type, u_int8_t* payload, size_t length) {
  switch (type) {
    case WStype_CONNECTED:
      Serial.println("CLIENT CONNECTED");
      ws.sendTXT(num, "OK", 2);
      break;
    case WStype_TEXT:
      Serial.println((int)(*payload));
      //48 IS "0" IN ASCII
      switch ((int)(*payload)) {
        case 48:
          incorporatedLed.write(LOW);
          ws.sendTXT(num, "OFF", 3);
          break;
        case 48 + 1:
          incorporatedLed.write(HIGH);
          ws.sendTXT(num, "ON", 2);
          break;
      }
      break;
    case WStype_DISCONNECTED:
      Serial.println("CLIENT DISCONNECTED");
      break;
  }
}

void setup() {
  Serial.begin(115200);
  Utils::turnOnSignal(2);
  wifi.begin();
  incorporatedLed.write(HIGH);
  delay(1000);
  incorporatedLed.write(LOW);
  ws.begin();
  ws.onEvent(onWebSocketEvent);
}

void loop() {
  ws.loop();
}