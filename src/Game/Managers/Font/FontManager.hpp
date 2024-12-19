/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_FONT_HPP_
#define RTYPE_GAME_MANAGERS_FONT_HPP_

/*  ---- INCLUDES ---- */
#include <filesystem>
#include <string>
#include <unordered_map>
#include <vector>
#include "GradeDe/Font.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Font
            {
                public:
                    ~Font() = default;

                    static Font &get();

                    gd::Font load(const std::string &name);

                private:
                    Font() = default;
                    std::unordered_map<std::string, gd::Font> _fonts;

                    void _loadNewFont(const std::string &name);
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_FONT_HPP_ */
