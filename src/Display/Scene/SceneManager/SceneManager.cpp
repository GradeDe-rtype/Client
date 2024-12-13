/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SceneManager.hpp"

namespace RType
{
    namespace Display
    {
        namespace Scene
        {
            SceneManager::SceneManager(gd::Window &window)
            {
                _musicManager = std::make_unique<RType::Display::Audio::MusicManager>();
                _musicManager->setVolume(100);
                _transitionShape.createRectangle((float)window.getWidth(), (float)window.getHeight());
                _transitionShape.setFillColor(_transitionColor);
                _transitionShape.setPosition((gd::Vector2<float>){0, 0});

                _addScene("game", std::make_shared<RType::Display::Scene::Game>(), window);
                _addScene("menu", std::make_shared<RType::Display::Scene::Menu>(), window);

                _currentScene = _scenes["menu"];
                _musicManager->setMusic("menu");
                _musicManager->setVolume(0);
                _currentScene->enter();
            }

            void SceneManager::changeScene(const std::string &name)
            {
                _nextScene = name;
                _transitionOpacity = 0;
                _transitionState = FADE_IN;
                _backupVolume = _musicManager->getVolume();
                _volumeTransition = _backupVolume / _transitionFrame;
            }

            std::shared_ptr<IScene> SceneManager::getScene()
            {
                return _currentScene;
            }

            void SceneManager::update()
            {
                if (_transitionState == FADE_IN) {
                    _transitionOpacity += _transitionSpeed;
                    _musicManager->modifyVolume(-_volumeTransition);
                    if (_transitionOpacity >= 255) {
                        _transitionOpacity = 255;
                        _transitionState = FADE_OUT;
                        _currentScene->leave();
                        _currentScene = _scenes[_nextScene];
                        _musicManager->setMusic(_nextScene);
                        _currentScene->enter();
                    }
                } else if (_transitionState == FADE_OUT) {
                    _transitionOpacity -= _transitionSpeed;
                    _musicManager->modifyVolume(_volumeTransition);
                    if (_transitionOpacity <= 0) {
                        _musicManager->setVolume(_backupVolume);
                        _transitionOpacity = 0;
                        _transitionState = NOTHING;
                    }
                }

                if (_transitionState != NOTHING) {
                    _transitionColor = gd::Color(0, 0, 0, _transitionOpacity);
                    _transitionShape.setFillColor(_transitionColor);
                }
            }

            void SceneManager::draw(gd::Window &window)
            {
                window.draw(_transitionShape);
            }

            bool SceneManager::isTransitioning() const
            {
                return _transitionState != NOTHING;
            }

            void SceneManager::_addScene(const std::string &name, std::shared_ptr<IScene> scene, gd::Window &window)
            {
                _scenes[name] = scene;
                _scenes[name]->load(window);
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
