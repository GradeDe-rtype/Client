/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_RESSOURCES_HPP_
#define RTYPE_RESSOURCES_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include <unordered_map>
#include "Enemy.hpp"
#include "GradeDe/Time.hpp"
#include "Player.hpp"
#include "SendList.hpp"
#include "Shoot.hpp"
#include "Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    class Ressources
    {
        public:
            static Ressources *get();
            ~Ressources() = default;

            void update();

            std::shared_ptr<RType::Game::Entity::Player> me = nullptr;
            std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Player>> players;
            std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Enemy>> enemies;
            std::shared_ptr<RType::Communication::SendList> sendList = nullptr;
            std::vector<std::unique_ptr<RType::Game::Entity::Shoot>> shoots;
            int wave = 1;
            bool isConnected = false;

        private:
            Ressources();

            std::vector<std::tuple<gd::Time, int, void (Ressources::*)()>> _timers;

            void _sendPlayerPosition();
    };
} // namespace RType

#endif /* !RTYPE_RESSOURCES_HPP_ */
