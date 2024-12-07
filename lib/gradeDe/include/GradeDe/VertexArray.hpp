/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_VERTEX_ARRAY_SFML_HPP_
#define GRADE_DE_VERTEX_ARRAY_SFML_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "GradeDe/Color.hpp"
#include "GradeDe/PrimitiveType.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Vertex.hpp"

namespace gd
{
    class VertexArray
    {
        public:
            VertexArray();
            VertexArray(gd::PrimitiveType primitiveType);
            VertexArray(gd::PrimitiveType primitiveType, std::size_t vertexCount);
            ~VertexArray() = default;

            void append(gd::Vertex &vertex);
            void clear();
            void setPrimitiveType(gd::PrimitiveType primitiveType);
            gd::PrimitiveType getPrimitiveType() const;
            void *getVertexArray();

            gd::Vertex &operator[](std::size_t index);

        private:
            void _sync();
            std::vector<gd::Vertex> _vertices;
            gd::PrimitiveType _primitiveType;
            sf::VertexArray _sfVertexArray;
    };
} // namespace gd

#endif /* !GRADE_DE_VERTEX_ARRAY_SFML_HPP_ */
