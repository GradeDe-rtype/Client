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
#include "Player.hpp"
#include "Ressources.hpp"
#include "Utils.hpp"
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

                void _handlePlayerConnection(std::vector<std::string> args);
                void _handlePlayerDisconnection(std::vector<std::string> args);
                void _handlePlayerPosition(std::vector<std::string> args);
                void _handlePlayerShoot(std::vector<std::string> args);
                void _handleEnemyShoot(std::vector<std::string> args);
                void _handleEnemyAppear(std::vector<std::string> args);
                void _handleEnemyDeath(std::vector<std::string> args);
                void _handleEnemyPosition(std::vector<std::string> args);
                void _handleWave(std::vector<std::string> args);
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_COMMANDS_HPP_ */
