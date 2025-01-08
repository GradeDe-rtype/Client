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
            _commands["create"] = &Commands::_handleCreateRoom;
            _commands["join"] = &Commands::_handleJoinRoom;
            _commands["list"] = &Commands::_handleListRooms;
            _commands["info"] = &Commands::_handleRoomInfo;
            _commands["connect"] = &Commands::_handlePlayerConnection;
            _commands["connect_you"] = &Commands::_handleYouConnection;
            _commands["disconnect"] = &Commands::_handlePlayerDisconnection;
            _commands["color"] = &Commands::_handlePlayerColor;
            _commands["mode"] = &Commands::_handleRoomMode;
            _commands["start"] = &Commands::_handleRoomStartGame;
            _commands["p_position"] = &Commands::_handlePlayerPosition;
            _commands["p_damage"] = &Commands::_handlePlayerDamage;
            _commands["p_death"] = &Commands::_handlePlayerDeath;
            _commands["p_info"] = &Commands::_handlePlayerInfo;
            _commands["enemy"] = &Commands::_handleEnemyCreation;
            _commands["e_position"] = &Commands::_handleEnemyPosition;
            _commands["e_damage"] = &Commands::_handleEnemyDamage;
            _commands["e_death"] = &Commands::_handleEnemyDeath;
            _commands["e_info"] = &Commands::_handleEnemyInfo;
            _commands["shoot"] = &Commands::_handleShootCreation;
            _commands["s_position"] = &Commands::_handleShootPosition;
            _commands["s_death"] = &Commands::_handleShootDeath;
            _commands["s_info"] = &Commands::_handleShootInfo;
            _commands["wave"] = &Commands::_handleGameWave;
            _commands["end"] = &Commands::_handleRoomEndGame;
        }

        void Commands::handleCommand(std::string command)
        {
            try {
                std::vector<std::string> args = Helpers::Utils::split(command, " ");
                if (_commands.find(args[0]) != _commands.end())
                    (this->*_commands[args[0]])(args);
            } catch (rfcArgParser::Error &e) {
                e.read();
            }
        }

        void Commands::_handleCreateRoom(std::vector<std::string> args)
        {
            std::cerr << "\"create\" command not implemented yet" << std::endl;
        }

        void Commands::_handleJoinRoom(std::vector<std::string> args)
        {
            std::cerr << "\"join\" command not implemented yet" << std::endl;
        }

        void Commands::_handleListRooms(std::vector<std::string> args)
        {
            std::cerr << "\"list\" command not implemented yet" << std::endl;
        }

        void Commands::_handleRoomInfo(std::vector<std::string> args)
        {
            std::cerr << "\"info\" command not implemented yet" << std::endl;
        }

        void Commands::_handlePlayerConnection(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shoots["player"][obj["id"]] = std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Shoot>>();
            RType::Ressources::get()->players[obj["id"]] = std::make_shared<RType::Game::Entity::Player>(std::stoi(obj["id"]), obj["color"]);
        }

        void Commands::_handleYouConnection(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->players[obj["id"]] = std::make_shared<RType::Game::Entity::Player>(std::stoi(obj["id"]), obj["color"]);
            RType::Ressources::get()->me = RType::Ressources::get()->players[obj["id"]];
        }

        void Commands::_handlePlayerDisconnection(std::vector<std::string> args)
        {
            RType::Ressources::get()->players.erase(args[1]);
        }

        void Commands::_handlePlayerColor(std::vector<std::string> args)
        {
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) return;
            RType::Ressources::get()->players[args[1]]->setColor(args[2]);
        }

        void Commands::_handleRoomMode(std::vector<std::string> args)
        {
            std::cerr << "\"mode\" command not implemented yet" << std::endl;
        }

        void Commands::_handleRoomStartGame(std::vector<std::string> args)
        {
            std::cerr << "\"start\" command not implemented yet" << std::endl;
        }

        void Commands::_handlePlayerPosition(std::vector<std::string> args)
        {
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) return;
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->players[args[1]]->setGoto(std::stoi(obj["x"]), std::stoi(obj["y"]));
        }

        void Commands::_handlePlayerDamage(std::vector<std::string> args)
        {
            std::cerr << "\"p_damage\" command not implemented yet" << std::endl;
        }

        void Commands::_handlePlayerDeath(std::vector<std::string> args)
        {
            RType::Ressources::get()->players[args[1]]->die();
        }

        void Commands::_handlePlayerInfo(std::vector<std::string> args)
        {
            std::cerr << "\"p_info\" command not implemented yet" << std::endl;
        }

        void Commands::_handleEnemyCreation(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shoots["enemy"][obj["id"]] = std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Shoot>>();
            RType::Ressources::get()->enemies[obj["id"]] = std::make_shared<RType::Game::Entity::Enemy>(std::stoi(obj["id"]), static_cast<RType::Game::Entity::Enemy::Type>(std::stoi(obj["type"])), std::stoi(obj["x"]), std::stoi(obj["y"]), std::stoi(obj["health"]));
        }

        void Commands::_handleEnemyPosition(std::vector<std::string> args)
        {
            if (RType::Ressources::get()->enemies.find(args[1]) == RType::Ressources::get()->enemies.end()) return;
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->enemies[args[1]]->setPosition(std::stoi(obj["x"]), std::stoi(obj["y"]));
        }

        void Commands::_handleEnemyDamage(std::vector<std::string> args)
        {
            std::cerr << "\"e_damage\" command not implemented yet" << std::endl;
        }

        void Commands::_handleEnemyDeath(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemies.erase(args[1]);
        }

        void Commands::_handleEnemyInfo(std::vector<std::string> args)
        {
            std::cerr << "\"e_info\" command not implemented yet" << std::endl;
        }

        void Commands::_handleShootCreation(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            gd::Vector2<float> pos = (obj["from"] == "player") ? RType::Ressources::get()->players[obj["related"]]->getPosition() : RType::Ressources::get()->enemies[obj["related"]]->getPosition();
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]][obj["id"]] = std::make_shared<RType::Game::Entity::Shoot>(pos.x, pos.y, obj["from"]);
        }

        void Commands::_handleShootPosition(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            std::unordered_map<std::string, std::string> position = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]][obj["id"]]->setPosition(std::stoi(position["x"]), std::stoi(position["y"]));
        }

        void Commands::_handleShootDeath(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]].erase(obj["id"]);
        }

        void Commands::_handleShootInfo(std::vector<std::string> args)
        {
            std::cerr << "\"s_info\" command not implemented yet" << std::endl;
        }

        void Commands::_handleGameWave(std::vector<std::string> args)
        {
            RType::Ressources::get()->wave = std::stoi(args[1]);
            for (auto &player : RType::Ressources::get()->players)
                if (!player.second->getIsAlive())
                    player.second->respawn();
            RType::Ressources::get()->enemies.clear();
            RType::Ressources::get()->roomState = RType::Ressources::RoomState::NEXT_WAVE;
        }

        void Commands::_handleRoomEndGame(std::vector<std::string> args)
        {
            RType::Ressources::get()->endScore = std::stoi(args[1]);
            RType::Ressources::get()->roomState = RType::Ressources::RoomState::END;
            RType::Ressources::get()->enemies.clear();
        }
    } // namespace Communication
} // namespace RType