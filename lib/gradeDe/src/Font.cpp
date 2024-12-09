/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Font.hpp"

namespace gd
{
    void Font::load(const std::string &path)
    {
        if (!_font.loadFromFile(path))
            throw Error("Failed to load font", path);
    }
} // namespace gd
