/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "EndIndicator.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            EndIndicator::EndIndicator(gd::Window &window)
            {
                int _currentWave = RType::Ressources::get()->wave;

                _endText = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("game.end.lose"), 1.8, gd::Color(255, 255, 255, 0));
                _endText->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _endText->getSize().x / 2), (float)(window.getHeight() / 3 - _endText->getSize().y / 2)});

                _wavesCompleted = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate(_endWin ? "game.end.wavesCompleted" : "game.end.wavesIncompleted"), 1.5, gd::Color(255, 255, 255, 0));
                _wavesCompleted->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _wavesCompleted->getSize().x / 2), (float)(window.getHeight() / 2 - _wavesCompleted->getSize().y / 2)});

                _pressEnter = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("game.end.pressEnterReplay"), 1, gd::Color(255, 255, 255, 0));
                _pressEnter->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _pressEnter->getSize().x / 2), (float)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});

                _fade.reset();
                _opacity = 0;
            }

            void EndIndicator::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END) {
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Pressed ||
                        event.joyStick.getButtonState(gd::JoyStick::Button::Y) == gd::JoyStick::State::Pressed) {
                        RType::Ressources::get()->roomState = RType::Ressources::RoomState::GAME;
                        RType::Ressources::get()->wave = 1;
                        for (auto &player : RType::Ressources::get()->players)
                            if (!player.second->getIsAlive())
                                player.second->respawn();
                    }
                }
            }

            void EndIndicator::draw(gd::Window &window)
            {
                _endText->draw(window);
                _wavesCompleted->draw(window);
                _pressEnter->draw(window);
            }

            void EndIndicator::update(gd::Window &window)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END) {
                    _endWin = RType::Ressources::get()->endWin;
                    _endText->setText(Traductor::get()->translate(_endWin ? "game.end.win" : "game.end.lose"));
                    _endText->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _endText->getSize().x / 2), (float)(window.getHeight() / 3 - _endText->getSize().y / 2)});
                    _wavesCompleted->setText(Traductor::get()->translate(_endWin ? "game.end.wavesCompleted" : "game.end.wavesIncompleted"));
                    _wavesCompleted->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _wavesCompleted->getSize().x / 2), (float)(window.getHeight() / 2 - _wavesCompleted->getSize().y / 2)});
                }

                if (_fade.getElapsedTime() >= _fadeTime) {
                    if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END)
                        _opacity = (_opacity + _fadeSpeed < 255) ? _opacity + _fadeSpeed : 255;
                    else
                        _opacity = (_opacity - _fadeSpeed > 0) ? _opacity - _fadeSpeed : 0;
                    _endText->setColor(gd::Color(255, 255, 255, _opacity));
                    _wavesCompleted->setColor(gd::Color(255, 255, 255, _opacity));
                    _pressEnter->setColor(gd::Color(255, 255, 255, _opacity));
                    _fade.reset();
                }
            }

            void EndIndicator::reload(gd::Window &window)
            {
                _endText->reload(window);
                _wavesCompleted->reload(window);
                _pressEnter->reload(window);

                _endText->setText(Traductor::get()->translate("game.end.lose"));
                _wavesCompleted->setText(Traductor::get()->translate(_endWin ? "game.end.wavesCompleted" : "game.end.wavesIncompleted"));
                _pressEnter->setText(Traductor::get()->translate("game.end.pressEnterReplay"));

                _endText->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _endText->getSize().x / 2), (float)(window.getHeight() / 3 - _endText->getSize().y / 2)});
                _wavesCompleted->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _wavesCompleted->getSize().x / 2), (float)(window.getHeight() / 2 - _wavesCompleted->getSize().y / 2)});
                _pressEnter->setPosition((gd::Vector2<float>){(float)(window.getWidth() / 2 - _pressEnter->getSize().x / 2), (float)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
