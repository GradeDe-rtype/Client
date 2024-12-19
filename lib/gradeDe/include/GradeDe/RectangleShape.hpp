/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_RECTANGLE_SHAPE_RECTANGLE_SFML_HPP_
#define GRADE_DE_RECTANGLE_SHAPE_RECTANGLE_SFML_HPP_

/*  ---- INCLUDES ---- */
#include <SFML/Graphics.hpp>
#include <vector>
#include "GradeDe/Color.hpp"
#include "GradeDe/Texture.hpp"
#include "GradeDe/Vector.hpp"

/*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents a rectangleshape.
     */
    class RectangleShape
    {
        public:
            /**
             * \brief Default constructor.
             */
            RectangleShape() = default;

            /**
             * \brief Default destructor.
             */
            ~RectangleShape() = default;

            /**
             * \brief Create the rectangleshape.
             *
             * \param points The points of the rectangleshape.
             */
            void create(gd::Vector2<float> size);

            /**
             * \brief Set the fill color of the rectangleshape.
             *
             * This function sets the fill color of the rectangleshape.
             *
             * \param color The fill color of the rectangleshape.
             */
            void setFillColor(gd::Color color);

            /**
             * \brief Set the outline color of the rectangleshape.
             *
             * This function sets the outline color of the rectangleshape.
             *
             * \param color The outline color of the rectangleshape.
             */
            void setOutlineColor(gd::Color color);

            /**
             * \brief Set the outline thickness of the rectangleshape.
             *
             * This function sets the outline thickness of the rectangleshape.
             *
             * \param thickness The outline thickness of the rectangleshape.
             */
            void setOutlineThickness(float thickness);

            /**
             * \brief Set the position of the rectangleshape.
             *
             * This function sets the position of the rectangleshape.
             *
             * \param position The position of the rectangleshape.
             */
            void setPosition(gd::Vector2<float> position);

            /**
             * \brief Set the size of the rectangleshape.
             *
             * This function sets the size of the rectangleshape.
             *
             * \param size The size of the rectangleshape.
             */
            void setTexture(gd::Texture &texture);

            /**
             * \brief Set the origin of the rectangleshape.
             *
             * This function sets the origin of the rectangleshape.
             *
             * \param origin The origin of the rectangleshape.
             */
            void setOrigin(gd::Vector2<float> origin);

            /**
             * \brief Set the rotation of the rectangleshape.
             *
             * This function sets the rotation of the rectangleshape.
             *
             * \param angle The rotation of the rectangleshape.
             */
            void setRotation(float angle);

            /**
             * \brief Set the size of the rectangleshape.
             *
             * This function sets the size of the rectangleshape.
             *
             * \param size The size of the rectangleshape.
             */
            void setSize(gd::Vector2<float> size);

            void setSizeX(float x);
            void setSizeY(float y);

            /**
             * \brief Move the rectangleshape.
             *
             * This function moves the rectangleshape.
             *
             * \param offset The offset of the rectangleshape.
             */
            void move(gd::Vector2<float> offset);

            /**
             * \brief Set the rotation of the rectangleshape.
             *
             * This function sets the rotation of the rectangleshape.
             *
             * \param angle The rotation of the rectangleshape.
             */
            void rotate(float angle);

            /**
             * \brief Get the fill color of the rectangleshape.
             */
            gd::Color getFillColor() const;

            /**
             * \brief Get the outline color of the rectangleshape.
             */
            gd::Color getOutlineColor() const;

            /**
             * \brief Get the outline thickness of the rectangleshape.
             */
            float getOutlineThickness() const;

            /**
             * \brief Get the position of the rectangleshape.
             */
            gd::Vector2<float> getPosition() const;

            /**
             * \brief Get the rotation angle of the rectangleshape.
             */
            float getRotation() const;

            /**
             * \brief Get the size of the rectangleshape.
             */
            gd::Vector2<float> getSize() const;

            /**
             * \brief Get the rectangleshape.
             */
            void *getShape();

        private:
            gd::Vector2<float> _size = {0, 0};

            /**
             * \brief The fill color of the rectangleshape.
             */
            gd::Color _fillColor = gd::Color::White;

            /**
             * \brief The outline color of the rectangleshape.
             */
            gd::Color _outlineColor = gd::Color::Transparent;

            /**
             * \brief The outline thickness of the rectangleshape.
             */
            float _outlineThickness = 0;

            /**
             * \brief The position of the rectangleshape.
             */
            gd::Vector2<float> _position = {0, 0};

            /**
             * \brief The origin of the rectangleshape.
             */
            gd::Vector2<float> _origin = {0, 0};

            /**
             * \brief The rotation of the rectangleshape.
             */
            float _rotation = 0;

            /**
             * \brief The size of the rectangleshape.
             */
            sf::RectangleShape _shape;
    };
} // namespace gd

#endif /* !GRADE_DE_RECTANGLE_SHAPE_RECTANGLE_SFML_HPP_ */
