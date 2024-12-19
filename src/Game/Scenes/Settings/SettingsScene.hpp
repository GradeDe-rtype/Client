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
#include "GradeDe/Music.hpp"
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Entity/SelectArrow/SelectArrow.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Game/Scenes/Base/MiniScene/AMiniScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Graphics/GraphicsMiniScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Sounds/SoundsMiniScene.hpp"
#include "Ressources/Ressources.hpp"

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
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;

                private:
                    std::vector<std::tuple<std::string, std::unique_ptr<RType::Game::Components::Text>, std::unique_ptr<RType::Game::Scenes::MiniScene::AMiniScene>>> _links;
                    std::unique_ptr<RType::Game::Entity::SelectArrow> _selectArrow;
                    std::vector<gd::Shape> _rectangles;
                    int _linkGap = 75;
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
