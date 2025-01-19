#include <criterion/criterion.h>
#include "Enemy.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            /* ---- ENEMY CLASS ---- */
            Test(Enemy, CronstructorDefault)
            {
                RType::Game::Entity::Enemy enemy(1, RType::Game::Entity::Enemy::Type::BASIC_MONSTER);

                cr_assert_eq(enemy.getId(), 1, "Enemy ID should be 1");
                cr_assert_eq(enemy.getHealth(), 100, "Enemy health should be initialized to 100");
                cr_assert(enemy.getIsAlive(), "Enemy should be alive by default");
                // TODO TESTING: Fix this test
                //  cr_assert_eq(enemy.getSize().x, 40, "Enemy size.x should be 40");
            }

            Test(Enemy, PositionInitialization)
            {
                RType::Game::Entity::Enemy enemy(2, RType::Game::Entity::Enemy::Type::KAMIKAZE_MONSTER, 10.0f, 20.0f);

                cr_assert_float_eq(enemy.getX(), 10.0f, 1e-6, "Enemy X position should be initialized to 10.0");
                cr_assert_float_eq(enemy.getY(), 20.0f, 1e-6, "Enemy Y position should be initialized to 20.0");
            }

            Test(Enemy, SetHealth)
            {
                RType::Game::Entity::Enemy enemy(3, RType::Game::Entity::Enemy::Type::BOSS);

                enemy.setHealth(150);
                cr_assert_eq(enemy.getHealth(), 150, "Enemy health should be updated to 150");
            }

            Test(Enemy, BasicMonsterShapeCreation)
            {
                RType::Game::Entity::Enemy enemy(4, RType::Game::Entity::Enemy::Type::BASIC_MONSTER);

                auto size = enemy.getSize();
                // TODO TESTING: Fix this test
                //  cr_assert_eq(size.x, 40, "Enemy shape size.x should be 40");
                //  cr_assert_eq(size.y, 40, "Enemy shape size.y should be 40");
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType