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
#include <unordered_map>

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
                B = 1,

                /**
                 * \brief Button code for the X button.
                 */
                X = 2,

                /**
                 * \brief Button code for the Y button.
                 */
                Y = 3,

                /**
                 * \brief Button code for the LB button.
                 */
                LB = 4,

                /**
                 * \brief Button code for the RB button.
                 */
                RB = 5,

                /**
                 * \brief Button code for the Select button.
                 */
                Select = 6,

                /**
                 * \brief Button code for the Start button.
                 */
                Menu = 7,

                /**
                 * \brief Button code for the Home button.
                 */
                Home = 8,
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
                LeftJoyStickY = 1,

                /**
                 * \brief Axis code for the Left JoyStick Y axis.
                 */
                LY = LeftJoyStickY,

                /**
                 * \brief Axis code for the Left Trigger.
                 */
                LeftTrigger = 2,

                /**
                 * \brief Axis code for the Left Trigger.
                 */
                LT = LeftTrigger,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RightTrigger = 3,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RT = RightTrigger,

                /**
                 * \brief Axis code for the Left JoyStick X axis.
                 */
                RightJoyStickX = 4,

                /**
                 * \brief Axis code for the Left JoyStick Y axis.
                 */
                RX = RightJoyStickX,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RightJoyStickY = 5,

                /**
                 * \brief Axis code for the Right Trigger.
                 */
                RY = RightJoyStickY,

                /**
                 * \brief Axis code for the Cross X axis.
                 */
                CrossX = 6,

                /**
                 * \brief Axis code for the Cross X axis.
                 */
                CX = CrossX,

                /**
                 * \brief Axis code for the Cross Y axis.
                 */
                CrossY = 7,

                /**
                 * \brief Axis code for the Cross Y axis.
                 */
                CY = CrossY,
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
            void setButtonPressed(Button button, bool pressed);

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
            bool isButtonPressed(Button button) const;

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

        private:
            std::unordered_map<Button, bool> _buttons;
            std::unordered_map<Axis, float> _axis;
            bool _isConnected;
    };
} // namespace gd

#endif /* !GRADE_DE_JOYSTICK_SFML_HPP_ */
