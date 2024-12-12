/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_ENEMY_HPP_
#define RTYPE_DISPLAY_ENEMY_HPP_

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
        class Enemy
        {
            public:
                Enemy(int id, int x = 0, int y = 0, int health = 100);
                ~Enemy() = default;

                gd::Shape &shape();

                void setHealth(int health);
                void setX(int x);
                void setY(int y);
                void setPosition(int x, int y);
                void move(int x, int y);

                int getId() const;
                int getHealth() const;
                int getX() const;
                int getY() const;

            private:
                gd::Shape _shape;
                int _id;
                int _health;
                int _x;
                int _y;
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_ENEMY_HPP_ */
