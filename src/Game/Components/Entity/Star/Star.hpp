/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_STAR_HPP_
#define RTYPE_GAME_COMPONENT_STAR_HPP_

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
            class Star : public AEntity
            {
                public:
                    Star();
                    ~Star() = default;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_STAR_HPP_ */
