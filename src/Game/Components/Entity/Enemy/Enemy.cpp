/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Enemy.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            Enemy::Enemy(int id, float x, float y, int health)
            {
                _id = id;
                _position = {x, y};
                _health = health;

                _size = 40;
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size / 2), static_cast<float>(_size)},
                    {static_cast<float>(0), static_cast<float>(_size / 2)},
                });
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(gd::Color::Magenta);
                _shape.setOutlineThickness(5);
                _shape.setPosition(_position);
                _shape.setRotation(0);
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType