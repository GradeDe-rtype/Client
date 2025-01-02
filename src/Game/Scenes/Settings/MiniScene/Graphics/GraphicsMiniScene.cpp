/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GraphicsMiniScene.hpp"

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
                    GraphicsMiniScene::SectionFrameRate::SectionFrameRate(gd::Vector2<float> size)
                        : RType::Game::Components::SectionRange("settings.frameRate", size, 6, 120, 6)
                    {
                        _range->setValue(gd::FrameRate::get().getFrameRate());
                        setTextValue();
                    }

                    void GraphicsMiniScene::SectionFrameRate::setSettingValue()
                    {
                        gd::FrameRate::get().setFrameRate(_range->getValue());
                    }

                    void GraphicsMiniScene::loadSections(gd::Vector2<float> window)
                    {
                        _sections.push_back(std::make_unique<SectionFrameRate>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
