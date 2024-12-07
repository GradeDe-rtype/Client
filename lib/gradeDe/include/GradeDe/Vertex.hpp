/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_VERTEX_SFML_HPP_
#define GRADE_DE_VERTEX_SFML_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GradeDe/Color.hpp"
#include "GradeDe/Vector.hpp"

namespace gd
{
    class Vertex
    {
        public:
            Vertex() = default;
            Vertex(const gd::Vector2<float> &position, const gd::Color &color);
            Vertex(const gd::Vector2<float> &position, const gd::Color &color, const gd::Vector2<float> &texCoords);
            ~Vertex() = default;

            gd::Vector2<float> position = {0, 0};
            gd::Color color = gd::Color::White;
            gd::Vector2<float> texCoords = {0, 0};

            void *getVertex();

        private:
            void _sync();
            sf::Vertex _vertex;
    };
} // namespace gd

#endif /* !GRADE_DE_VERTEX_SFML_HPP_ */
