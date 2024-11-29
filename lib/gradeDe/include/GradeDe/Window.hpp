/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_WINDOW_SFML_HPP_
    #define GRADE_DE_WINDOW_SFML_HPP_

    /*  ---- INCLUDES ---- */
    #include <SFML/Graphics.hpp>

    #include "GradeDe/Vector.hpp"
    #include "GradeDe/Color.hpp"


    /*  ---- CLASS ---- */
namespace gd
{
    class Event;

    /**
     * \brief Class that represents the window.
     */
    class Window
    {
        public:
            /**
             * \brief Default constructor.
             */
            Window() = default;

            /**
             * \brief Destructor.
             */
            ~Window();

            /**
             * \brief Create the window in fullscreen.
             */
            void create();

            /**
             * \brief Create the window with parameters.
             *
             * This function creates the window with the specified parameters.
             *
             * \param width The width of the window.
             * \param height The height of the window.
             */
            void create(int width, int height);

            /**
             * \brief Create the window with parameters.
             *
             * This function creates the window with the specified parameters.
             *
             * \param width The width of the window.
             * \param height The height of the window.
             * \param title The title of the window.
             */
            void create(int width, int height, const std::string &title);


            /**
             * \brief Close the window.
             */
            void close();

            /**
             * \brief Check if the window is open.
             */
            bool isOpen() const;


            /**
             * \brief Set the width of the window.
             *
             * This function sets the width of the window.
             *
             * \param width The width of the window.
             */
            void setWidth(int width);

            /**
             * \brief Set the height of the window.
             *
             * This function sets the height of the window.
             *
             * \param height The height of the window.
             */
            void setHeight(int height);

            /**
             * \brief Set the dimensions of the window.
             *
             * This function sets the dimensions of the window.
             *
             * \param width The width of the window.
             * \param height The height of the window.
             */
            void setDimensions(int width, int height);

            /**
             * \brief Set the dimensions of the window.
             *
             * This function sets the dimensions of the window.
             *
             * \param dimensions The dimensions of the window.
             */
            void setDimensions(const gd::Vector2<int> &dimensions);

            /**
             * \brief Set the title of the window.
             *
             * This function sets the title of the window.
             *
             * \param title The title of the window.
             */
            void setTitle(const std::string &title);

            /**
             * \brief Set the fullscreen mode.
             *
             * This function sets the fullscreen mode.
             *
             * \param fullscreen The fullscreen mode.
             */
            void setFullscreen(bool fullscreen);

            /**
             * \brief Check if the window is in fullscreen.
             */
            bool isFullscreen() const;


            /**
             * \brief Poll the event.
             *
             * This function polls the event.
             *
             * \param event The event.
             */
            void pollEvent(gd::Event &event);


            /**
             * \brief Clear the window.
             *
             * This function clears the window.
             *
             * \param color The color of the window.
             */
            void clear(gd::Color color = gd::Color::Black);


            /**
             * \brief Draw the shape.
             *
             * This function draws the shape.
             *
             * \param shape The shape.
             */
            void display();


            /**
             * \brief Get the width of the window.
             */
            int getWidth() const;

            /**
             * \brief Get the height of the window.
             */
            int getHeight() const;

            /**
             * \brief Get the dimensions of the window.
             */
            gd::Vector2<int> getDimensions() const;

            /**
             * \brief Get the title of the window.
             */
            std::string getTitle() const;

            /**
             * \brief Get the window.
             */
            void *getWindow();

        private:
            /**
             * \brief The window.
             */
            sf::RenderWindow _window;

            /**
             * \brief The video mode.
             */
            sf::VideoMode _videoMode;

            /**
             * \brief The fullscreen video mode.
             */
            sf::VideoMode _fullScreenVideoMode;

            /**
             * \brief The title of the window.
             */
            std::string _title;

            /**
             * \brief Is the window open
             */
            bool _isOpen = false;

            /**
             * \brief Is the window in fullscreen
             */
            bool _fullscreen = false;


            /**
             * \brief create the window
             */
            void _create(sf::VideoMode &videoMode, const std::string &title, sf::Uint32 style);
    };
}

#endif /* !GRADE_DE_WINDOW_SFML_HPP_ */
