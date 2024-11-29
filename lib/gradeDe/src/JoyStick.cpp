/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/JoyStick.hpp"

namespace gd
{
    JoyStick::JoyStick(unsigned int id)
    {
        _isConnected = sf::Joystick::isConnected(id);

        _buttons[Button::A] = false;
        _buttons[Button::B] = false;
        _buttons[Button::X] = false;
        _buttons[Button::Y] = false;
        _buttons[Button::LB] = false;
        _buttons[Button::RB] = false;
        _buttons[Button::Select] = false;
        _buttons[Button::Home] = false;

        _axis[Axis::LX] = 0;
        _axis[Axis::LY] = 0;
        _axis[Axis::RX] = 0;
        _axis[Axis::RY] = 0;
        _axis[Axis::LT] = 0;
        _axis[Axis::RT] = 0;
        _axis[Axis::CX] = 0;
        _axis[Axis::CY] = 0;
    }

    void JoyStick::setConnected(bool connected)
    {
        _isConnected = connected;
    }

    void JoyStick::setButtonPressed(Button button, bool pressed)
    {
        _buttons[button] = pressed;
    }

    void JoyStick::setAxisMoved(Axis axis, float position)
    {
        _axis[axis] = position;
    }

    bool JoyStick::isConnected() const
    {
        return _isConnected;
    }

    bool JoyStick::isButtonPressed(Button button) const
    {
        return _buttons.at(button);
    }

    bool JoyStick::isJoyStickMoved() const
    {
        for (const auto &axis : _axis) {
            if (axis.second != 0)
                return true;
        }
        return false;
    }

    bool JoyStick::isJoyStickMoved(Axis axis) const
    {
        return _axis.at(axis) != 0;
    }

    float JoyStick::getAxisPosition(Axis axis) const
    {
        return _axis.at(axis);
    }
}

