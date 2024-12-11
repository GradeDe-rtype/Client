/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_SCENE_SCENE_MANAGER_HPP_
#define RTYPE_DISPLAY_SCENE_SCENE_MANAGER_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <unordered_map>
#include "GameScene.hpp"
#include "GradeDe/Color.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "IScene.hpp"
#include "MenuScene.hpp"
#include "MusicManager.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        namespace Scene
        {
            class SceneManager
            {
                public:
                    SceneManager(gd::Window &window);
                    ~SceneManager() = default;

                    void changeScene(const std::string &name);
                    std::shared_ptr<IScene> getScene();
                    void update();
                    void draw(gd::Window &window);
                    bool isTransitioning() const;

                private:
                    typedef enum {
                        FADE_IN,
                        FADE_OUT,
                        NOTHING,
                    } TransitionState;

                    int _transitionFrame = 20;
                    int _transitionSpeed = 255 / _transitionFrame;
                    int _backupVolume = 100;
                    int _volumeTransition = 100 / _transitionFrame;
                    std::shared_ptr<IScene> _currentScene = nullptr;
                    std::string _nextScene = "";
                    TransitionState _transitionState = NOTHING;
                    int _transitionOpacity = 0;
                    std::unordered_map<std::string, std::shared_ptr<IScene>> _scenes = {};
                    gd::Shape _transitionShape;
                    gd::Color _transitionColor = gd::Color::Transparent;
                    std::unique_ptr<RType::Display::Audio::MusicManager> _musicManager = nullptr;

                    void _addScene(const std::string &name, std::shared_ptr<IScene> scene, gd::Window &window);
            };
        } // namespace Scene
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_SCENE_SCENE_MANAGER_HPP_ */
