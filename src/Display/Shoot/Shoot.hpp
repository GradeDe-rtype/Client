/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_SHOOT_HPP_
#define RTYPE_DISPLAY_SHOOT_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "GradeDe/Shape.hpp"
#include "GradeDe/Sound.hpp"
#include "GradeDe/Vector.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        class Shoot
        {
            public:
                Shoot(int x = 0, int y = 0);
                ~Shoot() = default;

                gd::Shape &shape();
                void update();

                void setX(int x);
                void setY(int y);
                void setPosition(int x, int y);
                void move(int x, int y);

                int getX() const;
                int getY() const;

            private:
                gd::Shape _shape;
                int _x;
                int _y;
                int _speed = 15;
                gd::Sound _blaster;
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_SHOOT_HPP_ */
