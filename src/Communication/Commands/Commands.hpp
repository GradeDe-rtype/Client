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
#include <vector>
#include <unordered_map>
#include "Utils.hpp"
#include "rfcArgParser.hpp"
#include "Ressources.hpp"
#include "Player.hpp"

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

                void _handleConnect(std::vector<std::string> args);
                void _handleDisconnect(std::vector<std::string> args);
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_COMMANDS_HPP_ */
