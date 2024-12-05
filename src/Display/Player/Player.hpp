/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_PLAYER_HPP_
#define RTYPE_DISPLAY_PLAYER_HPP_

/*  ---- INCLUDES ---- */
#include "GradeDe/Shape.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        class Player
        {
            public:
                Player(gd::Vector2<float> position = {0, 0});
                ~Player() = default;

                gd::Shape &shape();

            private:
                gd::Shape _shape;
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_PLAYER_HPP_ */
