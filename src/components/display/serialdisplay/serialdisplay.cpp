#include "serialdisplay.h"

SerialDisplayImpl::SerialDisplayImpl() {
  display = new SoftwareSerial(2, 8);
}

void SerialDisplayImpl::setup (DebugInterface *debug) {
  displayDebug = debug;
  display->begin(9600);
  clearDisplay();
  display->print("Hello, world");
}

void SerialDisplayImpl::loop() {
}

void SerialDisplayImpl::clearDisplay () {
  display->write(0xFE);  // send the special command
  display->write(0x01);  // send the clear screen command
}

void SerialDisplayImpl::displayHour(int hour, int minutes) {
}

void SerialDisplayImpl::setCoordStatus (int i, int j, bool state) {
}

void SerialDisplayImpl::displayWifiStatus (bool displayWifi) {

}

void SerialDisplayImpl::displayTemp (int temp) {
}

void SerialDisplayImpl::displayConfigurationMode (bool confEnabled) {

}

void SerialDisplayImpl::displayOtaProgress (int progressPercent) {

}

void SerialDisplayImpl::displayIpAddress (String ipAddress) {

}
