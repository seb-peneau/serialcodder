#include "components/debug/debugInterface.h"
#include "components/display/displayInterface.h"
#include "components/keypad/KeypadInterface.h"

class Domain {
  private:
    DebugInterface* debug;
    DisplayInterface* display;
    KeypadInterface* keypad;

  public:
    void setup ();
    void loop ();
    void handleKeypadTouch(char character);

    void setDebugInterface(DebugInterface* debug);
    void setDisplayInterface(DisplayInterface* display);
    void setKeypadInterface(KeypadInterface* keypad);
};
