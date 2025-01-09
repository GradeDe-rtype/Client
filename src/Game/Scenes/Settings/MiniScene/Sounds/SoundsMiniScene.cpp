/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SoundsMiniScene.hpp"

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
                    SoundsMiniScene::SectionSound::SectionSound(gd::Vector2<float> size)
                        : RType::Game::Components::SectionRange("settings.sound", size)
                    {
                        _range->setValue(RType::Game::Managers::Sound::get().getVolume());
                        setTextValue();
                        _soundTimer.reset();
                    }

                    void SoundsMiniScene::SectionSound::setSettingValue()
                    {
                        RType::Game::Managers::Sound::get().setVolume(_range->getValue());
                        if (_soundTimer.getElapsedTime() > 100) {
                            RType::Game::Managers::Sound::get().play("beep");
                            _soundTimer.reset();
                        }
                    }

                    SoundsMiniScene::SectionMusic::SectionMusic(gd::Vector2<float> size)
                        : RType::Game::Components::SectionRange("settings.music", size)
                    {
                        _range->setValue(RType::Game::Managers::Music::get().getVolume());
                        setTextValue();
                    }

                    void SoundsMiniScene::SectionMusic::setSettingValue()
                    {
                        RType::Game::Managers::Music::get().setVolume(_range->getValue());
                    }

                    void SoundsMiniScene::loadSections(gd::Vector2<float> window)
                    {
                        _sections.push_back(std::make_unique<SectionSound>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                        _sections.push_back(std::make_unique<SectionMusic>((gd::Vector2<float>){window.x - _innerPadding * 2, 20}));
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
