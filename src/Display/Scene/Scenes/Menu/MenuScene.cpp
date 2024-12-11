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
                _font.load("assets/font/Karma Future.otf");
                _text.setFont(_font);
                _text.setCharacterSize(30);
                _text.setString("Press 'Space' to start the game");
                _text.setPosition((gd::Vector2<int>){(int)(window.getWidth() / 2 - _text.getSize().x / 2), (int)(window.getHeight() / 2 - _text.getSize().y / 2)});
                _text.setColor(gd::Color::Black);
            }

            std::string Menu::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Space) == gd::KeyBoard::State::Released) return "game";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) window.close();
                if (event.joyStick().isConnected() && event.joyStick().getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return "game";
                return "";
            }

            void Menu::draw(gd::Window &window)
            {
                window.draw(_background);
                window.draw(_text);
            }
        } // namespace Scene
    } // namespace Display
} // namespace RType
