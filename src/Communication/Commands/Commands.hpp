/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_COMMUNICATION_COMMANDS_HPP_
#define RTYPE_COMMUNICATION_COMMANDS_HPP_

/*  ---- INCLUDES ---- */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Game/Components/Entity/Player/Player.hpp"
#include "Helpers/Utils/Utils.hpp"
#include "Ressources/Ressources.hpp"
#include "rfcArgParser.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Communication
    {
        class Commands
        {
            public:
                Commands();
                ~Commands() = default;

                void handleCommand(std::string command);

            private:
                std::unordered_map<std::string, void (Commands::*)(std::vector<std::string>)> _commands;

                void _handleCreateRoom(std::vector<std::string> args);
                void _handleJoinRoom(std::vector<std::string> args);
                void _handleListRooms(std::vector<std::string> args);
                void _handleRoomInfo(std::vector<std::string> args);
                void _handlePlayerConnection(std::vector<std::string> args);
                void _handleYouConnection(std::vector<std::string> args);
                void _handlePlayerDisconnection(std::vector<std::string> args);
                void _handlePlayerColor(std::vector<std::string> args);
                void _handleRoomMode(std::vector<std::string> args);
                void _handleRoomStartGame(std::vector<std::string> args);
                void _handlePlayerPosition(std::vector<std::string> args);
                void _handlePlayerDamage(std::vector<std::string> args);
                void _handlePlayerDeath(std::vector<std::string> args);
                void _handlePlayerShoot(std::vector<std::string> args);
                void _handlePlayerInfo(std::vector<std::string> args);
                void _handleEnemyCreation(std::vector<std::string> args);
                void _handleEnemyPosition(std::vector<std::string> args);
                void _handleEnemyDamage(std::vector<std::string> args);
                void _handleEnemyDeath(std::vector<std::string> args);
                void _handleEnemyShoot(std::vector<std::string> args);
                void _handleEnemyInfo(std::vector<std::string> args);
                void _handleGameWave(std::vector<std::string> args);
                void _handleRoomEndGame(std::vector<std::string> args);
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_COMMANDS_HPP_ */
