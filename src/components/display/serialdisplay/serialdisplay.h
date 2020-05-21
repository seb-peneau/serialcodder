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


};