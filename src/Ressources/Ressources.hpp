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

            std::unordered_map<std::string, std::shared_ptr<RType::Display::Player>> &players();
            RType::Display::Player &me();
            std::shared_ptr<RType::Communication::SendList> &sendList();
            std::vector<std::unique_ptr<RType::Display::Shoot>> &shoots();
            std::unordered_map<std::string, std::shared_ptr<RType::Display::Enemy>> &enemies();
            void update();

            void setSendList(std::shared_ptr<RType::Communication::SendList> sendList);

        private:
            Ressources();

            RType::Display::Player _me = RType::Display::Player(0, "#FFFFFF", 400, 300, 100);
            std::unordered_map<std::string, std::shared_ptr<RType::Display::Player>> _players;
            std::unordered_map<std::string, std::shared_ptr<RType::Display::Enemy>> _enemies;
            std::shared_ptr<RType::Communication::SendList> _sendList = nullptr;
            std::vector<std::tuple<gd::Time, int, void (Ressources::*)()>> _timers;
            std::vector<std::unique_ptr<RType::Display::Shoot>> _shoots;
            void _sendPlayerPosition();
    };
} // namespace RType

#endif /* !RTYPE_RESSOURCES_HPP_ */
