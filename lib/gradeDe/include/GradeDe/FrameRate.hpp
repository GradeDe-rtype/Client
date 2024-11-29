/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_FRAMERATE_SFML_HPP_
    #define GRADE_DE_FRAMERATE_SFML_HPP_

    /*  ---- INCLUDES ---- */

    /*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents the frame rate.
     */
    class FrameRate
    {
        public:
            /**
             * \brief Default constructor.
             */
            ~FrameRate() = default;


            /**
             * \brief Get the instance of the frame rate.
             */
            static FrameRate &get();

            /**
             * \brief Get the frame rate.
             */
            int fps() const;


            /**
             * \brief Set the frame rate.
             *
             * This function sets the frame rate.
             *
             * \param frameRate The frame rate.
             */
            void setFrameRate(int frameRate);

            /**
             * \brief Get the frame rate.
             */
            int getFrameRate() const;

        private:
            /**
             * \brief Default constructor.
             */
            FrameRate() = default;

            /**
             * \brief The frame rate.
             *
             * \note The default value is 24.
             */
            int _frameRate = 24;

            /**
             * \brief The instance of the frame rate.
             */
            static FrameRate &_instance;
    };
}

#endif /* !GRADE_DE_FRAMERATE_SFML_HPP_ */
