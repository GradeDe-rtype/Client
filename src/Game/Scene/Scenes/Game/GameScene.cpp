/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GameScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scene
        {
            void Game::load(gd::Window &window)
            {
                _starBackground = std::make_unique<RType::Game::Components::StarsBackground>(window);
                _waveIndicators = std::make_unique<RType::Game::Components::WaveIndicators>(window);
            }

            std::string Game::handleEvent(gd::Window &window, gd::Event &event)
            {
                _waveIndicators->handleEvent(window, event);

                gd::Vector2<float> position = RType::Ressources::get()->me->shape().getPosition();
                gd::Vector2<float> size = RType::Ressources::get()->me->shape().getSize();

                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Space) == gd::KeyBoard::State::Pressed) {
                    if (RType::Ressources::get()->me->getShootCooldown() == 0) {
                        RType::Ressources::get()->me->shoot();
                        int x = RType::Ressources::get()->me->shape().getPosition().x + RType::Ressources::get()->me->shape().getSize().x / 2;
                        int y = RType::Ressources::get()->me->shape().getPosition().y;
                        RType::Ressources::get()->shoots.push_back(std::make_unique<RType::Game::Entity::Shoot>(x, y));
                        std::unordered_map<std::string, std::string> tmp;
                        tmp["x"] = std::to_string(x);
                        tmp["y"] = std::to_string(y);
                        RType::Ressources::get()->sendList->push("shoot " + rfcArgParser::CreateObject(tmp));
                    }
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed && position.y >= size.y / 2) position.y -= RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed && position.y <= window.getHeight() - size.y / 2) position.y += RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed && position.x >= size.x / 2) position.x -= RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed && position.x <= window.getWidth() - size.x) position.x += RType::Ressources::get()->me->getSpeed();
                if (event.joyStick().isConnected()) {
                    if (event.joyStick().getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
                    if (event.joyStick().isJoyStickMoved()) {
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) position.x += RType::Ressources::get()->me->getSpeed() * event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                        if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) position.y += RType::Ressources::get()->me->getSpeed() * event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                    }
                }
                RType::Ressources::get()->me->setGoto(position.x, position.y);
                return "";
            }

            void Game::draw(gd::Window &window)
            {
                _starBackground->draw(window);
                window.draw(RType::Ressources::get()->me->shape());
                for (auto &player : RType::Ressources::get()->players)
                    window.draw(player.second->shape());
                for (auto &shoot : RType::Ressources::get()->shoots)
                    window.draw(shoot->shape());
                for (auto &enemy : RType::Ressources::get()->enemies)
                    window.draw(enemy.second->shape());
                _waveIndicators->draw(window);
            }

            void Game::update(gd::Window &window)
            {
                _waveIndicators->update(window);
                _starBackground->update(window);
                RType::Ressources::get()->me->update();
                for (auto &player : RType::Ressources::get()->players)
                    player.second->update();
                for (int i = 0; i < (int)RType::Ressources::get()->shoots.size(); i++) {
                    RType::Ressources::get()->shoots[i]->update();
                    if (RType::Ressources::get()->shoots[i]->getX() > window.getWidth() || RType::Ressources::get()->shoots[i]->getX() < 0) {
                        RType::Ressources::get()->shoots.erase(RType::Ressources::get()->shoots.begin() + i);
                        i--;
                    }
                }
            }
        } // namespace Scene
    } // namespace Game
} // namespace RType
