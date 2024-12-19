/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GameClient.hpp"

/*  ---- FUNCTION ---- */

namespace RType
{
    namespace Game
    {
        Client::Client()
        {
            RType::Ressources::get();
            _window.create(800, 600, "R-Type");
            _scenesManager = std::make_unique<RType::Game::Managers::Scenes>(_window);
            if (RType::Ressources::get()->me != nullptr)
                RType::Ressources::get()->me->shape().setPosition({(float)(_window.getWidth() / 2 - RType::Ressources::get()->me->getSize().x / 2), (float)(_window.getHeight() / 2 - RType::Ressources::get()->me->getSize().y / 2)});

            gd::FrameRate::get().setFrameRate(120);
            _starBackground = std::make_unique<RType::Game::Components::StarsBackground>(_window);
        }

        void Client::run()
        {
            while (_window.isOpen() && _scenesManager->getCurrentSceneName() != "exit") {
                Ressources::get()->update();
                _scenesManager->getScene()->update(_window);
                _handleEvent();
                if (_time.getElapsedTime() >= gd::FrameRate::get().fps()) {
                    _draw();
                    _time.reset();
                }
            }
            _window.close();
        }

        void Client::_handleGeneralEvent()
        {
            if (_event.close()) _window.close();
        }

        void Client::_handleEvent()
        {
            _window.pollEvent(_event);
            _handleGeneralEvent();
            _scenesManager->update();
            _starBackground->update(_window);
            if (_scenesManager->isTransitioning()) return;
            std::string next_scene = _scenesManager->getScene()->handleEvent(_window, _event);
            if (next_scene != "") _scenesManager->changeScene(next_scene);
        }

        void Client::_draw()
        {
            _window.clear(gd::Color::Black);
            _starBackground->draw(_window);
            _scenesManager->getScene()->draw(_window);
            _scenesManager->draw(_window);
            _window.display();
        }

    } // namespace Game
} // namespace RType
