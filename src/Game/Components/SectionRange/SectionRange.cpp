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

            void SectionRange::draw(gd::Window &window)
            {
                _text->draw(window);
                _range->draw(window);
            }

            void SectionRange::setPos(gd::Vector2<float> pos)
            {
                _text->setPosition((gd::Vector2<int>){(int)(pos.x), (int)(pos.y)});
                _range->setPosition(gd::Vector2<float>((float)(pos.x), (float)(_text->getPosition().y + _text->getSize().y + 20)));
            }

            float SectionRange::getSizeY() const
            {
                return _text->getSize().y + 10 + _range->getSize().y;
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
        } // namespace Components
    } // namespace Game
} // namespace RType
