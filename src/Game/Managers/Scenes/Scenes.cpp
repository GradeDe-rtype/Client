/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Scenes.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Scenes &Scenes::get()
            {
                static Scenes instance;
                return instance;
            }

            void Scenes::load(gd::Window &window)
            {
                _transitionShape.createRectangle((float)window.getWidth(), (float)window.getHeight());
                _transitionShape.setFillColor(_transitionColor);
                _transitionShape.setPosition((gd::Vector2<float>){0, 0});

                _addScene("settings", std::make_shared<RType::Game::Scenes::Settings>(), window);
                _addScene("exit", std::make_shared<RType::Game::Scenes::AScene>(), window);
                _addScene("menu", std::make_shared<RType::Game::Scenes::Menu>(), window);
                _addScene("game", std::make_shared<RType::Game::Scenes::Game>(), window);
                _addScene("roomsList", std::make_shared<RType::Game::Scenes::RoomsList>(), window);

                _currentSceneName = "menu";
                _currentScene = _scenes["menu"];
                RType::Game::Managers::Music::get().setMusic("menu");
                _currentScene->enter();
                _timer.reset();
            }

            void Scenes::reload(gd::Window &window)
            {
                if (!_needReload) return;
                _needReload = false;
                for (auto &scene : _scenes)
                    scene.second->reload(window);
            }

            void Scenes::changeScene(const std::string &name)
            {
                _nextScene = name;
                _transitionOpacity = 0;
                _transitionState = FADE_IN;
                _backupVolume = RType::Game::Managers::Music::get().getVolume();
                _volumeTransition = _backupVolume / _transitionFrame;
            }

            std::shared_ptr<RType::Game::Scenes::IScene> Scenes::getScene()
            {
                return _currentScene;
            }

            void Scenes::update()
            {
                if (_timer.getElapsedTime() <= _transitionDuration / _transitionFrame) return;
                _timer.reset();
                if (_transitionState == FADE_IN) {
                    _transitionOpacity += _transitionSpeed;
                    RType::Game::Managers::Music::get().modifyVolume(-_volumeTransition);
                    if (_transitionOpacity >= 255) {
                        _transitionOpacity = 255;
                        _transitionState = FADE_OUT;
                        _currentScene->leave();
                        _currentSceneName = _nextScene;
                        _currentScene = _scenes[_nextScene];
                        RType::Game::Managers::Music::get().setMusic(_nextScene);
                        _currentScene->enter();
                    }
                } else if (_transitionState == FADE_OUT) {
                    _transitionOpacity -= _transitionSpeed;
                    RType::Game::Managers::Music::get().modifyVolume(_volumeTransition);
                    if (_transitionOpacity <= 0) {
                        RType::Game::Managers::Music::get().setVolume(_backupVolume);
                        _transitionOpacity = 0;
                        _transitionState = NOTHING;
                    }
                }

                if (_transitionState != NOTHING) {
                    _transitionColor = gd::Color(0, 0, 0, _transitionOpacity);
                    _transitionShape.setFillColor(_transitionColor);
                }
            }

            void Scenes::draw(gd::Window &window)
            {
                window.draw(_transitionShape);
            }

            bool Scenes::isTransitioning() const
            {
                return _transitionState != NOTHING;
            }

            std::string Scenes::getCurrentSceneName() const
            {
                return _currentSceneName;
            }

            void Scenes::needToReload()
            {
                _needReload = true;
            }

            void Scenes::_addScene(const std::string &name, std::shared_ptr<RType::Game::Scenes::IScene> scene, gd::Window &window)
            {
                _scenes[name] = scene;
                _scenes[name]->load(window);
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType
