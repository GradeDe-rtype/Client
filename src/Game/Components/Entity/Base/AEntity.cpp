/*
    Authors:
    >> Caroline Boilly @Aeliondw
    >> Nathan Tirolf @dragusheen

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "AEntity.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            /*  ---- FUNCTIONS ---- */
            void AEntity::update()
            {
            }

            void AEntity::move(float x, float y)
            {
                setPosition(_position.x + x, _position.y + y);
            }

            void AEntity::move(gd::Vector2<float> move)
            {
                setPosition(_position.x + move.x, _position.y + move.y);
            }

            /*  ---- SETTER ---- */
            void AEntity::setColor(std::string color)
            {
                _color = gd::Color::fromHex(color);
                _shape.setFillColor(_color);
            }

            void AEntity::setColor(gd::Color color)
            {
                setColor(gd::Color::toHex(color));
            }

            void AEntity::setDamage(int damage)
            {
                _damage = damage;
            }

            void AEntity::setHealth(int health)
            {
                _health = health;
            }

            void AEntity::setIsAlive(bool isAlive)
            {
                _isAlive = isAlive;
            }

            void AEntity::setLevel(int level)
            {
                _level = level;
            }

            void AEntity::setPosition(float x, float y)
            {
                if (_position.x == x && _position.y == y) return;
                _position.x = x;
                _position.y = y;
                _shape.setPosition(_position);
            }

            void AEntity::setPosition(gd::Vector2<float> position)
            {
                setPosition(position.x, position.y);
            }

            void AEntity::setX(float x)
            {
                setPosition(x, _position.y);
            }

            void AEntity::setY(float y)
            {
                setPosition(_position.x, y);
            }

            void AEntity::setSize(int size)
            {
                _size = size;
            }

            void AEntity::setSpeed(int speed)
            {
                _speed = speed;
            }

            /*  ---- GETTER ---- */
            int AEntity::getDamage() const
            {
                return _damage;
            }

            int AEntity::getHealth() const
            {
                return _health;
            }

            int AEntity::getId() const
            {
                return _id;
            }

            bool AEntity::getIsAlive() const
            {
                return _isAlive;
            }

            int AEntity::getLevel() const
            {
                return _level;
            }

            gd::Vector2<float> AEntity::getPosition() const
            {
                return _position;
            }

            float AEntity::getX() const
            {
                return _position.x;
            }

            float AEntity::getY() const
            {
                return _position.y;
            }

            int AEntity::getSize() const
            {
                return _size;
            }

            int AEntity::getSpeed() const
            {
                return _speed;
            }

            std::string AEntity::getEntityInfo() const
            {
                std::unordered_map<std::string, std::string> tmp;
                tmp["id"] = std::to_string(_id);
                tmp["color"] = gd::Color::toHex(_color);
                tmp["health"] = std::to_string(_health);
                tmp["x"] = std::to_string(static_cast<int>(_position.x));
                tmp["y"] = std::to_string(static_cast<int>(_position.y));
                return rfcArgParser::CreateObject(tmp);
            }

            std::string AEntity::getEntitySmallInfo() const
            {
                std::unordered_map<std::string, std::string> tmp;
                tmp["id"] = std::to_string(_id);
                tmp["color"] = gd::Color::toHex(_color);
                return rfcArgParser::CreateObject(tmp);
            }

            std::string AEntity::getEntityPosition() const
            {
                std::unordered_map<std::string, std::string> tmp;
                tmp["x"] = std::to_string(static_cast<int>(_position.x));
                tmp["y"] = std::to_string(static_cast<int>(_position.y));
                return rfcArgParser::CreateObject(tmp);
            }

            gd::Shape &AEntity::shape()
            {
                return _shape;
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType
