/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/KeyBoard.hpp"
#include <iostream>

namespace gd
{
    KeyBoard::KeyBoard()
    {
        for (Key key = Key::Unknown; key < Key::KeyCount; key = static_cast<Key>(key + 1))
            _keys[key] = std::make_tuple(State::None, gd::Time());
    }

    void KeyBoard::setKeyState(Key key, KeyBoard::State state)
    {
        if (_keys.find(key) == _keys.end()) return;
        std::get<0>(_keys.at(key)) = state;
        std::get<1>(_keys.at(key)).reset();
    }

    KeyBoard::State KeyBoard::getKeyState(Key key)
    {
        if (_keys.find(key) == _keys.end()) return State::None;
        if (std::get<0>(_keys.at(key)) == State::Released) {
            if (std::get<1>(_keys.at(key)).getElapsedTime() >= 100)
                setKeyState(key, State::None);
            return std::get<0>(_keys.at(key));
        }
        return std::get<0>(_keys.at(key));
    }
} // namespace gd
