/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_ENEMY_HPP_
#define RTYPE_Game_ENEMY_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "AEntity.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class Enemy : public AEntity
            {
                public:
                    Enemy(int id, float x = 0, float y = 0, int health = 100);
                    ~Enemy() = default;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_ENEMY_HPP_ */
