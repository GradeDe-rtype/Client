/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_JOIN_ROOM_HPP_
#define RTYPE_GAME_SCENE_JOIN_ROOM_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/TextBox/TextBox.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Ressources/Ressources.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            class JoinRoom : public AScene
            {
                public:
                    JoinRoom() = default;
                    ~JoinRoom() override = default;

                    void load(gd::Window &window) override;
                    void reload(gd::Window &window) override;
                    void enter(gd::Window &window) override;
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;

                private:
                    std::unique_ptr<RType::Game::Components::TextBox> _codePreview;
                    std::string _code;
                    int _codeSize = 6;
                    int _linkSpacing = 100;
                    int _codeIndex = 0;
                    gd::Time _input;

                    void _updateCode(gd::Window &window, char c);
                    void _deleteCode(gd::Window &window);
                    std::string _validateCode(gd::Window &window);
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_JOIN_ROOM_HPP_ */
