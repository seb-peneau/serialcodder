#include "serialdisplay.h"

SerialDisplayImpl::SerialDisplayImpl() {
  display = new SoftwareSerial(2, 8);
}

void SerialDisplayImpl::setup (DebugInterface *debug) {
  displayDebug = debug;
  display->begin(9600);
  clearDisplay();
  display->print("Init ...");
}

void SerialDisplayImpl::loop() {
}

void SerialDisplayImpl::clearDisplay () {
  display->write(0xFE);  // send the special command
  display->write(0x01);  // send the clear screen command
}

