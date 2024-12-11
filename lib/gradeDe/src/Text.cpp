/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Text.hpp"

namespace gd
{
    void Text::setCharacterSize(unsigned int size)
    {
        _size = size;
        _text.setCharacterSize(size);
    }

    void Text::setColor(const gd::Color &color)
    {
        _color = color;
        _text.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    }

    void Text::setFont(const gd::Font &font)
    {
        _font = font;
        _text.setFont(*(sf::Font *)_font.getFont());
    }

    void Text::setPosition(const gd::Vector2<int> &position)
    {
        _position = position;
        _text.setPosition(position.x, position.y);
    }

    void Text::setString(const std::string &string)
    {
        _string = string;
        _text.setString(string);
    }

    void Text::setStyle(Style style)
    {
        _style = style;
        _text.setStyle(style);
    }

    unsigned int Text::getCharacterSize() const
    {
        return _size;
    }

    gd::Color Text::getColor() const
    {
        return _color;
    }

    gd::Font Text::getFont() const
    {
        return _font;
    }

    gd::Vector2<int> Text::getPosition() const
    {
        return _position;
    }

    std::string Text::getString() const
    {
        return _string;
    }

    Text::Style Text::getStyle() const
    {
        return _style;
    }

    gd::Vector2<float> Text::getSize() const
    {
        sf::FloatRect rect = _text.getGlobalBounds();
        gd::Vector2<float> size(rect.width, rect.height);
        return size;
    }

    void *Text::getText()
    {
        return &_text;
    }
} // namespace gd
