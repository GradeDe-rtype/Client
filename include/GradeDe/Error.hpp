/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_ERROR_SFML_HPP_
    #define GRADE_DE_ERROR_SFML_HPP_

    /*  ---- INCLUDES ---- */
    #include "GradeDe/Includes.hpp"

    /*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents an error.
     */
    class Error: public std::exception
    {
        public:
            /**
             * \brief Constructor with parameters.
             *
             * This constructor creates an error with the specified values.
             *
             * \param what The message of the error.
             * \param where The location of the error.
             */
            Error(const std::string &what, const std::string &where = "");
            ~Error() = default;

            /**
             * \brief Get the message of the error.
             */
            const char *what() const noexcept override;

            /**
             * \brief Get the location of the error.
             */
            const std::string &where() const noexcept;

            /**
             * \brief Read the error.
             *
             * This function reads the error.
             *
             * \param error The error to read.
             */
            static void read(const Error &error);

        private:
            /**
             * \brief The message of the error.
             */
            std::string _what;

            /**
             * \brief The location of the error.
             */
            std::string _where;
    };
}

#endif /* !GRADE_DE_FRAMERATE_SFML_HPP_ */
