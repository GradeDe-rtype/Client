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
#include "Ressources.hpp"

#include "GradeDe/Window.hpp"
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/FrameRate.hpp"


/*  ---- FUNCTION ---- */

void handleEvent(gd::Window &window, gd::Event &event)
{
    bool orientationReset = true;
    gd::Vector2<float> position = RType::Ressources::get()->me().shape().getPosition();
    gd::Vector2<float> size = RType::Ressources::get()->me().shape().getSize();

    if (event.close()) window.close();
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape)) window.close();
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) && position.y >= size.y / 2) {
        RType::Ressources::get()->me().shape().move({0, -15});
        RType::Ressources::get()->me().shape().setRotation(-20);
        orientationReset = false;
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) && position.y <= window.getHeight() - size.y / 2) {
        RType::Ressources::get()->me().shape().move({0, 15});
        RType::Ressources::get()->me().shape().setRotation(20);
        orientationReset = false;
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) && position.x >= size.x / 2) {
        RType::Ressources::get()->me().shape().move({-15, 0});
    }
    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) && position.x <= window.getWidth() - size.x) {
        RType::Ressources::get()->me().shape().move({15, 0});
    }
    if (orientationReset) RType::Ressources::get()->me().shape().setRotation(0);
    if (event.joyStick().isConnected()) {
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::A)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Red);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::B)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Green);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::X)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Blue);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::Y)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Yellow);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::LB)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Magenta);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::RB)) RType::Ressources::get()->me().shape().setFillColor(gd::Color::Cyan);
        if (event.joyStick().isButtonPressed(gd::JoyStick::Button::Home)) window.close();
        if (event.joyStick().isJoyStickMoved()) {
            gd::Vector2<float> move = {0, 0};
            if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LX)) {
                float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LX) / 100;
                move.x = 15 * percent;
            }
            if (event.joyStick().isJoyStickMoved(gd::JoyStick::Axis::LY)) {
                float percent = event.joyStick().getAxisPosition(gd::JoyStick::Axis::LY) / 100;
                move.y = 15 * percent;
            }
            RType::Ressources::get()->me().shape().move(move);
        }
    }
}

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        RType::Parsing parsing(argc, argv);
        std::cout << "Port: " << parsing.getPort() << std::endl;
        std::cout << "Ip Adress: " << parsing.getIpAdress() << std::endl;

        RType::Ressources::get();
        gd::Window window;
        window.create(800, 600, "R-Type");
        gd::Event event;
        gd::Time time;
        RType::Ressources::get()->me().shape().setPosition({ (float)(window.getWidth() / 2 - RType::Ressources::get()->me().shape().getSize().x / 2), (float)(window.getHeight() / 2 - RType::Ressources::get()->me().shape().getSize().y / 2) });

        while (window.isOpen()) {
            if (time.getElapsedTime() < gd::FrameRate::get().fps()) continue;
            time.reset();
            window.pollEvent(event);
            handleEvent(window, event);
            window.clear(gd::Color::Black);

            RType::Ressources::get()->me().shape().draw(window);
            window.display();
        }
        window.close();



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
