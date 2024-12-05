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
            for (auto &it : obj)
                std::cout << it.first << " : " << it.second << std::endl;
            gd::Vector2<float> pos = {(float)(rand() % 600 + 100), (float)(rand() % 400 + 100)};
            RType::Ressources::get()->players()[obj["player_id"]] = RType::Display::Player(pos);
        }

        void Commands::_handleDisconnect(std::vector<std::string> args)
        {
            RType::Ressources::get()->players().erase(args[1]);
        }
    } // namespace Communication
} // namespace RType