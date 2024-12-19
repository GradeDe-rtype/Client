/*
    Authors:
    >> Caroline Boilly @Aeliondw
    >> Nathan Tirolf @dragusheen

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_ENTITY_ABSTRACT_HPP_
#define RTYPE_GAME_ENTITY_ABSTRACT_HPP_

#include <vector>
#include "GradeDe/Color.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "Game/Components/Entity/Base/IEntity.hpp"
#include "rfcArgParser.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class AEntity : public IEntity
            {
                public:
                    AEntity() = default;
                    ~AEntity() = default;

                    void update() override;
                    void move(float x, float y) override;
                    void move(gd::Vector2<float> move) override;

                    void setColor(std::string color) override;
                    void setColor(gd::Color color) override;
                    void setDamage(int damage) override;
                    void setHealth(int health) override;
                    void setIsAlive(bool isAlive) override;
                    void setLevel(int level) override;
                    void setPosition(float x, float y) override;
                    void setPosition(gd::Vector2<float> position) override;
                    void setX(float x) override;
                    void setY(float y) override;
                    void setSize(int size) override;
                    void setSpeed(int speed) override;

                    int getDamage() const override;
                    int getHealth() const override;
                    int getId() const override;
                    bool getIsAlive() const override;
                    int getLevel() const override;
                    gd::Vector2<float> getPosition() const override;
                    float getX() const override;
                    float getY() const override;
                    int getSize() const override;
                    int getSpeed() const override;
                    std::string getEntityInfo() const override;
                    std::string getEntitySmallInfo() const override;
                    std::string getEntityPosition() const override;
                    gd::Shape &shape() override;

                protected:
                    gd::Color _color = gd::Color::White;
                    int _damage = 0;
                    int _health = 100;
                    int _id;
                    bool _isAlive = true;
                    int _level = 1;
                    gd::Time _moveClock;
                    gd::Shape _shape;
                    int _size = 0;
                    int _speed = 0;
                    gd::Vector2<float> _position = {0, 0};
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif // RTYPE_GAME_ENTITY_ABSTRACT_HPP_