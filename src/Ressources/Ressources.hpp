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
#include "GradeDe/Time.hpp"
#include "Communication/SendList/SendList.hpp"
#include "Game/Components/RoomGameSlot/RoomGameSlot.hpp"
#include "Game/Entity/Enemy/Enemy.hpp"
#include "Game/Entity/Player/Player.hpp"
#include "Game/Entity/Shoot/Shoot.hpp"
#include "Helpers/Mutex/Mutex.hpp"
#include "Helpers/Utils/Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    class Ressources
    {
        public:
            enum RoomState {
                NEXT_WAVE,
                WAVE_WAITING,
                WAVE_READY,
                GAME,
                END,
                ROOMS_LIST,
            };

            static Ressources *get();
            ~Ressources() = default;

            void update();
            void clearShoots(std::vector<std::string> from = {"player", "enemy"});
            void cleanShoots(std::vector<std::string> from = {"player", "enemy"});

            std::shared_ptr<RType::Game::Entity::Player> me = nullptr;
            RType::Helpers::Mutex playersMutex;
            std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Player>> players;
            RType::Helpers::Mutex enemiesMutex;
            std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Enemy>> enemies;
            RType::Helpers::Mutex shootsMutex;
            std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Shoot>>>> shoots;
            std::shared_ptr<RType::Communication::SendList> sendList = nullptr;
            std::vector<std::shared_ptr<RType::Game::Components::RoomGameSlot>> roomGameSlots;
            bool majRoom = false;
            int wave = 0;
            RoomState roomState = RoomState::GAME;
            bool isConnected = false;
            bool endWin = false;

        private:
            Ressources();

            std::vector<std::tuple<gd::Time, int, void (Ressources::*)()>> _timers;

            void _sendPlayerPosition();
    };
} // namespace RType

#endif /* !RTYPE_RESSOURCES_HPP_ */
