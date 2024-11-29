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
             * \brief Clear the event.
             *
             * This function clears the event.
             */
            void clear();


            /**
             * \brief Check if the window should be closed.
             */
            bool close() const;

            /**
             * \brief Get the joystick informations.
             */
            gd::JoyStick joyStick(unsigned int id = 0) const;

            /**
             * \brief Get the keyboard informations.
             */
            gd::KeyBoard keyBoard() const;

            /**
             * \brief Get the mouse informations.
             */
            gd::Mouse mouse() const;

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

            /**
             * \brief Set the key that is released.
             */
            std::vector<std::pair<unsigned int, gd::JoyStick>> _joySticks;

            /**
             * \brief The keyboard informations.
             */
            gd::KeyBoard _keyBoard;

            /**
             * \brief The mouse informations.
             */
            gd::Mouse _mouse;
    };
}

#endif /* !GRADE_DE_EVENT_SFML_HPP_ */