/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "FontManager.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Font &Font::get()
            {
                static Font instance;
                return instance;
            }

            gd::Font Font::getFont(const std::string &name)
            {
                if (_fonts.find(name) == _fonts.end())
                    _loadNewFont(name);
                return _fonts[name];
            }

            void Font::_loadNewFont(const std::string &name)
            {
                std::string path = "assets/font/" + name;
                std::vector<std::string> paths = {
                    path + ".ttf",
                    path + ".otf"};

                for (const std::string &p : paths) {
                    if (std::filesystem::exists(p)) {
                        _fonts[name].load(p);
                        return;
                    }
                }
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType