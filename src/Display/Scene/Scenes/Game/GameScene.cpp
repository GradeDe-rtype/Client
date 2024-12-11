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
                _blaster.load("assets/sounds/blaster.mp3");
            }

            std::string Game::handleEvent(gd::Window &window, gd::Event &event)
            {
                bool orientationReset = true;
                gd::Vector2<float> position = RType::Ressources::get()->me().shape().getPosition();
                gd::Vector2<float> size = RType::Ressources::get()->me().shape().getSize();

                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Space) == gd::KeyBoard::State::Released) _blaster.play();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed && position.y >= size.y / 2) position.y -= RType::Ressources::get()->me().getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed && position.y <= window.getHeight() - size.y / 2) position.y += RType::Ressources::get()->me().getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed && position.x >= size.x / 2) position.x -= RType::Ressources::get()->me().getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed && position.x <= window.getWidth() - size.x) position.x += RType::Ressources::get()->me().getSpeed();
                if (event.joyStick().isConnected()) {
                    if (event.joyStick().getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
                    if (event.joyStick().isJoyStickMoved()) {
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) position.x += RType::Ressources::get()->me().getSpeed() * event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) position.y += RType::Ressources::get()->me().getSpeed() * event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                    }
                }
                RType::Ressources::get()->me().setGoto(position.x, position.y);
                return "";
            }

            void Game::draw(gd::Window &window)
            {
                window.draw(RType::Ressources::get()->me().shape());
                for (auto &player : RType::Ressources::get()->players())
                    window.draw(player.second->shape());
            }

            void Game::update()
            {
                RType::Ressources::get()->me().update();
                for (auto &player : RType::Ressources::get()->players())
                    player.second->update();
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
