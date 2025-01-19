/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ENTITY_PLAYER_HPP_
#define RTYPE_GAME_COMPONENT_ENTITY_PLAYER_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "Game/Components/Range/Range.hpp"
#include "Game/Entity/Base/AEntity.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class Player : public AEntity
            {
                public:
                    Player(int id, std::string color = "#FFFFFF", float x = 0, float y = 0, int health = 100);

                    void update() override;
                    void draw(gd::Window &window) override;

                    void setColor(std::string color) override;
                    void setColor(gd::Color color) override;
                    void setOutlineColor(gd::Color color);
                    void setPosition(float x, float y) override;
                    void setGoto(int x, int y);
                    void shoot();
                    void setShootCooldown(int cooldown);
                    void die();
                    void respawn();
                    void showHealthBar(bool show);
                    void takeDamage(int damage);
                    void setHealth(int health) override;

                    bool hasMoved();
                    int getShootCooldown();
                    int getShootMaxCooldown();

                private:
                    gd::Vector2<int> _goto = {-1, -1};
                    bool _moved = false;
                    int _maxRotationAngle = 30;
                    gd::Time _shootTimer;
                    int _shootCooldown = 800;
                    gd::Time _rotationReset;
                    std::unique_ptr<Game::Components::Range> _healthBar;
                    bool _showHealthBar = false;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ENTITY_PLAYER_HPP_ */
