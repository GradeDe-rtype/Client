/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "GradeDe/Color.hpp"

namespace gd
{
    gd::Color::Color(int r, int g, int b, int a)
        : r(r), g(g), b(b), a(a)
    {
    }

    const gd::Color gd::Color::Black = gd::Color(0, 0, 0);
    const gd::Color gd::Color::White = gd::Color(255, 255, 255);
    const gd::Color gd::Color::Red = gd::Color(255, 0, 0);
    const gd::Color gd::Color::Green = gd::Color(0, 255, 0);
    const gd::Color gd::Color::Blue = gd::Color(0, 0, 255);
    const gd::Color gd::Color::Yellow = gd::Color(255, 255, 0);
    const gd::Color gd::Color::Magenta = gd::Color(255, 0, 255);
    const gd::Color gd::Color::Cyan = gd::Color(0, 255, 255);
    const gd::Color gd::Color::Transparent = gd::Color(0, 0, 0, 0);

    const gd::Color gd::Color::fromHex(std::string hex)
    {
        if (hex.size() != 7 && hex.size() != 9 && hex[0] != '#')
            return gd::Color::Black;
        int r = std::stoi(hex.substr(1, 2), 0, 16);
        int g = std::stoi(hex.substr(3, 2), 0, 16);
        int b = std::stoi(hex.substr(5, 2), 0, 16);
        int a = 255;

        if (hex.size() == 9)
            a = std::stoi(hex.substr(7, 2), 0, 16);

        return gd::Color(r, g, b, a);
    }

    const std::string gd::Color::toHex(const gd::Color &color)
    {
        std::stringstream ss;
        ss << "#"
           << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(color.r)
           << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(color.g)
           << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(color.b);
        return ss.str();
    }

    bool gd::Color::operator!=(const gd::Color &color) const
    {
        return r != color.r || g != color.g || b != color.b || a != color.a;
    }

    bool gd::Color::operator==(const gd::Color &color) const
    {
        return r == color.r && g == color.g && b == color.b && a == color.a;
    }
} // namespace gd
