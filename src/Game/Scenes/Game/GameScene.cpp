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
        namespace Scenes
        {
            void Game::load(gd::Window &window)
            {
                _waveIndicators = std::make_unique<RType::Game::Components::WaveIndicators>(window);
                _endIndicator = std::make_unique<RType::Game::Components::EndIndicator>(window);
                _health = std::make_unique<RType::Game::Components::Range>(0, 100, 1, gd::Vector2<float>(4, 4), gd::Vector2<float>(100, 10));
                _health->setColor(gd::Color::fromHex("#900028"));
                _shotCooldown = std::make_unique<RType::Game::Components::Range>(0, 1, 1, gd::Vector2<float>(4, 22), gd::Vector2<float>(100, 10));
                _shotCooldown->setColor(gd::Color::fromHex("#1CA350"));
            }

            void Game::enter(gd::Window &window)
            {
                (void)window;
                _shotCooldown->setEnd(RType::Ressources::get()->me->getShootMaxCooldown());
            }

            std::string Game::handleEvent(gd::Window &window, gd::Event &event)
            {
                _waveIndicators->handleEvent(window, event);
                _endIndicator->handleEvent(window, event);

                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::ROOMS_LIST) {
                    RType::Ressources::get()->roomState = RType::Ressources::RoomState::GAME;
                    return "roomsList";
                }

                gd::Vector2<float> position = RType::Ressources::get()->me->shape().getPosition();
                gd::Vector2<float> size = RType::Ressources::get()->me->getSize();

                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Space) == gd::KeyBoard::State::Pressed)
                    if (RType::Ressources::get()->me->getShootCooldown() == 0) RType::Ressources::get()->me->shoot();
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed && position.y >= size.y / 2) position.y -= RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed && position.y <= window.getHeight() - size.y / 2) position.y += RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed && position.x >= size.x / 2) position.x -= RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed && position.x <= window.getWidth() - size.x) position.x += RType::Ressources::get()->me->getSpeed();
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Tab) == gd::KeyBoard::State::Pressed) _toggleHealthBar();
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
                    if (event.joyStick.isJoyStickMoved()) {
                        if (event.joyStick.isJoyStickMoved(gd::JoyStick::Axis::LX)) position.x += RType::Ressources::get()->me->getSpeed() * event.joyStick.getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                        if (event.joyStick.isJoyStickMoved(gd::JoyStick::Axis::LY)) position.y += RType::Ressources::get()->me->getSpeed() * event.joyStick.getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                    }
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Pressed)
                        if (RType::Ressources::get()->me->getShootCooldown() == 0) RType::Ressources::get()->me->shoot();
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::B) == gd::JoyStick::State::Pressed) _showHealthBar = true;
                }
                RType::Ressources::get()->me->setGoto(position.x, position.y);
                return "";
            }

            void Game::reload(gd::Window &window)
            {
                _waveIndicators->reload(window);
                _endIndicator->reload(window);
            }

            void Game::draw(gd::Window &window)
            {
                for (auto &player : RType::Ressources::get()->players)
                    player.second->draw(window);
                for (auto &enemy : RType::Ressources::get()->enemies)
                    enemy.second->draw(window);
                for (auto &from : RType::Ressources::get()->shoots)
                    for (auto &who : from.second)
                        for (auto &shoot : who.second)
                            shoot.second->draw(window);
                _waveIndicators->draw(window);
                _endIndicator->draw(window);
                _health->draw(window);
                if (_shotCooldown->getValue() > 0)
                    _shotCooldown->draw(window);
            }

            void Game::update(gd::Window &window)
            {
                _health->setValue(RType::Ressources::get()->me->getHealth());
                _shotCooldown->setValue(RType::Ressources::get()->me->getShootCooldown());
                _endIndicator->update(window);
                _waveIndicators->update(window);
                RType::Ressources::get()->me->update();
                for (auto &player : RType::Ressources::get()->players) {
                    player.second->showHealthBar(_showHealthBar);
                    player.second->update();
                }
                for (auto &enemy : RType::Ressources::get()->enemies) {
                    enemy.second->showHealthBar(_showHealthBar);
                    enemy.second->update();
                }
            }

            void Game::_toggleHealthBar()
            {
                if (_healthBarToggleTimer.getElapsedTime() < 200) return;
                _healthBarToggleTimer.reset();
                _showHealthBar = !_showHealthBar;
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
