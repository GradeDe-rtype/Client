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
            _commands["connect"] = &Commands::_handlePlayerConnection;
            _commands["disconnect"] = &Commands::_handlePlayerDisconnection;
            _commands["p_position"] = &Commands::_handlePlayerPosition;
            _commands["shoot"] = &Commands::_handleShoot;
            _commands["enemy"] = &Commands::_handleEnemyAppear;
            _commands["e_death"] = &Commands::_handleEnemyDeath;
            _commands["e_position"] = &Commands::_handleEnemyPosition;
        }

        void Commands::handleCommand(std::string command)
        {
            std::vector<std::string> args = Helpers::Utils::split(command, " ");
            if (_commands.find(args[0]) != _commands.end())
                (this->*_commands[args[0]])(args);
        }

        void Commands::_handlePlayerConnection(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->players()[obj["player_id"]] = std::make_shared<RType::Display::Player>(std::stoi(obj["player_id"]), obj["color"]);
        }

        void Commands::_handlePlayerDisconnection(std::vector<std::string> args)
        {
            RType::Ressources::get()->players().erase(args[1]);
        }

        void Commands::_handlePlayerPosition(std::vector<std::string> args)
        {
            if (RType::Ressources::get()->players().find(args[1]) == RType::Ressources::get()->players().end()) return;
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->players()[args[1]]->setGoto(std::stoi(obj["x"]), std::stoi(obj["y"]));
        }

        void Commands::_handleShoot(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shoots().push_back(std::make_unique<RType::Display::Shoot>(std::stoi(obj["x"]), std::stoi(obj["y"])));
        }

        void Commands::_handleEnemyAppear(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->enemies()[obj["id"]] = std::make_shared<RType::Display::Enemy>(std::stoi(obj["id"]));
        }

        void Commands::_handleEnemyDeath(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemies().erase(args[1]);
        }

        void Commands::_handleEnemyPosition(std::vector<std::string> args)
        {
            if (RType::Ressources::get()->enemies().find(args[1]) == RType::Ressources::get()->enemies().end()) return;
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->enemies()[args[1]]->setPosition(std::stoi(obj["x"]), std::stoi(obj["y"]));
        }
    } // namespace Communication
} // namespace RType