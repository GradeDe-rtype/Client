/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Player.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            Player::Player(int id, std::string color, float x, float y, int health)
            {
                _id = id;
                _health = health;
                _position = {x, y};
                _color = gd::Color::fromHex(color);
                _speed = 15;

                _size = 40;
                _shape.create({
                    {static_cast<float>(0), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size / 2)},
                    {static_cast<float>(0), static_cast<float>(_size)},
                    {static_cast<float>(_size / 4), static_cast<float>(_size / 2)},
                });
                _shape.setOrigin({static_cast<float>(_size / 2), static_cast<float>(_size / 2)});
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(_color);
                _shape.setOutlineThickness(5);
                _shape.setPosition(_position);
                _shape.setRotation(0);
                _shootTimer.reset();
                _rotationReset.reset();
                _moveClock.reset();
            }

            void Player::setColor(std::string color)
            {
                _shape.setOutlineColor(gd::Color::fromHex(color));
            }

            void Player::setColor(gd::Color color)
            {
                _color = color;
                _shape.setOutlineColor(_color);
            }

            void Player::setPosition(float x, float y)
            {
                if (_position.x == x && _position.y == y) return;
                _position = {x, y};
                _shape.setPosition(_position);
                _moved = true;
            }

            void Player::setGoto(int x, int y)
            {
                _goto = {x, y};
            }

            void Player::shoot()
            {
                if (!_isAlive) return;
                if (_shootTimer.getElapsedTime() > _shootCooldown)
                    _shootTimer.reset();
            }

            void Player::setShootCooldown(int cooldown)
            {
                _shootCooldown = cooldown;
            }

            void Player::die()
            {
                _color.a = 100;
                _shape.setOutlineColor(_color);
                _isAlive = false;
            }

            void Player::respawn()
            {
                _color.a = 255;
                _shape.setOutlineColor(_color);
                _isAlive = true;
            }

            bool Player::hasMoved()
            {
                bool tmp = _moved;
                _moved = false;
                return tmp;
            }

            int Player::getShootCooldown()
            {
                if (!_isAlive) return -1;
                if (_shootTimer.getElapsedTime() > _shootCooldown)
                    return 0;
                return _shootCooldown - _shootTimer.getElapsedTime();
            }

            void Player::update()
            {
                if (_moveClock.getElapsedTime() >= 1000 / 24) {
                    if (_goto.y >= 0 && _goto.x >= 0) {
                        int distY = _goto.y - _position.y;
                        distY *= distY < 0 ? -1 : 1;
                        float percent = static_cast<float>(distY) / static_cast<float>(_speed);
                        if (_position.y > _goto.y) {
                            if (_shape.getRotation() > -_maxRotationAngle)
                                (percent == 1) ? _shape.rotate(-_maxRotationAngle / 3) : _shape.setRotation(-_maxRotationAngle * percent);
                            else
                                _shape.setRotation(-_maxRotationAngle);
                            _rotationReset.reset();
                        }
                        if (_position.y < _goto.y) {
                            if (_shape.getRotation() < _maxRotationAngle)
                                (percent >= 0.8) ? _shape.rotate(_maxRotationAngle / 3) : _shape.setRotation(_maxRotationAngle * percent);
                            else
                                _shape.setRotation(_maxRotationAngle);
                            _rotationReset.reset();
                        }
                        setPosition(_goto.x, _goto.y);
                        _goto = {-1, -1};
                    }
                    if (_rotationReset.getElapsedTime() > 50) {
                        if (_shape.getRotation() > 0) (_shape.getRotation() < 8) ? _shape.setRotation(0) : _shape.rotate(-8);
                        if (_shape.getRotation() < 0) (_shape.getRotation() > -8) ? _shape.setRotation(0) : _shape.rotate(8);
                    }
                    _moveClock.reset();
                }
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType