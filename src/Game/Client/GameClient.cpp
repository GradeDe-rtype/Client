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
            _sceneManager = std::make_unique<RType::Game::Scene::SceneManager>(_window);
            if (RType::Ressources::get()->me != nullptr)
                RType::Ressources::get()->me->shape().setPosition({(float)(_window.getWidth() / 2 - RType::Ressources::get()->me->shape().getSize().x / 2), (float)(_window.getHeight() / 2 - RType::Ressources::get()->me->shape().getSize().y / 2)});

            gd::FrameRate::get().setFrameRate(120);
            _starBackground = std::make_unique<RType::Game::Components::StarsBackground>(_window);
        }

        void Client::run()
        {
            while (_window.isOpen()) {
                Ressources::get()->update();
                _sceneManager->getScene()->update(_window);
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
            _sceneManager->update();
            _starBackground->update(_window);
            if (_sceneManager->isTransitioning()) return;
            std::string next_scene = _sceneManager->getScene()->handleEvent(_window, _event);
            if (next_scene != "") _sceneManager->changeScene(next_scene);
        }

        void Client::_draw()
        {
            _window.clear(gd::Color::Black);
            _starBackground->draw(_window);
            _sceneManager->getScene()->draw(_window);
            _sceneManager->draw(_window);
            _window.display();
        }

    } // namespace Game
} // namespace RType
