/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_WAITING_ROOM_HPP_
#define RTYPE_GAME_SCENE_WAITING_ROOM_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/TextBox/TextBox.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            class WaitingRoom : public AScene
            {
                public:
                    WaitingRoom() = default;
                    ~WaitingRoom() override = default;

                    void load(gd::Window &window) override;
                    void reload(gd::Window &window) override;
                    void enter(gd::Window &window) override;
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;
                    void update(gd::Window &window) override;

                private:
                    gd::Time _timeout;
                    int _timeoutValue = 6000;
                    bool _error = false;
                    std::unique_ptr<RType::Game::Components::TextBox> _waitMessage;
                    std::unique_ptr<RType::Game::Components::TextBox> _pressEnter;
                    int _linkSpacing = 100;
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_WAITING_ROOM_HPP_ */
