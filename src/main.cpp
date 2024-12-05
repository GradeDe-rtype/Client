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
#include "DisplayClient.hpp"
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
        std::shared_ptr<RType::Communication::Client> client = std::make_shared<RType::Communication::Client>(parsing.getIpAdress(), parsing.getPort(), sendList);
        RType::Ressources::get()->setSendList(sendList);

        RType::Helpers::Thread serverThread;
        serverThread.start([client]() { client->run(); });

        RType::Display::Client displayClient;
        displayClient.run();

        client->shutdown();
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
