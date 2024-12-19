/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_SHOOT_HPP_
#define RTYPE_Game_SHOOT_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "GradeDe/Color.hpp"
#include "GradeDe/Sound.hpp"
#include "Game/Components/Entity/Base/AEntity.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class Shoot : public AEntity
            {
                public:
                    Shoot(float x = 0, float y = 0, int speed = 15);
                    ~Shoot() = default;

                    void update();

                private:
                    gd::Sound _blaster;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_SHOOT_HPP_ */
