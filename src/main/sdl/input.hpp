/***************************************************************************
    SDL Based Input Handling.

    Populates keys array with user input.
    If porting to a non-SDL platform, you would need to replace this class.

    Copyright Chris White.
    See license.txt for more details.
***************************************************************************/

#pragma once

#include <SDL.h>

class Input
{
public:
    enum presses
    {
        LEFT = 0,
        RIGHT = 1,
        UP = 2,
        DOWN = 3,
        ACCEL = 4,
        BRAKE = 5,
        GEAR = 6,

        START = 7,
        COIN  = 8,
        
        PAUSE = 9,
        STEP  = 10,
        TIMER = 11,
        MENU = 12,
    };

    bool keys[13];
    bool keys_old[13];

    // Has gamepad been found?
    bool gamepad;

    // Use analog controls
    bool analog;

    // Latch last key press for redefines
    int key_press;

    // Latch last joystick button press for redefines
    int16_t joy_button;

    // Analog Controls
    int a_wheel;
    int a_accel;
    int a_brake;

    Input(void);
    ~Input(void);

    void init(int*, int*, const bool, int*, const int);
    void close();

    void handle_key_up(SDL_keysym*);
    void handle_key_down(SDL_keysym*);
    void handle_joy_axis(SDL_JoyAxisEvent*);
    void handle_joy_down(SDL_JoyButtonEvent*);
    void handle_joy_up(SDL_JoyButtonEvent*);
    void frame_done();
    bool is_pressed(presses p);
    bool has_pressed(presses p);

private:
    // SDL Joystick / Keypad
    SDL_Joystick *stick;

    // Configurations for keyboard and joypad
    int* pad_config;
    int* key_config;
    int* axis;

    int analog_zone;

    void handle_key(const int, const bool);
    void handle_joy(const uint8_t, const bool);
};

extern Input input;