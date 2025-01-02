/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Game/Components/Text/Text.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            Text::Text(std::string font, std::string text, float charactersize, gd::Color color, gd::Vector2<int> position)
            {
                _gdFont = Managers::Font::get().getFont(font);
                _text = text;
                _charactersize = charactersize;
                _position = position;
                _color = color;

                _gdText.setFont(_gdFont);
                _gdText.setString(text);
                _gdText.setCharacterSize(RType::Game::Managers::Accessibility::get().getTextSize() * charactersize);
                _gdText.setPosition(position);
                _gdText.setColor(color);
            }

            void Text::reload()
            {
                _gdText.setCharacterSize(RType::Game::Managers::Accessibility::get().getTextSize() * _charactersize);
            }

            void Text::draw(gd::Window &window)
            {
                window.draw(_gdText);
            }

            void Text::setCharacterSize(int charactersize)
            {
                _charactersize = charactersize;
                _gdText.setCharacterSize(RType::Game::Managers::Accessibility::get().getTextSize() * charactersize);
            }

            void Text::setColor(gd::Color color)
            {
                _color = color;
                _gdText.setColor(_color);
            }

            void Text::setPosition(gd::Vector2<int> position)
            {
                _position = position;
                _gdText.setPosition(_position);
            }

            void Text::setText(std::string text)
            {
                _text = text;
                _gdText.setString(_text);
            }

            gd::Vector2<int> Text::getPosition() const
            {
                return _position;
            }

            int Text::getCharacterSize() const
            {
                return _charactersize;
            }

            gd::Color Text::getColor() const
            {
                return _color;
            }

            gd::Vector2<float> Text::getSize() const
            {
                return _gdText.getSize();
            }

            std::string Text::getText() const
            {
                return _text;
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
