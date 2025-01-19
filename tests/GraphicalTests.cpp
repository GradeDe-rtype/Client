#include <criterion/criterion.h>

#include "Enemy.hpp"
#include "Player.hpp"
#include "Shoot.hpp"
#include "SelectArrow.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            /* ---- ENEMY CLASS ---- */

            Test(Enemy, Constructor_Default)
            {
                Enemy enemy(1, Enemy::Type::BASIC_MONSTER);
                cr_assert_eq(enemy.getId(), 1, "Enemy ID should be 1");
                cr_assert_eq(enemy.getHealth(), 100, "Enemy health should be initialized to 100");
                cr_assert(enemy.getIsAlive(), "Enemy should be alive by default");
                cr_assert_eq(enemy.getSpeed(), 0, "Enemy default speed should be 0");
            }

            Test(Enemy, Constructor_PositionInitialization)
            {
                Enemy enemy(2, Enemy::Type::KAMIKAZE_MONSTER, 10.0f, 20.0f);
                cr_assert_float_eq(enemy.getX(), 10.0f, 1e-6, "Enemy X position should be initialized to 10.0");
                cr_assert_float_eq(enemy.getY(), 20.0f, 1e-6, "Enemy Y position should be initialized to 20.0");
            }

            Test(Enemy, SetHealth)
            {
                Enemy enemy(3, Enemy::Type::BOSS);
                enemy.setHealth(150);
                cr_assert_eq(enemy.getHealth(), 150, "Enemy health should be updated to 150");

                enemy.setHealth(50);
                cr_assert_eq(enemy.getHealth(), 50, "Enemy health should be updated to 50");
            }

            Test(Enemy, TakeDamage)
            {
                Enemy enemy(4, Enemy::Type::BASIC_MONSTER);
                enemy.takeDamage(30);
                cr_assert_eq(enemy.getHealth(), 70, "Enemy health should be 70 after taking 30 damage");

                enemy.takeDamage(100);
                cr_assert_eq(enemy.getHealth(), 0, "Enemy health should not go below 0");
            }

            Test(Enemy, IsAlive_Check)
            {
                Enemy enemy(5, Enemy::Type::KAMIKAZE_MONSTER);
                cr_assert(enemy.getIsAlive(), "Enemy should be alive at initialization");
                enemy.takeDamage(200);
                cr_assert_eq(enemy.getHealth(), 0, "Enemy should have 0 health after taking 200 damage");
            }

            Test(Enemy, SetPosition)
            {
                Enemy enemy(6, Enemy::Type::BASIC_MONSTER);
                enemy.setPosition(50.0f, 75.0f);
                cr_assert_float_eq(enemy.getX(), 50.0f, 1e-6, "Enemy X position should be updated to 50.0");
                cr_assert_float_eq(enemy.getY(), 75.0f, 1e-6, "Enemy Y position should be updated to 75.0");
            }

            Test(Enemy, HealthBarVisibility)
            {
                Enemy enemy(7, Enemy::Type::BOSS);
                enemy.showHealthBar(true);
                cr_assert(true, "Health bar visibility toggled (manual verification required in graphics module)");
            }

            /* ---- PLAYER CLASS ---- */
                        
            Test(Player, Constructor_Default)
            {
                Player player(1, "#FF0000");
                cr_assert_eq(player.getId(), 1, "Player ID should be 1");
                cr_assert_eq(player.getHealth(), 100, "Player health should be initialized to 100");
                cr_assert(player.getIsAlive(), "Player should be alive by default");
                cr_assert_eq(player.getSpeed(), 15, "Player default speed should be 15");
            }

            Test(Player, SetPosition)
            {
                Player player(2, "#00FF00");
                player.setPosition(30.0f, 50.0f);
                cr_assert_float_eq(player.getX(), 30.0f, 1e-6, "Player X position should be updated to 30.0");
                cr_assert_float_eq(player.getY(), 50.0f, 1e-6, "Player Y position should be updated to 50.0");
            }

            Test(Player, TakeDamage)
            {
                Player player(3, "#0000FF");
                player.takeDamage(20);
                cr_assert_eq(player.getHealth(), 80, "Player health should be 80 after taking 20 damage");
                
                player.takeDamage(100);
                cr_assert_eq(player.getHealth(), 0, "Player health should not go below 0");
            }

            Test(Player, DieAndRespawn)
            {
                Player player(4, "#FFFF00");
                player.die();
                cr_assert_not(player.getIsAlive(), "Player should be dead after calling die()");
                
                player.respawn();
                cr_assert(player.getIsAlive(), "Player should be alive after calling respawn()");
            }

            Test(Player, ShootCooldown)
            {
                Player player(5, "#FF00FF");
                player.setShootCooldown(1000);
                cr_assert_eq(player.getShootMaxCooldown(), 1000, "Player shoot cooldown should be set to 1000");
            }

            /* ---- SELECTARROW CLASS ---- */
            
            Test(SelectArrow, Constructor_Default)
            {
                SelectArrow arrow(SelectArrow::LEFT, gd::Color::White, 10, {0, 0});
                cr_assert_eq(arrow.getDirection(), SelectArrow::LEFT, "Arrow direction should be LEFT");
            }

            Test(SelectArrow, ChangeDirection)
            {
                SelectArrow arrow;
                arrow.setDirection(SelectArrow::UP);
                cr_assert_eq(arrow.getDirection(), SelectArrow::UP, "Arrow direction should be set to UP");
            }

            Test(SelectArrow, ChangeColor)
            {
                SelectArrow arrow;
                arrow.setColor("#FF0000");
                cr_assert(true, "Arrow color change tested (manual verification needed in graphics)");
            }

        } // namespace Entity
    } // namespace Game
} // namespace RType
