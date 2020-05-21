
#include <Arduino.h>

#include "./services/keycodder/domain.h"
#include "./components/debug/console/console.h"
#include "./components/display/serialdisplay/serialdisplay.h"

Domain* Tamtam = new Domain();

void setup() {
  Console* console = new Console();
  SerialDisplayImpl *serialDisplayImpl = new SerialDisplayImpl();
  Tamtam->setDebugInterface(console);
  Tamtam->setDisplayInterface(serialDisplayImpl);
  Tamtam->setup();
}

void loop() {
  Tamtam->loop();
}