/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_CLIENT_HPP_
#define RTYPE_DISPLAY_CLIENT_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include "GradeDe/Event.hpp"
#include "GradeDe/FrameRate.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Ressources.hpp"
#include "SceneManager.hpp"
#include "SendList.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
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
                std::unique_ptr<RType::Display::Scene::SceneManager> _sceneManager;

                void _handleEvent();
                void _draw();
                void _handleGeneralEvent();
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_CLIENT_HPP_ */
