/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "MenuScene.hpp"
#include <iostream>

namespace RType
{
    namespace Display
    {
        namespace Scene
        {
            void Menu::load(gd::Window &window)
            {
                _background.createRectangle(window.getWidth(), window.getHeight());
                _background.setFillColor(gd::Color::White);
            }

            void Menu::unload()
            {
            }

            std::string Menu::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Space)) return "game";
                return "";
            }

            void Menu::draw(gd::Window &window)
            {
                _background.draw(window);
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
