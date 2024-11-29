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
            _buttons[button] = false;
    }

    void Mouse::setButtonState(Button button, bool state)
    {
        _buttons[button] = state;
    }

    bool Mouse::getButtonState(Button button) const
    {
        return _buttons.at(button);
    }

    gd::Vector2<int> Mouse::getPosition(gd::Window &window) const
    {
        sf::RenderWindow *sfmlWindow = (sf::RenderWindow *)window.getWindow();
        return gd::Vector2<int>(sf::Mouse::getPosition(*sfmlWindow).x, sf::Mouse::getPosition(*sfmlWindow).y);
    }
}
