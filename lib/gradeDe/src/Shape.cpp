/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Shape.hpp"

namespace gd
{
    void Shape::create(std::vector<gd::Vector2<float>> points)
    {
        _points = points;
        _shape.setPointCount(points.size());
        for (size_t i = 0; i < points.size(); i++)
            _shape.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
        _shape.setPosition(_position.x, _position.y);
    }

    void Shape::createRectangle(float width, float height)
    {
        _points = {
            {0, 0},
            {width, 0},
            {width, height},
            {0, height},
        };
        create(_points);
    }

    void Shape::setFillColor(gd::Color color)
    {
        _fillColor = color;
        _shape.setFillColor(sf::Color(color.r, color.g, color.b, color.a));
    }

    void Shape::setOutlineColor(gd::Color color)
    {
        _outlineColor = color;
        _shape.setOutlineColor(sf::Color(color.r, color.g, color.b, color.a));
    }

    void Shape::setOutlineThickness(float thickness)
    {
        _outlineThickness = thickness;
        _shape.setOutlineThickness(thickness);
    }

    void Shape::setPosition(gd::Vector2<float> position)
    {
        _position = position;
        _shape.setPosition(position.x, position.y);
    }

    void Shape::setOrigin(gd::Vector2<float> origin)
    {
        _origin = origin;
        _shape.setOrigin(origin.x, origin.y);
    }

    void Shape::setRotation(float angle)
    {
        _rotation = angle;
        _shape.setRotation(angle);
    }

    void Shape::setTexture(gd::Texture &texture)
    {
        _shape.setTexture((sf::Texture *)texture.getTexture());
    }

    void Shape::move(gd::Vector2<float> offset)
    {
        _position += offset;
        _shape.move(offset.x, offset.y);
    }

    void Shape::rotate(float angle)
    {
        _rotation += angle;
        _shape.setRotation(_rotation);
    }

    gd::Color Shape::getFillColor() const
    {
        return _fillColor;
    }

    gd::Color Shape::getOutlineColor() const
    {
        return _outlineColor;
    }

    float Shape::getOutlineThickness() const
    {
        return _outlineThickness;
    }

    gd::Vector2<float> Shape::getPosition() const
    {
        return _position;
    }

    gd::Vector2<float> Shape::getSize() const
    {
        auto bounds = _shape.getGlobalBounds();
        return {bounds.width, bounds.height};
    }

    float Shape::getRotation() const
    {
        return _rotation;
    }

    void *Shape::getShape()
    {
        return &_shape;
    }
} // namespace gd
