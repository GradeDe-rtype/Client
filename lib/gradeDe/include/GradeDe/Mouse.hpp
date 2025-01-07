/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_MOUSE_SFML_HPP_
#define GRADE_DE_MOUSE_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <tuple>
#include <unordered_map>
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    class Mouse
    {
        public:
            /**
             * \brief Enum that represents the keys on a mouse.
             *
             * This enum defines various key codes for each key on a standard mouse.
             * It is used for handling mouse input and key events.
             */
            enum Button {
                /**
                 * \brief Key code for the left mouse button.
                 */
                Left = 0,

                /**
                 * \brief Key code for the right mouse button.
                 */
                Right,

                /**
                 * \brief Key code for the middle mouse button.
                 */
                Middle,

                /**
                 * \brief Key code for the extra mouse button 1.
                 */
                XButton1,

                /**
                 * \brief Key code for the extra mouse button 2.
                 */
                XButton2,

                /**
                 * \brief Key code for the total number of mouse buttons.
                 */
                ButtonCount
            };

            enum State {
                /**
                 * \brief Button is pressed.
                 */
                Pressed,

                /**
                 * \brief Button is released.
                 */
                Released,

                /**
                 * \brief Button is not pressed.
                 */
                None,
            };

            /**
             * \brief Constructor of the Mouse class.
             */
            Mouse();

            /**
             * \brief Destructor of the Mouse class.
             */
            ~Mouse() = default;

            /**
             * \brief Set key state.
             *
             * \param key The key to set the state of.
             * \param state The state to set the key to.
             */
            void setButtonState(Button button, State state);

            /**
             * \brief Get the state of a key.
             *
             * \param key The key to get the state of.
             *
             * \return The state of the key.
             */
            State getButtonState(Button button);

            /**
             * \brief Get the position of the mouse.
             *
             * \param window The window to get the mouse position relative to.
             *
             * \return The position of the mouse relative to the window.
             */
            gd::Vector2<float> getPosition(gd::Window &window);

            bool hasMove(gd::Window &window);

        private:
            std::unordered_map<Button, std::tuple<State, gd::Time>> _buttons;
            gd::Vector2<float> _position = {0, 0};
    };
} // namespace gd

#endif /* !GRADE_DE_MOUSE_SFML_HPP_ */
