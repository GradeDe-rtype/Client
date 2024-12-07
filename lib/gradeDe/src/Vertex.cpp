/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GradeDe/Vertex.hpp"

namespace gd
{
    Vertex::Vertex(const gd::Vector2<float> &position, const gd::Color &color)
        : position(position), color(color)
    {
    }

    Vertex::Vertex(const gd::Vector2<float> &position, const gd::Color &color, const gd::Vector2<float> &texCoords)
        : position(position), color(color), texCoords(texCoords)
    {
    }

    void *Vertex::getVertex()
    {
        _sync();
        return &_vertex;
    }

    void Vertex::_sync()
    {
        _vertex.position = (sf::Vector2f){position.x, position.y};
        _vertex.color = sf::Color(color.r, color.g, color.b, color.a);
        _vertex.texCoords = (sf::Vector2f){texCoords.x, texCoords.y};
    }
} // namespace gd
