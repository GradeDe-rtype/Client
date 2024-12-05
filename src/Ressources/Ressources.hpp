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
#include <unordered_map>
#include "Player.hpp"
#include "SendList.hpp"
#include "Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    class Ressources
    {
        public:
            static Ressources *get();
            ~Ressources() = default;

            std::unordered_map<std::string, RType::Display::Player> &players();
            RType::Display::Player &me();
            std::shared_ptr<RType::Communication::SendList> &sendList();

            void setSendList(std::shared_ptr<RType::Communication::SendList> sendList);

        private:
            Ressources() = default;

            RType::Display::Player _me = RType::Display::Player(0, "#FFFFFF", 400, 300, 100);
            std::unordered_map<std::string, RType::Display::Player> _players;
            std::shared_ptr<RType::Communication::SendList> _sendList;
    };
} // namespace RType

#endif /* !RTYPE_RESSOURCES_HPP_ */
