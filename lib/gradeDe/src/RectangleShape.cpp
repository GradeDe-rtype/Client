/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/RectangleShape.hpp"

namespace gd
{
    void RectangleShape::create(gd::Vector2<float> size)
    {
        _size = size;
        _shape.setSize({size.x, size.y});
    }

    void RectangleShape::setFillColor(gd::Color color)
    {
        _fillColor = color;
        _shape.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    }

    void RectangleShape::setOutlineColor(gd::Color color)
    {
        _outlineColor = color;
        _shape.setOutlineColor(sf::Color(color.r, color.g, color.b, color.a));
    }

    void RectangleShape::setOutlineThickness(float thickness)
    {
        _outlineThickness = thickness;
        _shape.setOutlineThickness(thickness);
    }

    void RectangleShape::setPosition(gd::Vector2<float> position)
    {
        _position = position;
        _shape.setPosition(position.x, position.y);
    }

    void RectangleShape::setOrigin(gd::Vector2<float> origin)
    {
        _origin = origin;
        _shape.setOrigin(origin.x, origin.y);
    }

    void RectangleShape::setRotation(float angle)
    {
        _rotation = angle;
        _shape.setRotation(angle);
    }

    void RectangleShape::setTexture(gd::Texture &texture)
    {
        _shape.setTexture((sf::Texture *)texture.getTexture());
    }

    void RectangleShape::setSize(gd::Vector2<float> size)
    {
        _size = size;
        _shape.setSize({size.x, size.y});
    }

    void RectangleShape::setSizeX(float x)
    {
        setSize({x, _size.y});
    }

    void RectangleShape::setSizeY(float y)
    {
        setSize({_size.x, y});
    }

    void RectangleShape::move(gd::Vector2<float> offset)
    {
        _position += offset;
        _shape.move(offset.x, offset.y);
    }

    void RectangleShape::rotate(float angle)
    {
        _rotation += angle;
        _shape.setRotation(_rotation);
    }

    gd::Color RectangleShape::getFillColor() const
    {
        return _fillColor;
    }

    gd::Color RectangleShape::getOutlineColor() const
    {
        return _outlineColor;
    }

    float RectangleShape::getOutlineThickness() const
    {
        return _outlineThickness;
    }

    gd::Vector2<float> RectangleShape::getPosition() const
    {
        return _position;
    }

    gd::Vector2<float> RectangleShape::getSize() const
    {
        auto bounds = _shape.getGlobalBounds();
        return {bounds.width, bounds.height};
    }

    float RectangleShape::getRotation() const
    {
        return _rotation;
    }

    void *RectangleShape::getShape()
    {
        return &_shape;
    }
} // namespace gd
