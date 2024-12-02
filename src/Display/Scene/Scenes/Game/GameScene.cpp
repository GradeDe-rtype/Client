/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GameScene.hpp"

namespace RType
{
    namespace Display
    {
        namespace Scene
        {
            void Game::load(gd::Window &window)
            {
            }

            void Game::unload()
            {
            }

            std::string Game::handleEvent(gd::Window &window, gd::Event &event)
            {
                bool orientationReset = true;
                gd::Vector2<float> position = RType::Ressources::get()->me().shape().getPosition();
                gd::Vector2<float> size = RType::Ressources::get()->me().shape().getSize();

                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape)) return "menu";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) && position.y >= size.y / 2) {
                    RType::Ressources::get()->me().shape().move({0, -15});
                    if (RType::Ressources::get()->me().shape().getRotation() > -30)
                        RType::Ressources::get()->me().shape().rotate(-10);
                    orientationReset = false;
                    RType::Ressources::get()->sendList()->push("UP");
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) && position.y <= window.getHeight() - size.y / 2) {
                    RType::Ressources::get()->me().shape().move({0, 15});
                    if (RType::Ressources::get()->me().shape().getRotation() < 30)
                        RType::Ressources::get()->me().shape().rotate(10);
                    orientationReset = false;
                    RType::Ressources::get()->sendList()->push("DOWN");
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) && position.x >= size.x / 2) {
                    RType::Ressources::get()->me().shape().move({-15, 0});
                    RType::Ressources::get()->sendList()->push("LEFT");
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) && position.x <= window.getWidth() - size.x) {
                    RType::Ressources::get()->me().shape().move({15, 0});
                    RType::Ressources::get()->sendList()->push("RIGHT");
                }
                if (event.joyStick().isConnected()) {
                    if (event.joyStick().isButtonPressed(gd::JoyStick::Button::Home)) window.close();
                    if (event.joyStick().isJoyStickMoved()) {
                        gd::Vector2<float> move = {0, 0};
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) {
                            float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                            move.x = 15 * percent;
                        }
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) {
                            float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                            move.y = 15 * percent;
                            orientationReset = false;
                            if (move.y > 0) {
                                if (RType::Ressources::get()->me().shape().getRotation() < 30)
                                    RType::Ressources::get()->me().shape().rotate(10);
                                RType::Ressources::get()->sendList()->push("DOWN");
                            }
                            if (move.y < 0) {
                                if (RType::Ressources::get()->me().shape().getRotation() > -30)
                                    RType::Ressources::get()->me().shape().rotate(-10);
                                RType::Ressources::get()->sendList()->push("UP");
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
                return "";
            }

            void Game::draw(gd::Window &window)
            {
                RType::Ressources::get()->me().shape().draw(window);
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
