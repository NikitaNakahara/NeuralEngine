#include <Core/InputManager.hpp>

#include <stdlib.h>

namespace Core {
    struct IMWndID {
        #if defined(__linux__)
        unsigned long id = 0;
        Display* pDisplay;
        #endif
    };

    InputManager::InputManager(void *__idPtr) {
        #if defined(__linux__)
        _id =  (IMWndID*)__idPtr;
        _wmDeleteMessage = XInternAtom(_id->pDisplay, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(_id->pDisplay, _id->id, &_wmDeleteMessage, 1);
        XSelectInput(_id->pDisplay, _id->id, _inputMask | ExposureMask);
        updateEvents();
        #endif
    }

    void InputManager::updateEvents() {
        #if defined(__linux__)
        while (XPending(_id->pDisplay) > 0) {
            XNextEvent(_id->pDisplay, &_event);

            _windowShouldClose = _event.xclient.data.l[0] == _wmDeleteMessage;

            switch (_event.type) {
            case KeyPress:
            _keyCallback(XKeycodeToKeysym(_id->pDisplay, _event.xkey.keycode, 0));
                break;
            }
        }
        #endif
    }

    void InputManager::setKeyPressCallback(void (*__keyCallback)(unsigned int)) {
        _keyCallback = __keyCallback;
        #if defined(__linux__)
        XSelectInput(_id->pDisplay, _id->id, _inputMask | KeyPressMask);
        #endif
    }
}