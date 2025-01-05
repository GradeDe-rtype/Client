/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_SETTINGS_HPP_
#define RTYPE_GAME_SCENE_SETTINGS_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include "GradeDe/Event.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/TextBox/TextBox.hpp"
#include "Game/Entity/SelectArrow/SelectArrow.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Game/Scenes/Base/MiniScene/IMiniScene.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            class Settings : public AScene
            {
                public:
                    void load(gd::Window &window) override;
                    void reload(gd::Window &window) override;
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;

                private:
                    std::vector<std::tuple<std::string, std::unique_ptr<RType::Game::Components::TextBox>, std::unique_ptr<RType::Game::Scenes::MiniScene::IMiniScene>>> _links;
                    std::unique_ptr<RType::Game::Entity::SelectArrow> _selectArrow;
                    std::vector<gd::RectangleShape> _rectangles;
                    int _linkGap = 25;
                    int _linkSpacing = 50;
                    int _selectIndex = 0;
                    int _columnIndex = 0;
                    gd::Time _input;

                    void _moveSelectArrow(int index);
                    void _moveSelectedColumn(int index);
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_SETTINGS_HPP_ */
