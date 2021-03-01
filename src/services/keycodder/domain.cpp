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

  if (key == '*') {
    display->setBrightness(125);
    display->clearDisplay();
    display->setCursorPosition(0);
    display->print("Garage");
    display->setCursorPosition(7);
    display->print("|");
    display->setCursorPosition(8);
    display->print("Camera");
    display->setCursorPosition(16);
    display->print("Poules");
    display->setCursorPosition(23);
    display->print("|");
    display->print("Suite..");
  } else {
    display->setBrightness(2);
    display->clearDisplay();
    display->setCursorPosition(2);
    display->print((String) key);
  }
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