/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SelectArrow.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            SelectArrow::SelectArrow(SelectArrow::Direction direction, gd::Color color, int size, gd::Vector2<float> position)
            {
                _position = position;
                _color = color;
                _direction = direction;

                _size = size;
                _shape.create({
                    {static_cast<float>(0), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size / 2)},
                    {static_cast<float>(0), static_cast<float>(_size)},
                });
                _shape.setOrigin({static_cast<float>(_size / 2), static_cast<float>(_size / 2)});
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(color);
                _shape.setOutlineThickness(3);
                _shape.setRotation(static_cast<float>(_direction));
                _shape.setPosition(_position);
            }

            void SelectArrow::setColor(std::string color)
            {
                setColor(gd::Color::fromHex(color));
            }

            void SelectArrow::setColor(gd::Color color)
            {
                _color = color;
                _shape.setOutlineColor(_color);
            }

            void SelectArrow::setDirection(SelectArrow::Direction direction)
            {
                _direction = direction;
                _shape.setRotation(static_cast<float>(_direction));
            }

            SelectArrow::Direction SelectArrow::getDirection() const
            {
                return _direction;
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType