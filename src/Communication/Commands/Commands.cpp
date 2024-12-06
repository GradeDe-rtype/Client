/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Commands.hpp"

namespace RType
{
    namespace Communication
    {
        Commands::Commands()
        {
            _commands["connect"] = &Commands::_handleConnect;
            _commands["disconnect"] = &Commands::_handleDisconnect;
            _commands["p_position"] = &Commands::_handlePosition;
        }

        void Commands::handleCommand(std::string command)
        {
            std::vector<std::string> args = Helpers::Utils::split(command, " ");
            if (_commands.find(args[0]) != _commands.end())
                (this->*_commands[args[0]])(args);
        }

        void Commands::_handleConnect(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->players()[obj["player_id"]] = RType::Display::Player(std::stoi(obj["player_id"]), obj["color"]);
        }

        void Commands::_handleDisconnect(std::vector<std::string> args)
        {
            RType::Ressources::get()->players().erase(args[1]);
        }

        void Commands::_handlePosition(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->players()[obj["player_id"]].setGoto(std::stoi(obj["x"]), std::stoi(obj["y"]));
        }
    } // namespace Communication
} // namespace RType