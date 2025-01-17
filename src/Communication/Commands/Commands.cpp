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
        Commands::Commands(std::shared_ptr<SendList> sendList) : _sendList(sendList)
        {
            _sendList = sendList;

            _commands["create"] = &Commands::_handleCreateRoom;
            _commands["join"] = &Commands::_handleJoinRoom;
            _commands["list"] = &Commands::_handleListRooms;
            _commands["r_info"] = &Commands::_handleRoomInfo;
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
            _sendList->push("join " + args[1]);
        }

        void Commands::_handleJoinRoom(std::vector<std::string> args)
        {
            RType::Game::Managers::Scenes::get().changeScene("game");
            RType::Ressources::get()->roomState = RType::Ressources::RoomState::NEXT_WAVE;
        }

        void Commands::_handleListRooms(std::vector<std::string> args)
        {
            std::vector<std::string> rooms = rfcArgParser::ParseArray(args[1]);
            Ressources::get()->roomGameSlots.clear();
            for (auto &room : rooms)
                _sendList->push("r_info " + room);
        }

        void Commands::_handleRoomInfo(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            for (auto &key : {"name", "mode", "count", "id"}) {
                if (obj.count(key) == 0) std::cerr << "Invalid room object, missing \"" << key << "\" key" << std::endl;
                if (obj.count(key) == 0) return;
            }
            RType::Ressources::get()->roomGameSlots.push_back(std::make_shared<RType::Game::Components::RoomGameSlot>(std::stoi(obj["id"]), obj));
            RType::Ressources::get()->majRoom = true;
        }

        void Commands::_handlePlayerConnection(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->playersMutex.lock();
            RType::Ressources::get()->players[obj["id"]] = std::make_shared<RType::Game::Entity::Player>(std::stoi(obj["id"]), obj["color"]);
            RType::Ressources::get()->playersMutex.unlock();
            RType::Ressources::get()->shootsMutex.lock();
            RType::Ressources::get()->shoots["player"][obj["id"]] = std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Shoot>>();
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleYouConnection(std::vector<std::string> args)
        {
            _handlePlayerConnection(args);
            RType::Ressources::get()->playersMutex.lock();
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->me = RType::Ressources::get()->players[obj["id"]];
            RType::Ressources::get()->me->setOutlineColor(gd::Color::White);
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handlePlayerDisconnection(std::vector<std::string> args)
        {
            RType::Ressources::get()->playersMutex.lock();
            RType::Ressources::get()->players.erase(args[1]);
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handlePlayerColor(std::vector<std::string> args)
        {
            RType::Ressources::get()->playersMutex.lock();
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) {
                RType::Ressources::get()->playersMutex.unlock();
                return;
            }
            RType::Ressources::get()->players[args[1]]->setColor(args[2]);
            RType::Ressources::get()->playersMutex.unlock();
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
            RType::Ressources::get()->playersMutex.lock();
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) {
                RType::Ressources::get()->playersMutex.unlock();
                return;
            }
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->players[args[1]]->setGoto(std::stoi(obj["x"]), std::stoi(obj["y"]));
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handlePlayerDamage(std::vector<std::string> args)
        {
            RType::Ressources::get()->playersMutex.lock();
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) {
                RType::Ressources::get()->playersMutex.unlock();
                return;
            }
            RType::Ressources::get()->players[args[1]]->takeDamage(std::stoi(args[2]));
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handlePlayerDeath(std::vector<std::string> args)
        {
            RType::Ressources::get()->playersMutex.lock();
            if (RType::Ressources::get()->players.find(args[1]) == RType::Ressources::get()->players.end()) {
                RType::Ressources::get()->playersMutex.unlock();
                return;
            }
            RType::Ressources::get()->players[args[1]]->die();
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handlePlayerInfo(std::vector<std::string> args)
        {
            RType::Ressources::get()->playersMutex.lock();
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            if (RType::Ressources::get()->players.find(obj["id"]) == RType::Ressources::get()->players.end()) {
                RType::Ressources::get()->playersMutex.unlock();
                return;
            }
            RType::Ressources::get()->players[obj["id"]]->setHealth(std::stoi(obj["health"]));
            RType::Ressources::get()->players[obj["id"]]->setPosition(std::stof(obj["x"]), std::stof(obj["y"]));
            RType::Ressources::get()->playersMutex.unlock();
        }

        void Commands::_handleEnemyCreation(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->enemiesMutex.lock();
            RType::Ressources::get()->enemies[obj["id"]] = std::make_shared<RType::Game::Entity::Enemy>(std::stoi(obj["id"]), static_cast<RType::Game::Entity::Enemy::Type>(std::stoi(obj["type"])), std::stof(obj["x"]), std::stof(obj["y"]), std::stoi(obj["size"]), std::stoi(obj["health"]));
            RType::Ressources::get()->enemiesMutex.unlock();
            RType::Ressources::get()->shootsMutex.lock();
            RType::Ressources::get()->shoots["enemy"][obj["id"]] = std::unordered_map<std::string, std::shared_ptr<RType::Game::Entity::Shoot>>();
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleEnemyPosition(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemiesMutex.lock();
            if (RType::Ressources::get()->enemies.find(args[1]) == RType::Ressources::get()->enemies.end()) {
                RType::Ressources::get()->enemiesMutex.unlock();
                return;
            }
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->enemies[args[1]]->setPosition(std::stof(obj["x"]), std::stof(obj["y"]));
            RType::Ressources::get()->enemiesMutex.unlock();
        }

        void Commands::_handleEnemyDamage(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemiesMutex.lock();
            if (RType::Ressources::get()->enemies.find(args[1]) == RType::Ressources::get()->enemies.end()) {
                RType::Ressources::get()->enemiesMutex.unlock();
                return;
            }
            RType::Ressources::get()->enemies[args[1]]->takeDamage(std::stoi(args[2]));
            RType::Ressources::get()->enemiesMutex.unlock();
        }

        void Commands::_handleEnemyDeath(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemiesMutex.lock();
            if (RType::Ressources::get()->enemies.find(args[1]) == RType::Ressources::get()->enemies.end()) {
                RType::Ressources::get()->enemiesMutex.unlock();
                return;
            }
            RType::Ressources::get()->enemies.erase(args[1]);
            RType::Ressources::get()->enemiesMutex.unlock();
        }

        void Commands::_handleEnemyInfo(std::vector<std::string> args)
        {
            RType::Ressources::get()->enemiesMutex.lock();
            if (RType::Ressources::get()->enemies.find(args[1]) == RType::Ressources::get()->enemies.end()) {
                RType::Ressources::get()->enemiesMutex.unlock();
                return;
            }
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->enemies[obj["id"]]->setHealth(std::stoi(obj["health"]));
            RType::Ressources::get()->enemies[obj["id"]]->setPosition(std::stof(obj["x"]), std::stof(obj["y"]));
            RType::Ressources::get()->enemiesMutex.unlock();
        }

        void Commands::_handleShootCreation(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shootsMutex.lock();
            if (RType::Ressources::get()->shoots.find(obj["from"]) == RType::Ressources::get()->shoots.end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            if (RType::Ressources::get()->shoots[obj["from"]].find(obj["related"]) == RType::Ressources::get()->shoots[obj["from"]].end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            gd::Vector2<float> pos;
            if (obj["from"] == "player") {
                RType::Ressources::get()->playersMutex.lock();
                if (RType::Ressources::get()->players.find(obj["related"]) == RType::Ressources::get()->players.end()) {
                    RType::Ressources::get()->playersMutex.unlock();
                    return;
                }
                pos = RType::Ressources::get()->players[obj["related"]]->getPosition();
                RType::Ressources::get()->playersMutex.unlock();
            } else {
                RType::Ressources::get()->enemiesMutex.lock();
                if (RType::Ressources::get()->enemies.find(obj["related"]) == RType::Ressources::get()->enemies.end()) {
                    RType::Ressources::get()->enemiesMutex.unlock();
                    return;
                }
                pos = RType::Ressources::get()->enemies[obj["related"]]->getPosition();
                RType::Ressources::get()->enemiesMutex.unlock();
            }
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]][obj["id"]] = std::make_shared<RType::Game::Entity::Shoot>(pos.x, pos.y, obj["from"]);
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleShootPosition(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            std::unordered_map<std::string, std::string> position = rfcArgParser::ParseObject(args[2]);
            RType::Ressources::get()->shootsMutex.lock();
            if (RType::Ressources::get()->shoots.find(obj["from"]) == RType::Ressources::get()->shoots.end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            if (RType::Ressources::get()->shoots[obj["from"]].find(obj["related"]) == RType::Ressources::get()->shoots[obj["from"]].end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            if (RType::Ressources::get()->shoots[obj["from"]][obj["related"]].find(obj["id"]) == RType::Ressources::get()->shoots[obj["from"]][obj["related"]].end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]][obj["id"]]->setPosition(std::stoi(position["x"]), std::stoi(position["y"]));
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleShootDeath(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shootsMutex.lock();
            if (RType::Ressources::get()->shoots.find(obj["from"]) == RType::Ressources::get()->shoots.end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            if (RType::Ressources::get()->shoots[obj["from"]].find(obj["related"]) == RType::Ressources::get()->shoots[obj["from"]].end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            if (RType::Ressources::get()->shoots[obj["from"]][obj["related"]].find(obj["id"]) == RType::Ressources::get()->shoots[obj["from"]][obj["related"]].end()) {
                RType::Ressources::get()->shootsMutex.unlock();
                return;
            }
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]].erase(obj["id"]);
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleShootInfo(std::vector<std::string> args)
        {
            std::unordered_map<std::string, std::string> obj = rfcArgParser::ParseObject(args[1]);
            RType::Ressources::get()->shootsMutex.lock();
            RType::Ressources::get()->shoots[obj["from"]][obj["related"]][obj["id"]]->setPosition(std::stof(obj["x"]), std::stof(obj["y"]));
            RType::Ressources::get()->shootsMutex.unlock();
        }

        void Commands::_handleGameWave(std::vector<std::string> args)
        {
            RType::Ressources::get()->wave = std::stoi(args[1]);
            RType::Ressources::get()->playersMutex.lock();
            for (auto &player : RType::Ressources::get()->players)
                if (!player.second->getIsAlive())
                    player.second->respawn();
            RType::Ressources::get()->playersMutex.unlock();
            RType::Ressources::get()->enemiesMutex.lock();
            RType::Ressources::get()->enemies.clear();
            RType::Ressources::get()->enemiesMutex.unlock();
            RType::Ressources::get()->roomState = RType::Ressources::RoomState::NEXT_WAVE;
            RType::Ressources::get()->clearShoots({"enemy"});
            RType::Ressources::get()->cleanShoots({"player"});
        }

        void Commands::_handleRoomEndGame(std::vector<std::string> args)
        {
            RType::Ressources::get()->endWin = (args[1] == "win");
            RType::Ressources::get()->roomState = RType::Ressources::RoomState::END;
            RType::Ressources::get()->enemiesMutex.lock();
            RType::Ressources::get()->enemies.clear();
            RType::Ressources::get()->enemiesMutex.unlock();
            RType::Ressources::get()->clearShoots();
        }
    } // namespace Communication
} // namespace RType