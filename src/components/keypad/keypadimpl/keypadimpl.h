
#ifndef KeypadImpl_h
#define KeypadImpl_h

#include "../KeypadInterface.h"

#include "Keypad.h"

        const byte N_ROWS = 4;
        const byte N_COLS = 4;

class KeypadImpl: public KeypadInterface {

    private:
        Keypad *myKeypad; 
        DebugInterface *debugKeypad;
        byte COLPINS[N_COLS] = {D5, D6, D7, D8};
        byte ROWPINS[N_ROWS] = {D1, D2, D3, D4};
        char KEYS[N_ROWS][N_COLS] = {
            {'1','2','3','A'},
            {'4','5','6','B'},
            {'7','8','9','C'},
            {'*','0','#','D'}
        };
        unsigned long lastEvent;

        char _getKeyLocalFix();
        std::function<void(char)> onKeyHandler;

  
    public:
        KeypadImpl ();
        void setup (DebugInterface *debug);
        void loop ();
        void onKeyPressed(std::function<void(char)> handler);
};

#endif