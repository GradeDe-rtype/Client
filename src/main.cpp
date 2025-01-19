/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include <ctime>
#include <filesystem>
#include <iostream>
#include <memory>
#include "Communication/Client/CommunicationClient.hpp"
#include "Communication/SendList/SendList.hpp"
#include "Game/Client/GameClient.hpp"
#include "Helpers/Thread/Thread.hpp"
#include "Parsing/Parsing.hpp"

/*  ---- FUNCTION ---- */
void _createPapayaFile()
{
    if (!std::filesystem::exists(RType::Helpers::Path::get()->path() + "data"))
        std::filesystem::create_directories(RType::Helpers::Path::get()->path() + "data");

    if (!std::filesystem::exists(RType::Helpers::Path::get()->path() + "data/connect.papaya")) {
        std::filesystem::path path = RType::Helpers::Path::get()->path() + "data/connect.papaya";
        std::ofstream file_connect(path);
        file_connect << "ref;port;ip adress" << std::endl;
        file_connect << "ref;4666;0.0.0.0" << std::endl;
        file_connect.close();
    }

    if (!std::filesystem::exists(RType::Helpers::Path::get()->path() + "data/settings.papaya")) {
        std::filesystem::path path = RType::Helpers::Path::get()->path() + "data/settings.papaya";
        std::ofstream file_settings(path);
        file_settings << "setting;value" << std::endl;
        file_settings << "music;50" << std::endl;
        file_settings << "sound;50" << std::endl;
        file_settings << "frameRate;24" << std::endl;
        file_settings << "lang;EN" << std::endl;
        file_settings << "textSize;25" << std::endl;
        file_settings << "resolution;800x600" << std::endl;
        file_settings.close();
    }
}

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        _createPapayaFile();
        RType::Parsing parsing(argc, argv);

        std::shared_ptr<RType::Communication::SendList> sendList = std::make_shared<RType::Communication::SendList>();
        std::shared_ptr<RType::Communication::Client> communicationclient = std::make_shared<RType::Communication::Client>(parsing.getIpAdress(), parsing.getPort(), sendList);
        sendList->setClient(communicationclient.get());
        RType::Ressources::get()->sendList = sendList;

        RType::Helpers::Thread serverThread;
        serverThread.start([communicationclient]() { communicationclient->run(); });

        RType::Game::Client gameClient;
        gameClient.run();

        communicationclient->shutdown();
        serverThread.join();

    } catch (const RType::Parsing::ParsingError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << ">> Use -help for help." << std::endl;
        return 84;
    } catch (const RType::Parsing::Help &e) {
        e.what();
        return 0;
    }
    return 0;
}
