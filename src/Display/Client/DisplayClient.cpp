/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "DisplayClient.hpp"

/*  ---- FUNCTION ---- */

namespace RType
{
    namespace Display
    {
        Client::Client()
        {
            RType::Ressources::get();
            _window.create(800, 600, "R-Type");
            RType::Ressources::get()->me().shape().setPosition({(float)(_window.getWidth() / 2 - RType::Ressources::get()->me().shape().getSize().x / 2), (float)(_window.getHeight() / 2 - RType::Ressources::get()->me().shape().getSize().y / 2)});
            _sceneManager = std::make_unique<RType::Display::Scene::SceneManager>(_window);
        }

        void Client::run()
        {
            while (_window.isOpen()) {
                Ressources::get()->update();
                if (_time.getElapsedTime() < gd::FrameRate::get().fps()) continue;
                _time.reset();
                _sceneManager->getScene()->update(_window);
                _handleEvent();
                _draw();
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
            if (_sceneManager->isTransitioning()) return;
            std::string next_scene = _sceneManager->getScene()->handleEvent(_window, _event);
            if (next_scene != "") _sceneManager->changeScene(next_scene);
        }

        void Client::_draw()
        {
            _window.clear(gd::Color::Black);
            _sceneManager->getScene()->draw(_window);
            _sceneManager->draw(_window);
            _window.display();
        }

    } // namespace Display
} // namespace RType
