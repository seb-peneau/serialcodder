#include "components/debug/debugInterface.h"
#include "components/display/displayInterface.h"

class Domain {
  private:
    DebugInterface* debug;
    DisplayInterface* display;

  public:
    void setup ();
    void loop ();

    void setDebugInterface(DebugInterface* debug);
    void setDisplayInterface(DisplayInterface* display);
};
