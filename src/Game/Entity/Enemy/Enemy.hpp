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
#include "Game/Components/Range/Range.hpp"
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
                        BASIC_MONSTER = 3,
                        HEALTH_BONUS = 4,
                        DAMAGE_BONUS = 5,
                        ROCKET_WEAPON = 6
                    } Type;

                    Enemy(int id, Type type, float x = 0, float y = 0, int health = 100);
                    ~Enemy() = default;
                    void draw(gd::Window &window) override;

                    void setPosition(float x, float y) override;
                    void takeDamage(int damage);
                    void showHealthBar(bool show);
                    void setHealth(int health);

                private:
                    Type _type;
                    std::unique_ptr<Game::Components::Range> _healthBar;
                    bool _showHealthBar = false;
                    void _createMonsterShape();

                    void _createKamikazeMonster();
                    void _createBasicMonster();
                    void _createBossMonster();
                    void _createHealthPickup();
                    void _createDamagePickup();
                    void _createRocketPickup();
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ENTITY_ENEMY_HPP_ */
