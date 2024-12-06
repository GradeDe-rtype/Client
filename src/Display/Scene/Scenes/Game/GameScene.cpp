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

                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed && position.y >= size.y / 2) {
                    RType::Ressources::get()->me().move(0, -RType::Ressources::get()->me().getSpeed());
                    if (RType::Ressources::get()->me().shape().getRotation() > -30)
                        RType::Ressources::get()->me().shape().rotate(RType::Ressources::get()->me().shape().getRotation() > 0 ? -20 : -10);
                    orientationReset = false;
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed && position.y <= window.getHeight() - size.y / 2) {
                    RType::Ressources::get()->me().move(0, RType::Ressources::get()->me().getSpeed());
                    if (RType::Ressources::get()->me().shape().getRotation() < 30)
                        RType::Ressources::get()->me().shape().rotate(RType::Ressources::get()->me().shape().getRotation() < 0 ? 20 : 10);
                    orientationReset = false;
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed && position.x >= size.x / 2) RType::Ressources::get()->me().move(-15, 0);
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed && position.x <= window.getWidth() - size.x) RType::Ressources::get()->me().move(15, 0);
                if (event.joyStick().isConnected()) {
                    if (event.joyStick().getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
                    if (event.joyStick().isJoyStickMoved()) {
                        gd::Vector2<float> move = {0, 0};
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) {
                            float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                            move.x = RType::Ressources::get()->me().getSpeed() * percent;
                        }
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) {
                            float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                            move.y = RType::Ressources::get()->me().getSpeed() * percent;
                            RType::Ressources::get()->me().shape().setRotation(50 * percent);
                        }
                        RType::Ressources::get()->me().move(move.x, move.y);
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
                for (auto &player : RType::Ressources::get()->players())
                    player.second.shape().draw(window);
            }

            void Game::update()
            {
                for (auto &player : RType::Ressources::get()->players())
                    player.second.update();
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
