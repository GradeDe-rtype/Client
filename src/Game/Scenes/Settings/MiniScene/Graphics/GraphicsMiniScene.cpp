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

                    GraphicsMiniScene::SectionResolution::SectionResolution(gd::Vector2<float> size)
                        : RType::Game::Components::SectionRange("settings.resolution", size, 0, (int)RType::Game::Managers::Resolution::get().getAvailableResolutions().size() - 1, 1)
                    {
                        for (int i = 0; i < (int)RType::Game::Managers::Resolution::get().getAvailableResolutions().size(); i++)
                            if (RType::Game::Managers::Resolution::get().getCurrentResolution() == RType::Game::Managers::Resolution::get().getAvailableResolutions()[i])
                                _range->setValue(i);
                        setTextValue();
                    }

                    void GraphicsMiniScene::SectionResolution::setTextValue()
                    {
                        std::string text = Traductor::get()->translate(_name);
                        text.replace(text.find("{value}"), 7, RType::Game::Managers::Resolution::get().getAvailableResolutions()[(int)_range->getValue()]);
                        _text->setText(text);
                    }

                    std::string GraphicsMiniScene::SectionResolution::saveValue() const
                    {
                        return RType::Game::Managers::Resolution::get().getAvailableResolutions()[(int)_range->getValue()];
                    }

                    void GraphicsMiniScene::SectionResolution::setSettingValue()
                    {
                        RType::Game::Managers::Resolution::get().setResolution(RType::Game::Managers::Resolution::get().getAvailableResolutions()[(int)_range->getValue()]);
                    }

                    void GraphicsMiniScene::loadSections(gd::Vector2<float> window)
                    {
                        _sections.push_back(std::make_unique<SectionFrameRate>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                        _sections.push_back(std::make_unique<SectionResolution>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
