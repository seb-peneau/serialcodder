
#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "./services/keycodder/domain.h"
#include "./components/debug/console/console.h"
#include "./components/display/serialdisplay/serialdisplay.h"
#include "./components/keypad/keypadimpl/keypadimpl.h"


Domain* Tamtam = new Domain();

void setup() {
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  Console* console = new Console();
  SerialDisplayImpl *serialDisplayImpl = new SerialDisplayImpl();
  KeypadImpl *keypadImpl = new KeypadImpl();
  Tamtam->setDebugInterface(console);
  Tamtam->setDisplayInterface(serialDisplayImpl);
  Tamtam->setKeypadInterface(keypadImpl);
  Tamtam->setup();
}

void loop() {
  Tamtam->loop();
}