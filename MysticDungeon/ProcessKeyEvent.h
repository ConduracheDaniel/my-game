#include "drawImage.h";

void ProcessKeyEvent(WPARAM wParam, LPARAM lParam) {

    WORD vkCode = LOWORD(wParam);                                 // virtual-key code

    WORD keyFlags = HIWORD(lParam);

    WORD scanCode = LOBYTE(keyFlags);                             // scan code
    BOOL isExtendedKey = (keyFlags & KF_EXTENDED) == KF_EXTENDED; // extended-key flag, 1 if scancode has 0xE0 prefix

    if (isExtendedKey)
        scanCode = MAKEWORD(scanCode, 0xE0);

    BOOL wasKeyDown = (keyFlags & KF_REPEAT) == KF_REPEAT;        // previous key-state flag, 1 on autorepeat
    WORD repeatCount = LOWORD(lParam);                            // repeat count, > 0 if several keydown messages was combined into one message

    BOOL isKeyReleased = (keyFlags & KF_UP) == KF_UP;             // transition-state flag, 1 on keyup

    BOOL isKeyPressed = !(keyFlags & KF_UP);

    BOOL isKeyDown = GetAsyncKeyState(vkCode) & 0x8000;

    vkCode = toupper(vkCode);
    //keys actions
    std::unordered_map<char, BUTTON> keyToButtonMap = {
    {'A', BUTTON_A},
    {'S', BUTTON_S},
    {'D', BUTTON_D},
    {'W', BUTTON_W},

    {'I', BUTTON_I},
    {'J', BUTTON_J},
    {'K', BUTTON_K},
    {'L', BUTTON_L},

    {'Z', BUTTON_Z},
    {'X', BUTTON_X},
    {'C', BUTTON_C},

    {'B', BUTTON_B},
    {'N', BUTTON_N},
    {'M', BUTTON_M},
       
    };

    // In your function:
    if (keyToButtonMap.find(vkCode) != keyToButtonMap.end()) {
        BUTTON button = keyToButtonMap[vkCode];

        input.buttons[button].is_released = isKeyReleased;
        input.buttons[button].is_down = isKeyDown;
        input.buttons[button].is_pressed = isKeyPressed;
        input.buttons[button].changed = true;
    }
}