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
            : _id(id), _color(color), _x(x), _y(y), _health(health)
        {
            float size = 40;
            _shape.create({{0, 0}, {size, size / 2}, {0, size}, {size / 4, size / 2}});
            _shape.setOrigin({size / 2, size / 2});
            _shape.setFillColor(gd::Color::Transparent);
            _shape.setOutlineColor(gd::Color::fromHex(color));
            _shape.setOutlineThickness(5);
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
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
            _color = color;
            _shape.setOutlineColor(gd::Color::fromHex(color));
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
            _x = x;
            _y = y;
            _shape.setPosition((gd::Vector2<float>){static_cast<float>(_x), static_cast<float>(_y)});
        }

        void Player::move(int x, int y)
        {
            setPosition(_x + x, _y + y);
        }

        int Player::getId() const
        {
            return _id;
        }

        std::string Player::getColor() const
        {
            return _color;
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

        std::string Player::getPlayerInfo() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["id"] = std::to_string(_id);
            tmp["color"] = _color;
            tmp["health"] = std::to_string(_health);
            tmp["x"] = std::to_string(_x);
            tmp["y"] = std::to_string(_y);
            return rfcArgParser::CreateObject(tmp);
        }

        std::string Player::getPlayerSmallInfo() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["id"] = std::to_string(_id);
            tmp["color"] = _color;
            return rfcArgParser::CreateObject(tmp);
        }

        std::string Player::getPlayerPosition() const
        {
            std::unordered_map<std::string, std::string> tmp;
            tmp["x"] = std::to_string(_x);
            tmp["y"] = std::to_string(_y);
            return rfcArgParser::CreateObject(tmp);
        }
    } // namespace Display
} // namespace RType