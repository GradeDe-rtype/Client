/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Enemy.hpp"

namespace RType
{
    namespace Display
    {
        Enemy::Enemy(int id, int x, int y, int health)
            : _id(id), _x(x), _y(y), _health(health)
        {
            float size = 40;
            _shape.create({
                {size / 2, 0},
                {size, size / 2},
                {size / 2, size},
                {0, size / 2},
            });
            _shape.setOrigin({size / 2, size / 2});
            _shape.setFillColor(gd::Color::Transparent);
            _shape.setOutlineColor(gd::Color::Magenta);
            _shape.setOutlineThickness(5);
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
            _shape.setRotation(0);
        }

        gd::Shape &Enemy::shape()
        {
            return _shape;
        }

        void Enemy::setHealth(int health)
        {
            _health = health;
        }

        void Enemy::setX(int x)
        {
            setPosition(x, _y);
        }

        void Enemy::setY(int y)
        {
            setPosition(_x, y);
        }

        void Enemy::setPosition(int x, int y)
        {
            if (_x == x && _y == y) return;
            _x = x;
            _y = y;
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
        }

        void Enemy::move(int x, int y)
        {
            setPosition(_x + x, _y + y);
        }

        int Enemy::getId() const
        {
            return _id;
        }

        int Enemy::getHealth() const
        {
            return _health;
        }

        int Enemy::getX() const
        {
            return _x;
        }

        int Enemy::getY() const
        {
            return _y;
        }
    } // namespace Display
} // namespace RType