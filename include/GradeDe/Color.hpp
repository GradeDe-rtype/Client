/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_COLOR_SFML_HPP_
    #define GRADE_DE_COLOR_SFML_HPP_

    /*  ---- INCLUDES ---- */
    #include "GradeDe/Includes.hpp"

    /*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents a color.
     */
    class Color
    {
        public:
            /**
             * \brief Default constructor.
             *
             * \note This constructor creates a color with the default values (0, 0, 0, 255).
             */
            Color();

            /**
             * \brief Constructor with parameters.
             *
             * This constructor creates a color with the specified values.
             *
             * \param r The red component of the color.
             * \param g The green component of the color.
             * \param b The blue component of the color.
             * \param a The alpha component of the color.
             */
            Color(int r, int g, int b, int a = 255);

            /**
             * \brief Default destructor.
             */
            ~Color() = default;

            /**
             * \brief Get the red component of the color.
             */
            int r;

            /**
             * \brief Get the green component of the color.
             */
            int g;

            /**
             * \brief Get the blue component of the color.
             */
            int b;

            /**
             * \brief Get the alpha component of the color.
             */
            int a;

            /**
             * \brief Predefined color: Black.
             */
            static const gd::Color Black;

            /**
             * \brief Predefined color: White.
             */
            static const gd::Color White;

            /**
             * \brief Predefined color: Red.
             */
            static const gd::Color Red;

            /**
             * \brief Predefined color: Green.
             */
            static const gd::Color Green;

            /**
             * \brief Predefined color: Blue.
             */
            static const gd::Color Blue;

            /**
             * \brief Predefined color: Yellow.
             */
            static const gd::Color Yellow;

            /**
             * \brief Predefined color: Magenta.
             */
            static const gd::Color Magenta;

            /**
             * \brief Predefined color: Cyan.
             */
            static const gd::Color Cyan;

            /**
             * \brief Predefined color: Transparent.
             */
            static const gd::Color Transparent;
    };
}

#endif /* !GRADE_DE_COLOR_SFML_HPP_ */
