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
            Enemy::Enemy(int id, Enemy::Type type, float x, float y, int health)
            {
                _id = id;
                _position = {x, y};
                _health = health;

                _size = 40;
                _type = type;
                _createMonsterShape();
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(gd::Color::Magenta);
                _shape.setOutlineThickness(5);
                _shape.setPosition(_position);
                _shape.setRotation(0);
            }

            void Enemy::_createMonsterShape()
            {
                switch (_type) {
                    case Type::KAMIKAZE_MONSTER:
                        _createKamikazeMonster();
                        break;
                    case Type::BASIC_MONSTER:
                        _createBasicMonster();
                        break;
                }
            }

            void Enemy::_createBasicMonster()
            {
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size / 2), static_cast<float>(_size)},
                    {static_cast<float>(0), static_cast<float>(_size / 2)},
                });
            }

            void Enemy::_createKamikazeMonster()
            {
                _shape.create({
                    {static_cast<float>(0), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size)},
                });
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType