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
        unsigned int max = sf::Joystick::Count;
        for (unsigned int i = 0; i < (unsigned int)max; i++)
            _joySticks.push_back(std::make_pair(i, gd::JoyStick(i)));
    }

    void Event::handleEvent(void *event)
    {
        _event = *static_cast<sf::Event *>(event);

        switch (_event.type) {
            case sf::Event::Closed:
                _close = true;
                break;
            case sf::Event::KeyPressed:
                _keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), true);
                break;
            case sf::Event::KeyReleased:
                _keyBoard.setKeyState(static_cast<gd::KeyBoard::Key>(_event.key.code), false);
                break;
            case sf::Event::MouseButtonPressed:
                _mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), true);
                break;
            case sf::Event::MouseButtonReleased:
                _mouse.setButtonState(static_cast<gd::Mouse::Button>(_event.mouseButton.button), false);
                break;
            case sf::Event::JoystickConnected:
                for (auto &joyStick : _joySticks)
                    if (joyStick.first == _event.joystickConnect.joystickId)
                        joyStick.second.setConnected(true);
                break;
            case sf::Event::JoystickDisconnected:
                for (auto &joyStick : _joySticks)
                    if (joyStick.first == _event.joystickConnect.joystickId)
                        joyStick.second.setConnected(false);
                break;
            case sf::Event::JoystickButtonPressed:
                for (auto &joyStick : _joySticks)
                    if (joyStick.first == _event.joystickButton.joystickId)
                        joyStick.second.setButtonPressed(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), true);
                break;
            case sf::Event::JoystickButtonReleased:
                for (auto &joyStick : _joySticks)
                    if (joyStick.first == _event.joystickButton.joystickId)
                        joyStick.second.setButtonPressed(static_cast<gd::JoyStick::Button>(_event.joystickButton.button), false);
                break;
            case sf::Event::JoystickMoved:
                for (auto &joyStick : _joySticks)
                    if (joyStick.first == _event.joystickMove.joystickId)
                        joyStick.second.setAxisMoved(static_cast<gd::JoyStick::Axis>(_event.joystickMove.axis), _event.joystickMove.position);
                break;
            default:
                break;
        }
    }


    bool Event::close() const
    {
        return _close;
    }

    gd::JoyStick Event::joyStick(unsigned int id) const
    {
        for (const auto &joyStick : _joySticks)
            if (joyStick.first == id)
                return joyStick.second;
        return gd::JoyStick(0);
    }

    gd::KeyBoard Event::keyBoard() const
    {
        return _keyBoard;
    }

    gd::Mouse Event::mouse() const
    {
        return _mouse;
    }
}

