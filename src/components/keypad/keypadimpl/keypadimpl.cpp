#include "keypadimpl.h"

KeypadImpl::KeypadImpl () {
    myKeypad = new Keypad(makeKeymap(KEYS), ROWPINS, COLPINS, N_ROWS, N_COLS);    
}


void KeypadImpl::setup (DebugInterface *debug) {
    debugKeypad = debug;
    debugKeypad->debug("KeypadImpl::setup::finished");
    lastEvent = millis();
}

void KeypadImpl::loop () {
    unsigned long currentEvent = millis();
    if (currentEvent - lastEvent > 100) {
        myKeypad->getKey();
        char myKey = _getKeyLocalFix();
        if (myKey) {
            lastEvent = currentEvent;
            debugKeypad->debug("KeypadImpl::keypressed::" + (String) myKey);
            onKeyHandler(myKey);
        }
    }
}

// With my setup, I never get A and B running because 1 and 4 are triggered as well, quick fix that
char KeypadImpl::_getKeyLocalFix() {
    if (myKeypad->isPressed('A') && myKeypad->isPressed('1')) {
        return 'A';
    } else if (myKeypad->isPressed('B') && myKeypad->isPressed('4')) {
        return 'B';
    } else if (myKeypad->isPressed('1')) {
        return '1';
    } else if (myKeypad->isPressed('2')) {
        return '2';
    } else if (myKeypad->isPressed('3')) {
        return '3';
    } else if (myKeypad->isPressed('4')) {
        return '4';
    } else if (myKeypad->isPressed('5')) {
        return '5';
    } else if (myKeypad->isPressed('6')) {
        return '6';
    } else if (myKeypad->isPressed('7')) {
        return '7';
    } else if (myKeypad->isPressed('8')) {
        return '8';
    } else if (myKeypad->isPressed('9')) {
        return '9';
    } else if (myKeypad->isPressed('C')) {
        return 'C';
    } else if (myKeypad->isPressed('D')) {
        return 'D';
    } else if (myKeypad->isPressed('*')) {
        return '*';
    } else if (myKeypad->isPressed('0')) {
        return '0';
    } else if (myKeypad->isPressed('#')) {
        return '#';
    }
}

void KeypadImpl::onKeyPressed(std::function<void(char)> handler) {
    onKeyHandler = handler;
}