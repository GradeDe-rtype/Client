/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_PRIMITIVE_TYPE_SFML_HPP_
#define GRADE_DE_PRIMITIVE_TYPE_SFML_HPP_

#include <SFML/Graphics.hpp>

namespace gd
{
    enum PrimitiveType {
        Points = sf::Points,
        Lines = sf::Lines,
        LineStrip = sf::LineStrip,
        Triangles = sf::Triangles,
        TriangleStrip = sf::TriangleStrip,
        TriangleFan = sf::TriangleFan,
        Quads = sf::Quads
    };
} // namespace gd

#endif /* !GRADE_DE_PRIMITIVE_TYPE_SFML_HPP_ */
