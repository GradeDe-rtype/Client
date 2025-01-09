/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ENTITY_SHOOT_HPP_
#define RTYPE_GAME_COMPONENT_ENTITY_SHOOT_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include <unordered_map>
#include "GradeDe/Color.hpp"
#include "GradeDe/Sound.hpp"
#include "Game/Entity/Base/AEntity.hpp"
#include "Game/Managers/Sound/Sound.hpp"

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
                    Shoot(float x = 0, float y = 0, std::string from = "player");
                    ~Shoot() = default;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ENTITY_SHOOT_HPP_ */
