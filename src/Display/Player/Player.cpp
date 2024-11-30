/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Player.hpp"

namespace RType
{
    namespace Display
    {
        Player::Player()
        {
            float size = 40;
            _shape.create({{0, 0}, {size, size / 2}, {0, size}, {size / 4, size / 2}});
            _shape.setOrigin({size / 2, size / 2});
            _shape.setFillColor(gd::Color::Transparent);
            _shape.setOutlineColor(gd::Color::White);
            _shape.setOutlineThickness(5);
        }

        gd::Shape &Player::shape()
        {
            return _shape;
        }
    } // namespace Display
} // namespace RType