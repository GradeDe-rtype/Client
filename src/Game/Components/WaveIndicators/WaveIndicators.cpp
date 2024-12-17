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

                _font.load("assets/font/Karma Future.otf");
                _nextWave.setFont(_font);
                _nextWave.setCharacterSize(50);
                _nextWave.setString("Next Wave !");
                _nextWave.setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _nextWave.getSize().x / 2), (int)(window.getHeight() / 3 - _nextWave.getSize().y / 2)});
                _nextWave.setColor(gd::Color(255, 255, 255, 0));

                _waveUpgrade.setFont(_font);
                _waveUpgrade.setCharacterSize(40);
                _waveUpgrade.setString(std::to_string(_currentWave));
                _waveUpgrade.setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _waveUpgrade.getSize().x / 2), (int)(window.getHeight() / 2 - _waveUpgrade.getSize().y / 2)});
                _waveUpgrade.setColor(gd::Color(255, 255, 255, 0));

                _pressEnter.setFont(_font);
                _pressEnter.setCharacterSize(30);
                _pressEnter.setString("Press 'Enter' when you're ready !");
                _pressEnter.setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _pressEnter.getSize().x / 2), (int)(window.getHeight() / 3 * 2 - _pressEnter.getSize().y / 2)});
                _pressEnter.setColor(gd::Color(255, 255, 255, 0));

                _waveIndicator.setFont(_font);
                _waveIndicator.setCharacterSize(30);
                _waveIndicator.setString("Wave " + std::to_string(_currentWave));
                _waveIndicator.setPosition((gd::Vector2<int>){4, (int)(window.getHeight() - _waveIndicator.getSize().y - 8)});
                _waveIndicator.setColor(gd::Color(255, 255, 255, 255));

                _fade.reset();
                _opacity = 0;
            }

            void WaveIndicators::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::WAVE_WAITING) {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Pressed) {
                        RType::Ressources::get()->roomState = RType::Ressources::RoomState::WAVE_READY;
                        _currentWave = RType::Ressources::get()->wave;
                        _waveIndicator.setString("Wave " + std::to_string(_currentWave));
                    }
                }
            }

            void WaveIndicators::draw(gd::Window &window)
            {
                window.draw(_nextWave);
                window.draw(_waveUpgrade);
                window.draw(_pressEnter);
                if (_currentWave > 0) window.draw(_waveIndicator);
            }

            void WaveIndicators::update(gd::Window &window)
            {
                if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::NEXT_WAVE) {
                    _waveUpgrade.setString(std::to_string(_currentWave) + " -> " + std::to_string(RType::Ressources::get()->wave));
                    _waveUpgrade.setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _waveUpgrade.getSize().x / 2), (int)(window.getHeight() / 2 - _waveUpgrade.getSize().y / 2)});
                    int _currentWave = RType::Ressources::get()->wave;
                    RType::Ressources::get()->roomState = RType::Ressources::RoomState::WAVE_WAITING;
                }

                if (_fade.getElapsedTime() >= _fadeTime) {
                    if (RType::Ressources::get()->roomState == RType::Ressources::RoomState::WAVE_WAITING)
                        _opacity = (_opacity + _fadeSpeed < 255) ? _opacity + _fadeSpeed : 255;
                    else
                        _opacity = (_opacity - _fadeSpeed > 0) ? _opacity - _fadeSpeed : 0;
                    _nextWave.setColor(gd::Color(255, 255, 255, _opacity));
                    _waveUpgrade.setColor(gd::Color(255, 255, 255, _opacity));
                    _pressEnter.setColor(gd::Color(255, 255, 255, _opacity));
                    _waveIndicator.setColor(gd::Color(255, 255, 255, 255 - _opacity));
                    _fade.reset();
                }
            }
        } // namespace Components
    } // namespace Game
} // namespace RType