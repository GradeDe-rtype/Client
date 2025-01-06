/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Range.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            Range::Range(int start, int end, int step, gd::Vector2<float> position, gd::Vector2<float> size)
            {
                _position = position;
                _size = size;
                _start = start;
                _end = end;
                _step = step;
                _value = start;

                _background.create({size.x, size.y});
                _background.setPosition(position);
                _background.setFillColor(gd::Color(0, 0, 0, 150));
                _background.setOutlineColor(gd::Color::White);
                _background.setOutlineThickness(2);

                _range.create({0, size.y - 4});
                _range.setPosition({position.x + 2, position.y + 2});
                _range.setFillColor(gd::Color::White);
            }

            void Range::reload(gd::Vector2<float> window)
            {
                _size.x = window.x;
                _background.setSize({window.x, _size.y});
                _background.setPosition(_position);
                _range.setSize({0, _size.y - 4});
                _range.setPosition({window.x + 2, _position.y + 2});
                setValue(_value);
            }

            void Range::draw(gd::Window &window)
            {
                window.draw(_background);
                window.draw(_range);
            }

            void Range::setColor(gd::Color color)
            {
                _range.setFillColor(color);
                _background.setOutlineColor(color);
            }

            void Range::upValue()
            {
                if (_value + _step <= _end) _value += _step;
                setValue(_value);
            }

            void Range::downValue()
            {
                if (_value - _step >= _start) _value -= _step;
                setValue(_value);
            }

            void Range::setValue(float value)
            {
                if (value < _start)
                    _value = _start;
                else if (value > _end)
                    _value = _end;
                else
                    _value = value;

                _range.setSizeX((_size.x - 4) * (_value - _start) / (_end - _start));
            }

            float Range::getValue() const
            {
                return _value;
            }

            void Range::setPosition(gd::Vector2<float> position)
            {
                _position = position;
                _background.setPosition(position);
                _range.setPosition({position.x + 2, position.y + 2});
            }

            gd::Vector2<float> Range::getSize() const
            {
                return _background.getSize();
            }

            void Range::setEnd(int end)
            {
                _end = end;
                setValue(_value);
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
