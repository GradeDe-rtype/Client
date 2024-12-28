/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SETTINGS_SOUNDS_MINI_SCENE_HPP_
#define RTYPE_GAME_SETTINGS_SOUNDS_MINI_SCENE_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "Game/Components/Range/Range.hpp"
#include "Game/Components/SectionRange/SectionRange.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Managers/Music/Music.hpp"
#include "Game/Managers/Sound/Sound.hpp"
#include "Game/Scenes/Base/MiniScene/AMiniScene.hpp"
#include "Helpers/Utils/Utils.hpp"
#include "Papaya.hpp"
#include "Traductor.hpp"

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
                    class SoundsMiniScene : public AMiniScene
                    {
                        public:
                            class SectionSound : public RType::Game::Components::SectionRange
                            {
                                public:
                                    SectionSound(gd::Vector2<float> size);

                                    void setSettingValue() override;
                            };

                            class SectionMusic : public RType::Game::Components::SectionRange
                            {
                                public:
                                    SectionMusic(gd::Vector2<float> size);

                                    void setSettingValue() override;
                            };

                            void load(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                            void reload(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                            bool handleEvent(gd::Event &event) override;
                            void draw(gd::Window &window) override;

                        private:
                            std::vector<std::unique_ptr<RType::Game::Components::SectionRange>> _sections;
                            std::unique_ptr<RType::Game::Components::Text> _save;
                            int _innerPadding = 50;
                            gd::Time _input;
                            int _selected = 0;
                            bool _changes = false;

                            void _changeRangeValue(int value);
                            void _moveSelected(int value);
                            void _saveSettings();
                    };
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_SOUNDS_MINI_SCENE_HPP_ */
