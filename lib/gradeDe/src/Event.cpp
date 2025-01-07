/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Event.hpp"

namespace gd
{
    Event::Event()
    {
        for (unsigned int i = 0; i < 100; i++) {
            if (sf::Joystick::isConnected(i)) {
                joyStick.setConnected(true);
                break;
            }
        }
    }

    void Event::handleEvent(void *event)
    {
        _event = *static_cast<sf::Event *>(event);

        switch (_event.type) {
            case sf::Event::Closed:
                _close = true;
                break;
            case sf::Event::KeyPressed:
                keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), gd::KeyBoard::State::Pressed);
                break;
            case sf::Event::KeyReleased:
                keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), gd::KeyBoard::State::Released);
                break;
            case sf::Event::MouseButtonPressed:
                mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), gd::Mouse::State::Pressed);
                break;
            case sf::Event::MouseButtonReleased:
                mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), gd::Mouse::State::Released);
                break;
            case sf::Event::JoystickConnected:
                joyStick.setConnected(true);
                break;
            case sf::Event::JoystickDisconnected:
                joyStick.setConnected(false);
                break;
            case sf::Event::JoystickButtonPressed:
                joyStick.setButtonState(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), gd::JoyStick::State::Pressed);
                break;
            case sf::Event::JoystickButtonReleased:
                joyStick.setButtonState(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), gd::JoyStick::State::Released);
                break;
            case sf::Event::JoystickMoved:
                joyStick.setAxisMoved(static_cast<gd::JoyStick::Axis>(_event.joystickMove.axis), _event.joystickMove.position);
                break;
            default:
                break;
        }
    }

    bool Event::close() const
    {
        return _close;
    }
} // namespace gd
