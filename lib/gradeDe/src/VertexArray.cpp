/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GradeDe/VertexArray.hpp"

namespace gd
{
    VertexArray::VertexArray()
    {
        VertexArray(gd::PrimitiveType::Points, 0);
    }

    VertexArray::VertexArray(gd::PrimitiveType primitiveType)
    {
        VertexArray(primitiveType, 0);
    }

    VertexArray::VertexArray(gd::PrimitiveType primitiveType, std::size_t vertexCount)
        : _primitiveType(primitiveType), _sfVertexArray(static_cast<sf::PrimitiveType>(primitiveType), vertexCount)
    {
        for (std::size_t i = 0; i < vertexCount; i++)
            _vertices.push_back(gd::Vertex());
    }

    void VertexArray::append(gd::Vertex &vertex)
    {
        _vertices.push_back(vertex);
        _sfVertexArray.append(*static_cast<sf::Vertex *>(vertex.getVertex()));
    }

    void VertexArray::clear()
    {
        _vertices.clear();
        _sfVertexArray.clear();
    }

    void VertexArray::setPrimitiveType(gd::PrimitiveType primitiveType)
    {
        _primitiveType = primitiveType;
        _sfVertexArray.setPrimitiveType(static_cast<sf::PrimitiveType>(primitiveType));
    }

    gd::PrimitiveType VertexArray::getPrimitiveType() const
    {
        return _primitiveType;
    }

    gd::Vertex &VertexArray::operator[](std::size_t index)
    {
        return _vertices[index];
    }

    void *VertexArray::getVertexArray()
    {
        _sync();
        return &_sfVertexArray;
    }

    void VertexArray::_sync()
    {
        for (std::size_t i = 0; i < _vertices.size(); i++)
            _sfVertexArray[i] = *static_cast<sf::Vertex *>(_vertices[i].getVertex());
    }
} // namespace gd
