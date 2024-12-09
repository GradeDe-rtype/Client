/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_FONT_SFML_HPP_
#define GRADE_DE_FONT_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Graphics.hpp>
#include "GradeDe/Error.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    class Font
    {
        public:
            Font() = default;
            ~Font() = default;

            void load(const std::string &path);

            void *getFont();

        private:
            sf::Font _font;
    };
} // namespace gd

#endif /* !GRADE_DE_FRAMERATE_SFML_HPP_ */
