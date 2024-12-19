/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_
#define RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Shape.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Scenes/Base/MiniScene/AMiniScene.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                namespace Settings
                {
                    class GraphicsMiniScene : public AMiniScene
                    {
                        public:
                            void load(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                            bool handleEvent(gd::Event &event) override;
                            void draw(gd::Window &window) override;

                        private:
                            std::unique_ptr<RType::Game::Components::Text> _title;
                    };
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_ */
