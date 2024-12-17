/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Star.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            Star::Star()
            {
                _size = 100;
                _shape.create({
                    {static_cast<float>(_size / 2), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size)},
                    {static_cast<float>(0), static_cast<float>(_size)},
                });
                _shape.setOrigin({static_cast<float>(_size / 2), static_cast<float>(_size / 4)});
                _shape.setFillColor(gd::Color::Transparent);
                _shape.setOutlineColor(gd::Color::Yellow);
                _shape.setOutlineThickness(5);
                _shape.setPosition({100, 100});
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType