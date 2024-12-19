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
                _joyStick.setConnected(true);
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
                _keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), gd::KeyBoard::State::Pressed);
                break;
            case sf::Event::KeyReleased:
                _keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), gd::KeyBoard::State::Released);
                break;
            case sf::Event::MouseButtonPressed:
                _mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), gd::Mouse::State::Pressed);
                break;
            case sf::Event::MouseButtonReleased:
                _mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), gd::Mouse::State::Released);
                break;
            case sf::Event::JoystickConnected:
                _joyStick.setConnected(true);
                break;
            case sf::Event::JoystickDisconnected:
                _joyStick.setConnected(false);
                break;
            case sf::Event::JoystickButtonPressed:
                _joyStick.setButtonState(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), gd::JoyStick::State::Pressed);
                break;
            case sf::Event::JoystickButtonReleased:
                _joyStick.setButtonState(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), gd::JoyStick::State::Released);
                break;
            case sf::Event::JoystickMoved:
                _joyStick.setAxisMoved(static_cast<gd::JoyStick::Axis>(_event.joystickMove.axis), _event.joystickMove.position);
                break;
            default:
                break;
        }
    }

    bool Event::close() const
    {
        return _close;
    }

    gd::JoyStick Event::joyStick() const
    {
        return _joyStick;
    }

    gd::KeyBoard Event::keyBoard() const
    {
        return _keyBoard;
    }

    gd::Mouse Event::mouse() const
    {
        return _mouse;
    }
} // namespace gd
