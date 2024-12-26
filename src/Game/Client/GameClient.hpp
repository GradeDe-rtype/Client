/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_CLIENT_HPP_
#define RTYPE_GAME_CLIENT_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include "GradeDe/Event.hpp"
#include "GradeDe/FrameRate.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Communication/SendList/SendList.hpp"
#include "Game/Components/StarsBackground/StarsBackground.hpp"
#include "Game/Managers/Scenes/Scenes.hpp"
#include "Game/Managers/Sound/Sound.hpp"
#include "Ressources/Ressources.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        class Client
        {
            public:
                Client();
                ~Client() = default;

                void run();

            private:
                gd::Window _window;
                gd::Event _event;
                gd::Time _time;
                std::unique_ptr<RType::Game::Components::StarsBackground> _starBackground;

                void _handleEvent();
                void _draw();
                void _handleGeneralEvent();
        };
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_CLIENT_HPP_ */
