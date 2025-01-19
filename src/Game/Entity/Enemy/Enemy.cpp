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
            Enemy::Enemy(int id, Enemy::Type type, float x, float y, int size, int health)
            {
                _id = id;
                _position = {x, y};
                _health = health;

                _size = size;
                _type = type;
                _createMonsterShape();
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(gd::Color::Magenta);
                _shape.setOutlineThickness(5);
                _shape.setPosition(_position);
                _shape.setRotation(0);

                _healthBar = std::make_unique<Game::Components::Range>(0, _health, 1, gd::Vector2<float>(0, 0), gd::Vector2<float>(_size * 1.5, 10));
                _healthBar->setValue(_health);
                _healthBar->setColor(gd::Color::fromHex("#900028"));
                _showHealthBar = false;
                _healthBar->setPosition(gd::Vector2<float>(_position.x + _size / 2 - _healthBar->getSize().x / 2, _position.y + _size + _healthBar->getSize().y));
            }

            void Enemy::_createMonsterShape()
            {
                switch (_type) {
                    case Enemy::Type::BASIC_MONSTER:
                        _createBasicMonster();
                        break;
                    case Enemy::Type::KAMIKAZE_MONSTER:
                        _createKamikazeMonster();
                        break;
                    case Enemy::Type::BOSS:
                        _createBossMonster();
                        break;
                    case Enemy::Type::HEALTH_BONUS:
                        _createHealthPickup();
                        break;
                    case Enemy::Type::DAMAGE_BONUS:
                        _createDamagePickup();
                        break;
                    case Enemy::Type::SHOTGUN_WEAPON:
                        _createShotgunWeapon();
                        break;
                    default:
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

            void Enemy::_createBossMonster()
            {
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(_size * 0.7), static_cast<float>(_size * 0.3)},
                    {static_cast<float>(_size), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size * 0.4)},
                    {static_cast<float>(_size * 0.8), static_cast<float>(_size)},
                    {static_cast<float>(_size * 0.2), static_cast<float>(_size)},
                    {static_cast<float>(0), static_cast<float>(_size * 0.4)},
                    {static_cast<float>(0), static_cast<float>(0)},
                    {static_cast<float>(_size * 0.3), static_cast<float>(_size * 0.3)},
                });
            }

            void Enemy::_createHealthPickup()
            {
                _shape.create({
                    {static_cast<float>(_size * 0.4), static_cast<float>(0)},
                    {static_cast<float>(_size * 0.6), static_cast<float>(0)},
                    {static_cast<float>(_size * 0.6), static_cast<float>(_size * 0.4)},
                    {static_cast<float>(_size), static_cast<float>(_size * 0.4)},
                    {static_cast<float>(_size), static_cast<float>(_size * 0.6)},
                    {static_cast<float>(_size * 0.6), static_cast<float>(_size * 0.6)},
                    {static_cast<float>(_size * 0.6), static_cast<float>(_size)},
                    {static_cast<float>(_size * 0.4), static_cast<float>(_size)},
                    {static_cast<float>(_size * 0.4), static_cast<float>(_size * 0.6)},
                    {static_cast<float>(0), static_cast<float>(_size * 0.6)},
                    {static_cast<float>(0), static_cast<float>(_size * 0.4)},
                    {static_cast<float>(_size * 0.4), static_cast<float>(_size * 0.4)},
                });
            }

            void Enemy::_createDamagePickup()
            {
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(_size * 0.7), static_cast<float>(_size * 0.3)},
                    {static_cast<float>(_size), static_cast<float>(_size * 0.5)},
                    {static_cast<float>(_size * 0.7), static_cast<float>(_size * 0.7)},
                    {static_cast<float>(_size / 2), static_cast<float>(_size)},
                    {static_cast<float>(_size * 0.3), static_cast<float>(_size * 0.7)},
                    {static_cast<float>(0), static_cast<float>(_size * 0.5)},
                    {static_cast<float>(_size * 0.3), static_cast<float>(_size * 0.3)},
                });
            }

            void Enemy::_createShotgunWeapon()
            {
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(0), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size / 3), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size / 3), static_cast<float>(_size)},
                    {static_cast<float>(_size / 3 * 2), static_cast<float>(_size)},
                    {static_cast<float>(_size / 3 * 2), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size), static_cast<float>(_size / 2)},
                });
            }

            void Enemy::takeDamage(int damage)
            {
                _health -= damage;
                if (_health <= 0) _health = 0;
                _healthBar->setValue(_health);
            }

            void Enemy::showHealthBar(bool show)
            {
                _showHealthBar = show;
            }

            void Enemy::draw(gd::Window &window)
            {
                window.draw(_shape);
                if (_showHealthBar) _healthBar->draw(window);
            }

            void Enemy::setPosition(float x, float y)
            {
                if (_position.x == x && _position.y == y) return;
                _position = {x, y};
                _shape.setPosition(_position);
                _healthBar->setPosition(gd::Vector2<float>(_position.x + _size / 2 - _healthBar->getSize().x / 2, _position.y + _size + _healthBar->getSize().y));
            }

            void Enemy::setHealth(int health)
            {
                _health = health;
                _healthBar->setValue(_health);
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType