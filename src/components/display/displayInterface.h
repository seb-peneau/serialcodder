#ifndef DisplayInterface_h
#define DisplayInterface_h

#include "Arduino.h"
#include "../debug/debugInterface.h"

class DisplayInterface
{
  public:
    virtual void setup (DebugInterface *debug);
    virtual void loop ();
    virtual void clearDisplay ();
};

#endif