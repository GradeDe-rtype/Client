/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_
#define RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_

/*  ---- INCLUDES ---- */
#include "GradeDe/FrameRate.hpp"
#include "Game/Components/SectionRange/SectionRange.hpp"
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
                            class SectionFrameRate : public RType::Game::Components::SectionRange
                            {
                                public:
                                    SectionFrameRate(gd::Vector2<float> size);

                                    void setSettingValue() override;
                            };

                            void loadSections(gd::Vector2<float> window) override;
                    };
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_GRAPHICS_MINI_SCENE_HPP_ */
