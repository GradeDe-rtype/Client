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
            RType::Game::Managers::Sound::get();

            Traductor::get()->loadLang("assets/lang/en.json", "EN");
            Traductor::get()->loadLang("assets/lang/fr.json", "FR");

            Papaya settings("./assets/data", "settings");
            Traductor::get()->setLang(settings.getData("setting", "lang", "value"));
            RType::Game::Managers::Music::get().setVolume(std::stoi(settings.getData("setting", "music", "value")));
            RType::Game::Managers::Sound::get().setVolume(std::stoi(settings.getData("setting", "sound", "value")));
            gd::FrameRate::get().setFrameRate(std::stoi(settings.getData("setting", "frameRate", "value")));
            RType::Game::Managers::Accessibility::get().setTextSize(std::stoi(settings.getData("setting", "textSize", "value")));
            RType::Game::Managers::Resolution::get().setResolution(settings.getData("setting", "resolution", "value"));
            RType::Game::Managers::Resolution::get().updateResolution();
            std::pair<int, int> resolution = RType::Game::Managers::Resolution::get().getResolution();

            _window.create(resolution.first, resolution.second, "R-Type");
            RType::Game::Managers::Scenes::get().load(_window);
            if (RType::Ressources::get()->me != nullptr)
                RType::Ressources::get()->me->shape().setPosition({(float)(_window.getWidth() / 2 - RType::Ressources::get()->me->getSize().x / 2), (float)(_window.getHeight() / 2 - RType::Ressources::get()->me->getSize().y / 2)});

            gd::FrameRate::get().setFrameRate(120);
            _starBackground = std::make_unique<RType::Game::Components::StarsBackground>(_window);
        }

        void Client::run()
        {
            while (_window.isOpen() && RType::Game::Managers::Scenes::get().getCurrentSceneName() != "exit") {
                Ressources::get()->update();
                RType::Game::Managers::Sound::get().update();
                _checkWindowResize();
                RType::Game::Managers::Scenes::get().reload(_window);
                RType::Game::Managers::Scenes::get().getScene()->update(_window);
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
            RType::Game::Managers::Scenes::get().update(_window);
            _starBackground->update(_window);
            if (RType::Game::Managers::Scenes::get().isTransitioning()) return;
            std::string next_scene = RType::Game::Managers::Scenes::get().getScene()->handleEvent(_window, _event);
            if (next_scene != "") RType::Game::Managers::Scenes::get().changeScene(next_scene);
        }

        void Client::_draw()
        {
            _window.clear(gd::Color::Black);
            _starBackground->draw(_window);
            RType::Game::Managers::Scenes::get().getScene()->draw(_window);
            RType::Game::Managers::Scenes::get().draw(_window);
            _window.display();
        }

        void Client::_checkWindowResize()
        {
            if (RType::Game::Managers::Resolution::get().getCurrentResolution() != RType::Game::Managers::Resolution::get().getNextResolution()) {
                _window.close();
                RType::Game::Managers::Resolution::get().updateResolution();
                std::pair<int, int> resolution = RType::Game::Managers::Resolution::get().getResolution();
                RType::Game::Managers::Scenes::get().needToReload();
                _window.create(resolution.first, resolution.second);
            }
        }

    } // namespace Game
} // namespace RType
