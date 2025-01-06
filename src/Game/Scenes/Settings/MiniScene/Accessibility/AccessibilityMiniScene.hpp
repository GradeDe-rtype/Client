/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SETTINGS_ACCESSIBILITY_MINI_SCENE_HPP_
#define RTYPE_GAME_SETTINGS_ACCESSIBILITY_MINI_SCENE_HPP_

/*  ---- INCLUDES ---- */
#include "Game/Components/SectionRange/SectionRange.hpp"
#include "Game/Managers/Accessibility/AccessibilityManager.hpp"
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
                    class AccessibilityMiniScene : public AMiniScene
                    {
                        public:
                            class SectionTextSize : public RType::Game::Components::SectionRange
                            {
                                public:
                                    SectionTextSize(gd::Vector2<float> size);

                                    void setSettingValue() override;
                            };

                            void loadSections(gd::Vector2<float> window) override;
                    };
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_ACCESSIBILITY_MINI_SCENE_HPP_ */
