/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_CLIENT_HPP_
#define RTYPE_DISPLAY_CLIENT_HPP_

/*  ---- INCLUDES ---- */
#include "GradeDe/Event.hpp"
#include "GradeDe/FrameRate.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Ressources.hpp"
#include "SendList.hpp"

#include <memory>

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        class Client
        {
            public:
                Client(std::shared_ptr<RType::Communication::SendList> sendList);
                ~Client() = default;

                void run();

            private:
                gd::Window _window;
                gd::Event _event;
                gd::Time _time;
                std::shared_ptr<RType::Communication::SendList> _sendList;

                void _handleEvent();
        };
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_CLIENT_HPP_ */
