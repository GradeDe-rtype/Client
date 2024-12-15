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
        Player::Player(int id, std::string color, int x, int y, int health)
            : _id(id), _x(x), _y(y), _health(health)
        {
            _color = gd::Color::fromHex(color);

            float size = 40;
            _shape.create({{0, 0}, {size, size / 2}, {0, size}, {size / 4, size / 2}});
            _shape.setOrigin({size / 2, size / 2});
            _shape.setFillColor(gd::Color::Transparent);
            _shape.setOutlineColor(_color);
            _shape.setOutlineThickness(5);
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
            _shape.setRotation(0);
            _shootTimer.reset();
            _rotationReset.reset();
            _dead = false;
            _moveClock.reset();
        }

        gd::Shape &Player::shape()
        {
            return _shape;
        }

        void Player::setId(int id)
        {
            _id = id;
        }

        void Player::setColor(std::string color)
        {
            _color = gd::Color::fromHex(color);
            _shape.setOutlineColor(_color);
        }

        void Player::setHealth(int health)
        {
            _health = health;
        }

        void Player::setX(int x)
        {
            setPosition(x, _y);
        }

        void Player::setY(int y)
        {
            setPosition(_x, y);
        }

        void Player::setPosition(int x, int y)
        {
            if (_x == x && _y == y) return;
            _x = x;
            _y = y;
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
            _moved = true;
        }

        void Player::move(int x, int y)
        {
            setPosition(_x + x, _y + y);
        }

        void Player::setGoto(int x, int y)
        {
            _goto = {x, y};
        }

        void Player::shoot()
        {
            if (_dead) return;
            if (_shootTimer.getElapsedTime() > _shootCooldown)
                _shootTimer.reset();
        }

        void Player::setSpeed(int speed)
        {
            _speed = speed;
        }

        void Player::setShootCooldown(int cooldown)
        {
            _shootCooldown = cooldown;
        }

        void Player::die()
        {
            _color.a = 100;
            _shape.setOutlineColor(_color);
            _dead = true;
        }

        void Player::respawn()
        {
            _color.a = 255;
            _shape.setOutlineColor(_color);
            _dead = false;
        }

        int Player::getId() const
        {
            return _id;
        }

        std::string Player::getColor() const
        {
            return gd::Color::toHex(_color);
        }

        int Player::getHealth() const
        {
            return _health;
        }

        int Player::getX() const
        {
            return _x;
        }

        int Player::getY() const
        {
            return _y;
        }

        int Player::getSpeed() const
        {
            return _speed;
        }

        bool Player::hasMoved()
        {
            bool tmp = _moved;
            _moved = false;
            return tmp;
        }

        std::string Player::getPlayerInfo() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["id"] = std::to_string(_id);
            tmp["color"] = gd::Color::toHex(_color);
            tmp["health"] = std::to_string(_health);
            tmp["x"] = std::to_string(_x);
            tmp["y"] = std::to_string(_y);
            return rfcArgParser::CreateObject(tmp);
        }

        std::string Player::getPlayerSmallInfo() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["id"] = std::to_string(_id);
            tmp["color"] = gd::Color::toHex(_color);
            return rfcArgParser::CreateObject(tmp);
        }

        std::string Player::getPlayerPosition() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["x"] = std::to_string(_x);
            tmp["y"] = std::to_string(_y);
            return rfcArgParser::CreateObject(tmp);
        }

        int Player::getShootCooldown()
        {
            if (_dead) return -1;
            if (_shootTimer.getElapsedTime() > _shootCooldown)
                return 0;
            return _shootCooldown - _shootTimer.getElapsedTime();
        }

        bool Player::isDead()
        {
            return _dead;
        }

        void Player::update()
        {
            if (_moveClock.getElapsedTime() >= 1000 / 24) {
                if (_goto.y >= 0 && _goto.x >= 0) {
                    int distY = _goto.y - _y;
                    distY *= distY < 0 ? -1 : 1;
                    float percent = static_cast<float>(distY) / static_cast<float>(_speed);
                    if (_y > _goto.y) {
                        if (_shape.getRotation() > -_maxRotationAngle)
                            (percent == 1) ? _shape.rotate(-_maxRotationAngle / 3) : _shape.setRotation(-_maxRotationAngle * percent);
                        else
                            _shape.setRotation(-_maxRotationAngle);
                        _rotationReset.reset();
                    }
                    if (_y < _goto.y) {
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
    } // namespace Display
} // namespace RType