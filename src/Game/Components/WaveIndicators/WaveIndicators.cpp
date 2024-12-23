/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "WaveIndicators.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            WaveIndicators::WaveIndicators(gd::Window &window)
            {
                int _currentWave = RType::Ressources::get()->wave;

                _nextWave = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("game.wave.nextWave"), 50, gd::Color(255, 255, 255, 0));
                _nextWave->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _nextWave->getSize().x / 2), (int)(window.getHeight() / 3 - _nextWave->getSize().y / 2)});

                _waveUpgrade = std::make_unique<RType::Game::Components::Text>("Karma Future", std::to_string(_currentWave), 40, gd::Color(255, 255, 255, 0));
                _waveUpgrade->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _waveUpgrade->getSize().x / 2), (int)(window.getHeight() / 2 - _waveUpgrade->getSize().y / 2)});

                _pressEnter = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("game.wave.pressEnterReady"), 30, gd::Color(255, 255, 255, 0));
                _pressEnter->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _pressEnter->getSize().x / 2), (int)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});

                std::string text = Traductor::get()->translate("game.wave.wave");
                text.replace(text.find("{value}"), 7, std::to_string(_currentWave));
                _waveIndicator = std::make_unique<RType::Game::Components::Text>("Karma Future", text, 30, gd::Color(255, 255, 255, 255));
                _waveIndicator->setPosition((gd::Vector2<int>){4, (int)(window.getHeight() - _waveIndicator->getSize().y - 8)});

                _fade.reset();
                _opacity = 0;
            }

            void WaveIndicators::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::WAVE_WAITING) {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Pressed) {
                        RType::Ressources::get()->roomState = RType::Ressources::RoomState::WAVE_READY;
                        _currentWave = RType::Ressources::get()->wave;
                        std::string text = Traductor::get()->translate("game.wave.wave");
                        text.replace(text.find("{value}"), 7, std::to_string(_currentWave));
                        _waveIndicator->setText(text);
                    }
                }
            }

            void WaveIndicators::draw(gd::Window &window)
            {
                _nextWave->draw(window);
                _waveUpgrade->draw(window);
                _pressEnter->draw(window);
                if (_currentWave > 0) _waveIndicator->draw(window);
            }

            void WaveIndicators::update(gd::Window &window)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::NEXT_WAVE) {
                    _waveUpgrade->setText(std::to_string(_currentWave) + " -> " + std::to_string(RType::Ressources::get()->wave));
                    _waveUpgrade->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _waveUpgrade->getSize().x / 2), (int)(window.getHeight() / 2 - _waveUpgrade->getSize().y / 2)});
                    int _currentWave = RType::Ressources::get()->wave;
                    RType::Ressources::get()->roomState = RType::Ressources::RoomState::WAVE_WAITING;
                }

                if (_fade.getElapsedTime() >= _fadeTime) {
                    if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::WAVE_WAITING)
                        _opacity = (_opacity + _fadeSpeed < 255) ? _opacity + _fadeSpeed : 255;
                    else
                        _opacity = (_opacity - _fadeSpeed > 0) ? _opacity - _fadeSpeed : 0;
                    _nextWave->setColor(gd::Color(255, 255, 255, _opacity));
                    _waveUpgrade->setColor(gd::Color(255, 255, 255, _opacity));
                    _pressEnter->setColor(gd::Color(255, 255, 255, _opacity));
                    _waveIndicator->setColor(gd::Color(255, 255, 255, 255 - _opacity));
                    _fade.reset();
                }
            }

            void WaveIndicators::reload(gd::Window &window)
            {
                _nextWave->setText(Traductor::get()->translate("game.wave.nextWave"));
                _waveUpgrade->setText(std::to_string(RType::Ressources::get()->wave));
                _pressEnter->setText(Traductor::get()->translate("game.wave.pressEnterReady"));
                std::string text = Traductor::get()->translate("game.wave.wave");
                text.replace(text.find("{value}"), 7, std::to_string(RType::Ressources::get()->wave));
                _waveIndicator->setText(text);

                _nextWave->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _nextWave->getSize().x / 2), (int)(window.getHeight() / 3 - _nextWave->getSize().y / 2)});
                _waveUpgrade->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _waveUpgrade->getSize().x / 2), (int)(window.getHeight() / 2 - _waveUpgrade->getSize().y / 2)});
                _pressEnter->setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _pressEnter->getSize().x / 2), (int)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
