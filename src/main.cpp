/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include <ctime>
#include <iostream>
#include <memory>
#include "CommunicationClient.hpp"
#include "GameClient.hpp"
#include "Parsing.hpp"
#include "SendList.hpp"
#include "Thread.hpp"

/*  ---- FUNCTION ---- */

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
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
