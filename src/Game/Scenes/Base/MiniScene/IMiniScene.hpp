/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MINI_SCENE_INTERFACE_HPP_
#define RTYPE_GAME_MINI_SCENE_INTERFACE_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                class IMiniScene
                {
                    public:
                        virtual ~IMiniScene() = default;
                        virtual void load(gd::Vector2<float> coord, gd::Vector2<float> window) = 0;
                        virtual bool handleEvent(gd::Event &event) = 0;
                        virtual void draw(gd::Window &window) = 0;
                };
            }; // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_MINI_SCENE_INTERFACE_HPP_ */
