/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Mouse.hpp"

namespace gd
{
    Mouse::Mouse()
    {
        for (Button button = Button::Left; button < Button::ButtonCount; button = static_cast<Button>(button + 1))
            _buttons[button] = std::make_tuple(State::None, gd::Time());
    }

    void Mouse::setButtonState(Button button, Mouse::State state)
    {
        if (_buttons.find(button) == _buttons.end()) return;
        std::get<0>(_buttons.at(button)) = state;
        std::get<1>(_buttons.at(button)).reset();
    }

    Mouse::State Mouse::getButtonState(Button button)
    {
        if (_buttons.find(button) == _buttons.end()) return State::None;
        if (std::get<0>(_buttons.at(button)) == State::Released) {
            if (std::get<1>(_buttons.at(button)).getElapsedTime() >= 100)
                setButtonState(button, State::None);
            return std::get<0>(_buttons.at(button));
        }
        return std::get<0>(_buttons.at(button));
    }

    gd::Vector2<int> Mouse::getPosition(gd::Window &window) const
    {
        sf::RenderWindow *sfmlWindow = (sf::RenderWindow *)window.getWindow();
        return gd::Vector2<int>(sf::Mouse::getPosition(*sfmlWindow).x, sf::Mouse::getPosition(*sfmlWindow).y);
    }
} // namespace gd
