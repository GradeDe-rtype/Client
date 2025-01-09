/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_ROOMS_LIST_HPP_
#define RTYPE_GAME_SCENE_ROOMS_LIST_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <tuple>
#include <vector>
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/TextBox/TextBox.hpp"
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
            class RoomsList : public AScene
            {
                public:
                    void load(gd::Window &window) override;
                    void reload(gd::Window &window) override;
                    void update(gd::Window &window) override;
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;

                private:
                    std::vector<std::tuple<std::string (RoomsList::*)(), std::string, std::unique_ptr<RType::Game::Components::TextBox>>> _links;
                    int _linkPadding = 25;
                    int _selectIndex = 0;
                    int _selectRow = 1;
                    gd::Time _input;
                    gd::Time _refreshTimer;

                    void _createLinks(std::vector<std::pair<std::string (RoomsList::*)(), std::string>> datas, gd::Window &window);
                    int _getIndexLink(std::string name);
                    void _moveSelectedIndex(int index);

                    std::string _linkBack();
                    std::string _linkRefresh();
                    std::string _linkJoin();
                    std::string _linkCreate();
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_ROOMS_LIST_HPP_ */
