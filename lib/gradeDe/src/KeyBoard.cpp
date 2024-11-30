/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/KeyBoard.hpp"

namespace gd
{
    KeyBoard::KeyBoard()
    {
        for (Key key = Key::Unknown; key < Key::KeyCount; key = static_cast<Key>(key + 1))
            _keys[key] = false;
    }

    void KeyBoard::setKeyState(Key key, bool state)
    {
        _keys[key] = state;
    }

    bool KeyBoard::getKeyState(Key key) const
    {
        return _keys.at(key);
    }
} // namespace gd
