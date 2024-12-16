/*
    Authors:
    >> Caroline Boilly @Aeliondw
    >> Nathan Tirolf @dragusheen

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_ENTITY_INTERFACE_HPP_
#define RTYPE_GAME_ENTITY_INTERFACE_HPP_

#include "GradeDe/Color.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Vector.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class IEntity
            {
                public:
                    virtual ~IEntity() = default;

                    virtual void update() = 0;
                    virtual void move(float x, float y) = 0;
                    virtual void move(gd::Vector2<float> move) = 0;

                    virtual void setColor(std::string color) = 0;
                    virtual void setColor(gd::Color color) = 0;
                    virtual void setDamage(int damage) = 0;
                    virtual void setHealth(int health) = 0;
                    virtual void setIsAlive(bool isAlive) = 0;
                    virtual void setLevel(int level) = 0;
                    virtual void setPosition(float x, float y) = 0;
                    virtual void setPosition(gd::Vector2<float> position) = 0;
                    virtual void setX(float x) = 0;
                    virtual void setY(float y) = 0;
                    virtual void setSize(int size) = 0;
                    virtual void setSpeed(int speed) = 0;

                    virtual int getDamage() const = 0;
                    virtual int getHealth() const = 0;
                    virtual int getId() const = 0;
                    virtual bool getIsAlive() const = 0;
                    virtual int getLevel() const = 0;
                    virtual gd::Vector2<float> getPosition() const = 0;
                    virtual float getX() const = 0;
                    virtual float getY() const = 0;
                    virtual int getSize() const = 0;
                    virtual int getSpeed() const = 0;
                    virtual std::string getEntityInfo() const = 0;
                    virtual std::string getEntitySmallInfo() const = 0;
                    virtual std::string getEntityPosition() const = 0;
                    virtual gd::Shape &shape() = 0;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif // RTYPE_GAME_ENTITY_INTERFACE_HPP_