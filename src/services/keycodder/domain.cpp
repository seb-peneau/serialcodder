#include "domain.h"

int count = 0;

void Domain::setup() {
  debug->debug("Domain::setup::display");
  display->setup(debug);
  debug->debug("Domain::setup");
  keypad->setup(debug);
  keypad->onKeyPressed([&, this](char key){
    return handleKeypadTouch(key);
  });
}

void Domain::loop() {
  display->loop();
  keypad->loop();
}

void Domain::handleKeypadTouch(char key) {
  debug->debug("Domain::handleKeypadTouch::" + (String) key);
}

void Domain::setDebugInterface(DebugInterface* dI) {
  debug = dI;
}

void Domain::setDisplayInterface (DisplayInterface* dI) {
  display = dI;
}

void Domain::setKeypadInterface (KeypadInterface* kI) {
  keypad = kI;
}