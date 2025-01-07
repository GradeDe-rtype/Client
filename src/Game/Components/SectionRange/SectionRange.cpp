/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SectionRange.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            SectionRange::SectionRange(std::string name, gd::Vector2<float> size, int start, int end, int step)
                : _name(name)
            {
                _text = std::make_shared<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate(name));
                _range = std::make_shared<RType::Game::Components::Range>(start, end, step, (gd::Vector2<float>){0, 0}, size);

                _text->setPosition({0, 0});
                _range->setPosition(gd::Vector2<float>((float)(0), (float)(_text->getPosition().y + _text->getSize().y + 10)));

                setColor(gd::Color(255, 255, 255, 150));
            }

            void SectionRange::reload(gd::Vector2<float> window)
            {
                setTextValue();
                _range->reload(window);
            }

            void SectionRange::draw(gd::Window &window)
            {
                _text->draw(window);
                _range->draw(window);
            }

            bool SectionRange::handleEvt(gd::Window &window, gd::Event &event)
            {
                if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Pressed) {
                    gd::Vector2<float> mouse = event.mouse.getPosition(window);
                    if (mouse.x >= _range->getPosition().x && mouse.x <= _range->getPosition().x + _range->getSize().x && mouse.y >= _range->getPosition().y && mouse.y <= _range->getPosition().y + _range->getSize().y) {
                        _range->setValuePercentage((mouse.x - _range->getPosition().x) / _range->getSize().x);
                        setTextValue();
                        setSettingValue();
                        RType::Game::Managers::Scenes::get().needToReload();
                        return true;
                    }
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) {
                    _changeRangeValue(-1);
                    return true;
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) {
                    _changeRangeValue(1);
                    return true;
                }
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getXAxisPosition(false) < -50) {
                        _changeRangeValue(-1);
                        return true;
                    }
                    if (event.joyStick.getXAxisPosition(true) > 50) {
                        _changeRangeValue(1);
                        return true;
                    }
                }
                return false;
            }

            void SectionRange::setPosition(gd::Vector2<float> position)
            {
                _position = position;
                _text->setPosition((gd::Vector2<float>){(float)(_position.x), (float)(_position.y)});
                _range->setPosition(gd::Vector2<float>((float)(_position.x), (float)(_text->getPosition().y + _text->getSize().y + 20)));
            }

            gd::Vector2<float> SectionRange::getSize() const
            {
                return {getSizeX(), getSizeY()};
            }

            float SectionRange::getSizeY() const
            {
                return _text->getSize().y + 10 + _range->getSize().y;
            }

            float SectionRange::getSizeX() const
            {
                float textX = _text->getSize().x;
                float rangeX = _range->getSize().x;
                return (textX > rangeX) ? textX : rangeX;
            }

            std::shared_ptr<RType::Game::Components::Range> SectionRange::range()
            {
                return _range;
            }

            void SectionRange::setColor(gd::Color color)
            {
                _text->setColor(color);
                _range->setColor(color);
            }

            void SectionRange::setTextValue()
            {
                std::string text = Traductor::get()->translate(_name);
                text.replace(text.find("{value}"), 7, std::to_string((int)_range->getValue()));
                _text->setText(text);
            }

            void SectionRange::setSettingValue()
            {
            }

            float SectionRange::getValue() const
            {
                return _range->getValue();
            }

            std::string SectionRange::getName() const
            {
                return _name;
            }

            std::string SectionRange::saveValue() const
            {
                return std::to_string((int)getValue());
            }

            void SectionRange::_changeRangeValue(int value)
            {
                if (_input.getElapsedTime() < 100) return;
                _input.reset();
                if (value < 0)
                    _range->downValue();
                else
                    _range->upValue();

                setTextValue();
                setSettingValue();
                RType::Game::Managers::Scenes::get().needToReload();
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
