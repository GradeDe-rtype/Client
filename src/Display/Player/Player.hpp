/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_PLAYER_HPP_
#define RTYPE_PLAYER_HPP_

/*  ---- INCLUDES ---- */
#include "GradeDe/Shape.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    class Player
    {
        public:
            Player();
            ~Player() = default;

            gd::Shape &shape();

        private:
            gd::Shape _shape;
    };
} // namespace RType

#endif /* !RTYPE_PLAYER_HPP_ */
