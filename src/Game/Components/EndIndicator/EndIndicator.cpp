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

                _endText = std::make_unique<RType::Game::Components::Text>("Karma Future", "End !", 50, gd::Color(255, 255, 255, 0));
                _endText->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _endText->getSize().x / 2), (int)(window.getHeight() / 3 - _endText->getSize().y / 2)});

                _scoreText = std::make_unique<RType::Game::Components::Text>("Karma Future", std::to_string(_endScore), 40, gd::Color(255, 255, 255, 0));
                _scoreText->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _scoreText->getSize().x / 2), (int)(window.getHeight() / 2 - _scoreText->getSize().y / 2)});

                _pressEnter = std::make_unique<RType::Game::Components::Text>("Karma Future", "Press 'Enter' when you want to replay !", 30, gd::Color(255, 255, 255, 0));
                _pressEnter->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _pressEnter->getSize().x / 2), (int)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});

                _fade.reset();
                _opacity = 0;
            }

            void EndIndicator::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END) {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Pressed) {
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
                _scoreText->draw(window);
                _pressEnter->draw(window);
            }

            void EndIndicator::update(gd::Window &window)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END) {
                    _endScore = RType::Ressources::get()->endScore;
                    _endText->setText((_endScore >= 5) ? "You win !" : "You lose !");
                    _endText->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _endText->getSize().x / 2), (int)(window.getHeight() / 3 - _endText->getSize().y / 2)});
                    _scoreText->setText(std::to_string(_endScore) + " / 5 waves completed !");
                    _scoreText->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _scoreText->getSize().x / 2), (int)(window.getHeight() / 2 - _scoreText->getSize().y / 2)});
                }

                if (_fade.getElapsedTime() >= _fadeTime) {
                    if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::END)
                        _opacity = (_opacity + _fadeSpeed < 255) ? _opacity + _fadeSpeed : 255;
                    else
                        _opacity = (_opacity - _fadeSpeed > 0) ? _opacity - _fadeSpeed : 0;
                    _endText->setColor(gd::Color(255, 255, 255, _opacity));
                    _scoreText->setColor(gd::Color(255, 255, 255, _opacity));
                    _pressEnter->setColor(gd::Color(255, 255, 255, _opacity));
                    _fade.reset();
                }
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
