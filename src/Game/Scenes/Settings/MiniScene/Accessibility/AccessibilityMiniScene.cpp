/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "AccessibilityMiniScene.hpp"

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
                    AccessibilityMiniScene::SectionTextSize::SectionTextSize(gd::Vector2<float> size)
                        : RType::Game::Components::SectionRange("settings.textSize", size, 20, 50, 5)
                    {
                        _range->setValue(RType::Game::Managers::Accessibility::get().getTextSize());
                        setTextValue();
                    }

                    void AccessibilityMiniScene::SectionTextSize::setSettingValue()
                    {
                        RType::Game::Managers::Accessibility::get().setTextSize(_range->getValue());
                    }

                    void AccessibilityMiniScene::loadSections(gd::Vector2<float> window)
                    {
                        _sections.push_back(std::make_unique<SectionTextSize>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
