/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Shoot.hpp"

namespace RType
{
    namespace Display
    {
        Shoot::Shoot(int x, int y)
            : _x(x), _y(y)
        {
            float size = 20;
            _shape.create({{0, 0}, {size, size / 4}, {0, size / 2}, {size - size / 10, size / 4}});
            _shape.setOrigin({size / 2, size / 4});
            _shape.setFillColor(gd::Color::Cyan);
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
            _shape.setRotation(0);

            std::unordered_map<std::string, std::string> tmp;
            tmp["x"] = std::to_string(_x);
            tmp["y"] = std::to_string(_y);
        }

        gd::Shape &Shoot::shape()
        {
            return _shape;
        }

        void Shoot::setX(int x)
        {
            setPosition(x, _y);
        }

        void Shoot::setY(int y)
        {
            setPosition(_x, y);
        }

        void Shoot::setPosition(int x, int y)
        {
            if (_x == x && _y == y) return;
            _x = x;
            _y = y;
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
        }

        void Shoot::move(int x, int y)
        {
            setPosition(_x + x, _y + y);
        }

        int Shoot::getX() const
        {
            return _x;
        }

        int Shoot::getY() const
        {
            return _y;
        }

        void Shoot::update()
        {
            move(_speed, 0);
        }
    } // namespace Display
} // namespace RType