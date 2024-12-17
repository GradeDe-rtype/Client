/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_PLAYER_HPP_
#define RTYPE_Game_PLAYER_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "AEntity.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"

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

                    void update();

                    void setColor(std::string color) override;
                    void setColor(gd::Color color) override;
                    void setPosition(float x, float y) override;
                    void setGoto(int x, int y);
                    void shoot();
                    void setShootCooldown(int cooldown);
                    void die();
                    void respawn();

                    bool hasMoved();
                    int getShootCooldown();

                private:
                    gd::Vector2<int> _goto = {-1, -1};
                    bool _moved = false;
                    int _maxRotationAngle = 30;
                    gd::Time _shootTimer;
                    int _shootCooldown = 800;
                    gd::Time _rotationReset;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_PLAYER_HPP_ */
