/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MINI_SCENE_ABSTRACT_HPP_
#define RTYPE_GAME_MINI_SCENE_ABSTRACT_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <vector>
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "Game/Components/SectionRange/SectionRange.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Managers/Scenes/Scenes.hpp"
#include "Game/Scenes/Base/MiniScene/IMiniScene.hpp"
#include "Papaya.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                class AMiniScene : public IMiniScene
                {
                    public:
                        AMiniScene() = default;
                        ~AMiniScene() override = default;
                        void load(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                        void reload(gd::Vector2<float> coord, gd::Vector2<float> window) override;
                        bool handleEvent(gd::Window &window, gd::Event &event) override;
                        void draw(gd::Window &window) override;
                        void loadSections(gd::Vector2<float> window) override;
                        bool changeScene() override;

                    protected:
                        gd::Vector2<float> _window;
                        gd::Vector2<float> _coord;
                        std::vector<std::unique_ptr<RType::Game::Components::SectionRange>> _sections;
                        std::unique_ptr<RType::Game::Components::Text> _save;
                        int _innerPadding = 50;
                        int _sectionGap = 50;
                        gd::Time _input;
                        int _selected = 0;
                        bool _changes = false;
                        bool _changeScene = false;

                        void _moveSelected(int value);
                        void _saveSettings();
                };
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SETTINGS_MINI_SCENE_ABSTRACT_HPP_ */
