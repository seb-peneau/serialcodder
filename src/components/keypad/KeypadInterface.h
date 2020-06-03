#ifndef KeypadInterface_h
#define KeypadInterface_h

#include "Arduino.h"
#include "../debug/debugInterface.h"

class KeypadInterface
{
  public:
    virtual void setup (DebugInterface *debug);
    virtual void loop ();
    virtual void onKeyPressed(std::function<void(char)> handler);
};

#endif