/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_SHAPE_SFML_HPP_
#define GRADE_DE_SHAPE_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Graphics.hpp>
#include <vector>

#include "GradeDe/Color.hpp"
#include "GradeDe/Texture.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents a shape.
     */
    class Shape
    {
        public:
            /**
             * \brief Default constructor.
             */
            Shape() = default;

            /**
             * \brief Default destructor.
             */
            ~Shape() = default;

            /**
             * \brief Create the shape.
             *
             * \param points The points of the shape.
             */
            void create(std::vector<gd::Vector2<float>> points);

            /**
             * \brief Create a rectangle.
             *
             * \param size The size of the rectangle.
             */
            void createRectangle(float width, float height);

            /**
             * \brief Set the fill color of the shape.
             *
             * This function sets the fill color of the shape.
             *
             * \param color The fill color of the shape.
             */
            void setFillColor(gd::Color color);

            /**
             * \brief Set the outline color of the shape.
             *
             * This function sets the outline color of the shape.
             *
             * \param color The outline color of the shape.
             */
            void setOutlineColor(gd::Color color);

            /**
             * \brief Set the outline thickness of the shape.
             *
             * This function sets the outline thickness of the shape.
             *
             * \param thickness The outline thickness of the shape.
             */
            void setOutlineThickness(float thickness);

            /**
             * \brief Set the position of the shape.
             *
             * This function sets the position of the shape.
             *
             * \param position The position of the shape.
             */
            void setPosition(gd::Vector2<float> position);

            /**
             * \brief Set the size of the shape.
             *
             * This function sets the size of the shape.
             *
             * \param size The size of the shape.
             */
            void setTexture(gd::Texture &texture);

            /**
             * \brief Set the origin of the shape.
             *
             * This function sets the origin of the shape.
             *
             * \param origin The origin of the shape.
             */
            void setOrigin(gd::Vector2<float> origin);

            /**
             * \brief Set the rotation of the shape.
             *
             * This function sets the rotation of the shape.
             *
             * \param angle The rotation of the shape.
             */
            void setRotation(float angle);

            /**
             * \brief Move the shape.
             *
             * This function moves the shape.
             *
             * \param offset The offset of the shape.
             */
            void move(gd::Vector2<float> offset);

            /**
             * \brief Set the rotation of the shape.
             *
             * This function sets the rotation of the shape.
             *
             * \param angle The rotation of the shape.
             */
            void rotate(float angle);

            /**
             * \brief Get the fill color of the shape.
             */
            gd::Color getFillColor() const;

            /**
             * \brief Get the outline color of the shape.
             */
            gd::Color getOutlineColor() const;

            /**
             * \brief Get the outline thickness of the shape.
             */
            float getOutlineThickness() const;

            /**
             * \brief Get the position of the shape.
             */
            gd::Vector2<float> getPosition() const;

            /**
             * \brief Get the rotation angle of the shape.
             */
            float getRotation() const;

            /**
             * \brief Get the size of the shape.
             */
            gd::Vector2<float> getSize() const;

            /**
             * \brief Draw the shape.
             *
             * This function draws the shape.
             *
             * \param window The window.
             */
            void draw(gd::Window &window);

        private:
            /**
             * \brief The points of the shape.
             */
            std::vector<gd::Vector2<float>> _points;

            /**
             * \brief The fill color of the shape.
             */
            gd::Color _fillColor = gd::Color::White;

            /**
             * \brief The outline color of the shape.
             */
            gd::Color _outlineColor = gd::Color::Transparent;

            /**
             * \brief The outline thickness of the shape.
             */
            float _outlineThickness = 0;

            /**
             * \brief The position of the shape.
             */
            gd::Vector2<float> _position = {0, 0};

            /**
             * \brief The origin of the shape.
             */
            gd::Vector2<float> _origin = {0, 0};

            /**
             * \brief The rotation of the shape.
             */
            float _rotation = 0;

            /**
             * \brief The size of the shape.
             */
            sf::ConvexShape _shape;
    };
} // namespace gd

#endif /* !GRADE_DE_SHAPE_SFML_HPP_ */
