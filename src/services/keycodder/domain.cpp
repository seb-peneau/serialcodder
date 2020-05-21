#include "domain.h"

int count = 0;

void Domain::setup() {
  debug->debug("Domain::setup");
  display->setup(debug);
}

void Domain::loop() {
  display->loop();
}

void Domain::setDebugInterface(DebugInterface* dI) {
  debug = dI;
}

void Domain::setDisplayInterface (DisplayInterface* dI) {
  display = dI;
}
