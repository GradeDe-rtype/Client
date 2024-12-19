/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_JOYSTICK_SFML_HPP_
#define GRADE_DE_JOYSTICK_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Window/Joystick.hpp>
#include <tuple>
#include <unordered_map>
#include <vector>
#include "GradeDe/Time.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that contains the joystick informations.
     */
    class JoyStick
    {
        public:
            enum Button {
                /**
                 * \brief Button code for the A button.
                 */
                A = 0,

                /**
                 * \brief Button code for the B button.
                 */
                B,

                /**
                 * \brief Button code for the X button.
                 */
                X,

                /**
                 * \brief Button code for the Y button.
                 */
                Y,

                /**
                 * \brief Button code for the LB button.
                 */
                LB,

                /**
                 * \brief Button code for the RB button.
                 */
                RB,

                /**
                 * \brief Button code for the Select button.
                 */
                Select,

                /**
                 * \brief Button code for the Start button.
                 */
                Menu,

                /**
                 * \brief Button code for the Home button.
                 */
                Home,

                /**
                 * \brief Key code for the total number of buttons.
                 */
                ButtonCount,
            };

            enum Axis {
                /**
                 * \brief Axis code for the Left JoyStick X axis.
                 */
                LeftJoyStickX = 0,

                /**
                 * \brief Axis code for the Left JoyStick X axis.
                 */
                LX = LeftJoyStickX,

                /**
                 * \brief Axis code for the Left JoyStick Y axis.
                 */
                LeftJoyStickY,

                /**
                 * \brief Axis code for the Left JoyStick Y axis.
                 */
                LY = LeftJoyStickY,

                /**
                 * \brief Axis code for the Left Trigger.
                 */
                LeftTrigger,

                /**
                 * \brief Axis code for the Left Trigger.
                 */
                LT = LeftTrigger,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RightTrigger,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RT = RightTrigger,

                /**
                 * \brief Axis code for the Left JoyStick X axis.
                 */
                RightJoyStickX,

                /**
                 * \brief Axis code for the Left JoyStick Y axis.
                 */
                RX = RightJoyStickX,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RightJoyStickY,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RY = RightJoyStickY,

                /**
                 * \brief Axis code for the Cross X axis.
                 */
                CrossX,

                /**
                 * \brief Axis code for the Cross X axis.
                 */
                CX = CrossX,

                /**
                 * \brief Axis code for the Cross Y axis.
                 */
                CrossY,

                /**
                 * \brief Axis code for the Cross Y axis.
                 */
                CY = CrossY,

                /**
                 * \brief Key code for the total number of axis.
                 */
                AxisCount,
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
             * \brief Constructor of the JoyStick class.
             *
             * \param id The id of the joystick.
             *
             * This constructor initializes the joystick with the given id.
             */
            JoyStick(unsigned int id);

            /**
             * \brief Destructor of the JoyStick class.
             */
            ~JoyStick() = default;

            /**
             * \brief Set the connection state of the joystick.
             */
            void setConnected(bool connected);

            /**
             * \brief Set the state of a button.
             */
            void setButtonState(Button button, State pressed);

            /**
             * \brief Set the position of an axis.
             */
            void setAxisMoved(Axis axis, float position);

            /**
             * \brief Check if the joystick is connected.
             */
            bool isConnected() const;

            /**
             * \brief Check if a button is pressed.
             */
            State getButtonState(Button button);

            /**
             * \brief Check if one of the joystick is moved.
             */
            bool isJoyStickMoved() const;

            /**
             * \brief Check if a joystick is moved.
             */
            bool isJoyStickMoved(Axis axis) const;

            /**
             * \brief Get the position of an axis.
             */
            float getAxisPosition(Axis axis) const;

            /**
             * \brief Get the position of X axis.
             *
             * \params highest If true, return the highest X axis position. Else, return the lowest.
             */
            float getXAxisPosition(bool highest) const;

            /**
             * \brief Get the position of Y axis.
             *
             * \params highest If true, return the highest Y axis position. Else, return the lowest.
             */
            float getYAxisPosition(bool highest) const;

        private:
            std::unordered_map<Button, std::tuple<State, gd::Time>> _buttons;
            std::unordered_map<Axis, float> _axis;
            bool _isConnected;
            std::vector<Axis> _axisX;
            std::vector<Axis> _axisY;
    };
} // namespace gd

#endif /* !GRADE_DE_JOYSTICK_SFML_HPP_ */
