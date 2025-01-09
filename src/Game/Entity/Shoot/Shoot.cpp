/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Shoot.hpp"

namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            Shoot::Shoot(float x, float y, std::string from)
            {
                _position = {x, y};

                _size = 20;
                _shape.create({
                    {static_cast<float>(0), static_cast<float>(0)},
                    {static_cast<float>(_size), static_cast<float>(_size / 4)},
                    {static_cast<float>(0), static_cast<float>(_size / 2)},
                    {static_cast<float>(_size - _size / 10), static_cast<float>(_size / 4)},
                });
                _shape.setOrigin({static_cast<float>(_size / 2), static_cast<float>(_size / 4)});
                _shape.setFillColor(gd::Color::Cyan);
                _shape.setPosition(_position);
                _shape.setRotation(0);
                RType::Game::Managers::Sound::get().play("blaster");

                if (from == "enemy") {
                    _shape.setRotation(180);
                    _shape.setFillColor(gd::Color::Yellow);
                }
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType