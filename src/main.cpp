/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "RType.hpp"
#include "Parsing.hpp"
#include "Papaya.hpp"
#include "Path.hpp"

/*  ---- FUNCTION ---- */

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        RType::Parsing parsing(argc, argv);
        std::cout << "Port: " << parsing.getPort() << std::endl;
        std::cout << "Machine: " << parsing.getMachine() << std::endl;

        // std::shared_ptr<Zappy::Server::Server> server = std::make_shared<Zappy::Server::Server>(parsing.getMachine(), parsing.getPort());
        // server->setRessources(Zappy::GUI::Ressources::Ref::get()->ressources);
        // Zappy::GUI::Ressources::Ref::get()->shared_memory = server->getSharedMemory();
        // Zappy::Server::Thread serverThread;
        // serverThread.start([server]() { server->run(); });

        // Zappy::GUI::SceneManager sceneManager;
        // sceneManager.run();
        // server->shutdown();
        // serverThread.join();
    } catch (const RType::Parsing::ParsingError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << ">> Use -help for help." << std::endl;
        return 84;
    } catch (const RType::Parsing::Help &e) {
        e.what();
        return 0;
    // } catch (const Exceptions::ConnexionServeurFail &e) {
    //     std::cerr << "Server connection error: " << e.what() << std::endl;
    //     return 84;
    // } catch (const std::exception &e) {
    //     std::cerr << "Unexpected error: " << e.what() << std::endl;
    //     return 84;
    }
    return 0;
}
