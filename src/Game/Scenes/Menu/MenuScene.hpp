/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_MENU_HPP_
#define RTYPE_GAME_SCENE_MENU_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include "GradeDe/Event.hpp"
#include "GradeDe/Music.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Entity/SelectArrow/SelectArrow.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Ressources/Ressources.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            class Menu : public AScene
            {
                public:
                    /**
                     * @brief Load the scene
                     *
                     * @param `window` The window
                     */
                    void load(gd::Window &window) override;

                    void reload(gd::Window &window) override;

                    /**
                     * @brief Update the scene
                     *
                     * @param `window` The window
                     * @param `event` The event
                     */
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;

                    /**
                     * @brief Draw the scene
                     *
                     * @param `window` The window
                     */
                    void draw(gd::Window &window) override;

                    /**
                     * @brief Update the scene
                     */
                    void update(gd::Window &window) override;

                private:
                    std::vector<std::tuple<std::string, std::string, std::unique_ptr<RType::Game::Components::Text>>> _links;
                    std::unique_ptr<RType::Game::Entity::SelectArrow> _selectArrow;
                    bool _connected = false;
                    int _linkGap = 75;
                    int _linkSpacing = 50;
                    int _selectIndex = 1;
                    gd::Time _input;

                    void _addLink(std::string name, std::string link, gd::Window &window);
                    void _setPositionsLinks();
                    int _getIndexLink(std::string name);
                    void _moveSelectArrow(int index);
                    void _setSelectArrowPosition();
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_MENU_HPP_ */
