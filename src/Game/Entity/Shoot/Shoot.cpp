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
            Shoot::Shoot(float x, float y, int speed)
            {
                _position = {x, y};
                _speed = speed;

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
                _blaster.load("assets/sounds/blaster.mp3");
                _blaster.setVolume(50);
                _blaster.play();
                _moveClock.reset();

                if (_speed < 0) {
                    _shape.setRotation(180);
                    _shape.setFillColor(gd::Color::Yellow);
                }
            }

            void Shoot::update()
            {
                if (_moveClock.getElapsedTime() > 1000 / 60) {
                    _moveClock.reset();
                    move(_speed, 0);
                }
            }
        } // namespace Entity
    } // namespace Game
} // namespace RType