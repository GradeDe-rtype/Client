/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ENTITY_ENEMY_HPP_
#define RTYPE_GAME_COMPONENT_ENTITY_ENEMY_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "Game/Entity/Base/AEntity.hpp"

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
                    typedef enum {
                        MONSTER = 0,
                        BOSS = 1,
                        KAMIKAZE_MONSTER = 2,
                        BASIC_MONSTER = 3
                    } Type;

                    Enemy(int id, Type type, float x = 0, float y = 0, int health = 100);
                    ~Enemy() = default;

                    void takeDamage(int damage);

                private:
                    Type _type;

                    void _createMonsterShape();
                    void _createKamikazeMonster();
                    void _createBasicMonster();
                    void _createBossMonster();
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ENTITY_ENEMY_HPP_ */
