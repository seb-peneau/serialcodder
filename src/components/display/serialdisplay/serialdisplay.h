#include "../displayInterface.h"

#include "SoftwareSerial.h"

class SerialDisplayImpl : public DisplayInterface
{
  private:
    DebugInterface *displayDebug;
    SoftwareSerial *display;

  public:
    SerialDisplayImpl();
    void setup (DebugInterface *debug);
    void loop ();
    void clearDisplay ();
    void setCoordStatus (int x, int y, bool state);
    void displayWifiStatus (bool displayWifi);
    void displayHour(int hour, int minute);
    void displayTemp(int temp);
    void displayConfigurationMode(bool confEnabled);
    void displayOtaProgress (int progressPercent);
    void displayIpAddress (String ipAddress);

};