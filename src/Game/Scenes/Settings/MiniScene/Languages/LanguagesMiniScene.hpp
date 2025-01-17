/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SETTINGS_LANGUAGES_MINI_SCENE_HPP_
#define RTYPE_GAME_SETTINGS_LANGUAGES_MINI_SCENE_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include "GradeDe/Event.hpp"
#include "GradeDe/FrameRate.hpp"
#include "GradeDe/RectangleShape.hpp"
#include "GradeDe/Time.hpp"
#include "Game/Components/Range/Range.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Entity/SelectArrow/SelectArrow.hpp"
#include "Game/Managers/Music/Music.hpp"
#include "Game/Managers/Scenes/Scenes.hpp"
#include "Game/Scenes/Base/MiniScene/AMiniScene.hpp"
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
                    class LanguagesMiniScene : public AMiniScene
                    {
                        public:
                            void load(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                            void reload(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                            bool handleEvent(gd::Window &window, gd::Event &event) override;
                            void draw(gd::Window &window) override;

                        private:
                            std::unique_ptr<RType::Game::Components::Text> _save;
                            std::vector<std::tuple<std::string, std::shared_ptr<RType::Game::Components::Text>>> _langs;
                            std::shared_ptr<RType::Game::Components::Text> _selectedLang;
                            std::unique_ptr<RType::Game::Entity::SelectArrow> _selectArrow;
                            int _innerPadding = 50;
                            gd::Time _input;
                            int _selected = 0;
                            bool _changes = false;

                            void _moveSelected(int value);
                            void _saveSettings();
                            void _changeSelectedLang();
                    };
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_LANGUAGES_MINI_SCENE_HPP_ */
