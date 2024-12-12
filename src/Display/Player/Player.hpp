/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_PLAYER_HPP_
#define RTYPE_DISPLAY_PLAYER_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "rfcArgParser.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        class Player
        {
            public:
                Player(int id, std::string color = "#FFFFFF", int x = 0, int y = 0, int health = 100);
                ~Player() = default;

                gd::Shape &shape();
                void update();

                void setId(int id);
                void setColor(std::string color);
                void setHealth(int health);
                void setX(int x);
                void setY(int y);
                void setPosition(int x, int y);
                void move(int x, int y);
                void setGoto(int x, int y);
                void shoot();
                void setSpeed(int speed);
                void setShootCooldown(int cooldown);

                int getId() const;
                std::string getColor() const;
                int getHealth() const;
                int getX() const;
                int getY() const;
                std::string getPlayerInfo() const;
                std::string getPlayerSmallInfo() const;
                std::string getPlayerPosition() const;
                int getSpeed() const;
                bool hasMoved();
                int getShootCooldown();

            private:
                gd::Shape _shape;
                int _id;
                std::string _color;
                int _health;
                int _x;
                int _y;
                int _speed = 15;
                gd::Vector2<int> _goto = {-1, -1};
                bool _moved = false;
                int _maxRotationAngle = 30;
                gd::Time _shootTimer;
                int _shootCooldown = 1000;
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_PLAYER_HPP_ */
