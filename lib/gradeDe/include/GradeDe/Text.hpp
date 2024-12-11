/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_TEXT_SFML_HPP_
#define GRADE_DE_TEXT_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Graphics.hpp>
#include "GradeDe/Color.hpp"
#include "GradeDe/Error.hpp"
#include "GradeDe/Font.hpp"
#include "GradeDe/Vector.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    class Text
    {
        public:
            enum Style {
                Regular = sf::Text::Regular,
                Bold = sf::Text::Bold,
                Italic = sf::Text::Italic,
                Underlined = sf::Text::Underlined,
                StrikeThrough = sf::Text::StrikeThrough
            };

            Text() = default;
            ~Text() = default;

            void setCharacterSize(unsigned int size);
            void setColor(const gd::Color &color);
            void setFont(const gd::Font &font);
            void setPosition(const gd::Vector2<int> &position);
            void setString(const std::string &string);
            void setStyle(Style style);

            unsigned int getCharacterSize() const;
            gd::Color getColor() const;
            gd::Font getFont() const;
            gd::Vector2<int> getPosition() const;
            std::string getString() const;
            Style getStyle() const;
            gd::Vector2<float> getSize() const;
            void *getText();

        private:
            sf::Text _text;
            std::string _string = "";
            Style _style = Regular;
            gd::Font _font;
            gd::Color _color = gd::Color::Black;
            unsigned int _size = 30;
            gd::Vector2<int> _position = {0, 0};
    };
} // namespace gd

#endif /* !GRADE_DE_FRAMERATE_SFML_HPP_ */
