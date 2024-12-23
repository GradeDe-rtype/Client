/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MINI_SCENE_ABSTRACT_HPP_
#define RTYPE_GAME_MINI_SCENE_ABSTRACT_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "Game/Scenes/Base/MiniScene/IMiniScene.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                class AMiniScene : public IMiniScene
                {
                    public:
                        AMiniScene() = default;
                        ~AMiniScene() override = default;
                        void load(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                        void reload(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                        bool handleEvent(gd::Event &event) override;
                        void draw(gd::Window &window) override;

                    protected:
                        gd::Vector2<float> _window;
                        gd::Vector2<float> _coord;
                };
            }; // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_MINI_SCENE_ABSTRACT_HPP_ */
