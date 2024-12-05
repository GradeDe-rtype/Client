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

        for (Button button = Button::A; button < Button::ButtonCount; button = static_cast<Button>(button + 1))
            _buttons[button] = std::make_tuple(State::None, gd::Time());

        for (Axis axis = Axis::LeftJoyStickX; axis < Axis::AxisCount; axis = static_cast<Axis>(axis + 1))
            _axis[axis] = 0;
    }

    void JoyStick::setConnected(bool connected)
    {
        _isConnected = connected;
    }

    void JoyStick::setButtonState(Button button, JoyStick::State state)
    {
        if (_buttons.find(button) == _buttons.end()) return;
        std::get<0>(_buttons.at(button)) = state;
        std::get<1>(_buttons.at(button)).reset();
    }

    void JoyStick::setAxisMoved(Axis axis, float position)
    {
        _axis[axis] = position;
    }

    bool JoyStick::isConnected() const
    {
        return _isConnected;
    }

    JoyStick::State JoyStick::getButtonState(Button button)
    {
        if (_buttons.find(button) == _buttons.end()) return State::None;
        if (std::get<0>(_buttons.at(button)) == State::Released) {
            if (std::get<1>(_buttons.at(button)).getElapsedTime() >= 100)
                setButtonState(button, State::None);
            return std::get<0>(_buttons.at(button));
        }
        return std::get<0>(_buttons.at(button));
    }

    bool JoyStick::isJoyStickMoved() const
    {
        for (const auto &axis : _axis)
            if (axis.second != 0) return true;
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
} // namespace gd
