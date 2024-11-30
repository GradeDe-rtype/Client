/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "DisplayClient.hpp"

/*  ---- FUNCTION ---- */

namespace RType
{
    namespace Display
    {
        Client::Client(std::shared_ptr<RType::Communication::SendList> sendList) : _sendList(sendList)
        {
        }

        void Client::run()
        {
            RType::Ressources::get();
            _window.create(800, 600, "R-Type");
            RType::Ressources::get()->me().shape().setPosition({(float)(_window.getWidth() / 2 - RType::Ressources::get()->me().shape().getSize().x / 2), (float)(_window.getHeight() / 2 - RType::Ressources::get()->me().shape().getSize().y / 2)});

            while (_window.isOpen()) {
                if (_time.getElapsedTime() < gd::FrameRate::get().fps()) continue;
                _time.reset();
                _window.pollEvent(_event);
                _handleEvent();
                _window.clear(gd::Color::Black);

                RType::Ressources::get()->me().shape().draw(_window);
                _window.display();
            }
            _window.close();
        }

        void Client::_handleEvent()
        {
            bool orientationReset = true;
            gd::Vector2<float> position = RType::Ressources::get()->me().shape().getPosition();
            gd::Vector2<float> size = RType::Ressources::get()->me().shape().getSize();

            if (_event.close()) _window.close();
            if (_event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape)) _window.close();
            if (_event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) && position.y >= size.y / 2) {
                RType::Ressources::get()->me().shape().move({0, -15});
                if (RType::Ressources::get()->me().shape().getRotation() > -30)
                    RType::Ressources::get()->me().shape().rotate(-10);
                orientationReset = false;
                _sendList->push("UP");
            }
            if (_event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) && position.y <= _window.getHeight() - size.y / 2) {
                RType::Ressources::get()->me().shape().move({0, 15});
                if (RType::Ressources::get()->me().shape().getRotation() < 30)
                    RType::Ressources::get()->me().shape().rotate(10);
                orientationReset = false;
                _sendList->push("DOWN");
            }
            if (_event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) && position.x >= size.x / 2) {
                RType::Ressources::get()->me().shape().move({-15, 0});
                _sendList->push("LEFT");
            }
            if (_event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) && position.x <= _window.getWidth() - size.x) {
                RType::Ressources::get()->me().shape().move({15, 0});
                _sendList->push("RIGHT");
            }
            if (_event.joyStick().isConnected()) {
                if (_event.joyStick().isButtonPressed(gd::JoyStick::Button::Home)) _window.close();
                if (_event.joyStick().isJoyStickMoved()) {
                    gd::Vector2<float> move = {0, 0};
                    if (_event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) {
                        float percent = _event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                        move.x = 15 * percent;
                    }
                    if (_event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) {
                        float percent = _event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                        move.y = 15 * percent;
                        orientationReset = false;
                        if (move.y > 0) {
                            if (RType::Ressources::get()->me().shape().getRotation() < 30)
                                RType::Ressources::get()->me().shape().rotate(10);
                            _sendList->push("DOWN");
                        }
                        if (move.y < 0) {
                            if (RType::Ressources::get()->me().shape().getRotation() > -30)
                                RType::Ressources::get()->me().shape().rotate(-10);
                            _sendList->push("UP");
                        }
                    }
                    RType::Ressources::get()->me().shape().move(move);
                }
            }
            if (orientationReset) {
                if (RType::Ressources::get()->me().shape().getRotation() > 0) {
                    if (RType::Ressources::get()->me().shape().getRotation() < 8)
                        RType::Ressources::get()->me().shape().setRotation(0);
                    else
                        RType::Ressources::get()->me().shape().rotate(-8);
                }
                if (RType::Ressources::get()->me().shape().getRotation() < 0) {
                    if (RType::Ressources::get()->me().shape().getRotation() > -8)
                        RType::Ressources::get()->me().shape().setRotation(0);
                    else
                        RType::Ressources::get()->me().shape().rotate(8);
                }
            }
        }
    } // namespace Display
} // namespace RType
