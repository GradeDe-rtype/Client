/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_TIME_SFML_HPP_
#define GRADE_DE_TIME_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/System.hpp>

/*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents the time.
     */
    class Time
    {
        public:
            /**
             * \brief Default constructor.
             */
            Time();

            /**
             * \brief Default destructor.
             */
            ~Time() = default;

            /**
             * \brief Reset the timer.
             */
            void reset();

            /**
             * \brief Get the elapsed time.
             */
            int getElapsedTime();

        private:
            /**
             * \brief The clock.
             */
            sf::Clock _clock;

            /**
             * \brief The time.
             */
            sf::Time _time;
    };
} // namespace gd

#endif /* !GRADE_DE_TIME_SFML_HPP_ */
