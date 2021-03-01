#include "serialdisplay.h"

SerialDisplayImpl::SerialDisplayImpl() {
  display = new SoftwareSerial(2, D0);
}

void SerialDisplayImpl::setup (DebugInterface *debug) {
  displayDebug = debug;
  displayDebug->debug("SerialDisplayImpl::setup::start");
  display->begin(9600);
  clearDisplay();
  display->print("Init4 ...");
  displayDebug->debug("SerialDisplayImpl::setup::end");
}

void SerialDisplayImpl::loop() {
}

void SerialDisplayImpl::clearDisplay () {
  display->write(0xFE);  // send the special command
  display->write(0x01);  // send the clear screen command
}

void SerialDisplayImpl::setCursorPosition (int position) {
  display->write(0xFE); // send the special command
  display->write(0x80); // send the cursor position command
  display->write((unsigned char) position);
}

void SerialDisplayImpl::setBrightness (int value) {
  display->write(0x80); // send backlight value
  display->write((unsigned char) value);
}

void SerialDisplayImpl::print(String message) {
  display->print(message);
}
