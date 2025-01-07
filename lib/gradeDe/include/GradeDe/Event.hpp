/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_EVENT_SFML_HPP_
#define GRADE_DE_EVENT_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Window/Event.hpp>
#include <vector>
#include "GradeDe/JoyStick.hpp"
#include "GradeDe/KeyBoard.hpp"
#include "GradeDe/Mouse.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents an event.
     */
    class Event
    {
        public:
            /**
             * \brief Default constructor.
             */
            Event();

            /**
             * \brief Default destructor.
             */
            ~Event() = default;

            /**
             * \brief Handle an event.
             *
             * This function handles the specified event.
             *
             * \param event The event to handle.
             */
            void handleEvent(void *event);

            /**
             * \brief Check if the window should be closed.
             */
            bool close() const;

            gd::JoyStick joyStick = gd::JoyStick(0);
            gd::KeyBoard keyBoard;
            gd::Mouse mouse;

        private:
            /**
             * \brief The event.
             */
            sf::Event _event;

            /**
             * \brief Boolean that indicates if the window should be closed.
             *
             * \note The default value is false.
             */
            bool _close = false;
    };
} // namespace gd

#endif /* !GRADE_DE_EVENT_SFML_HPP_ */
