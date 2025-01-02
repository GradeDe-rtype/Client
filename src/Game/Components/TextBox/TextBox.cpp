/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Game/Components/TextBox/TextBox.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            TextBox::TextBox(float max, std::string font, std::string text, Align align, int charactersize, gd::Color color, gd::Vector2<int> position)
            {
                _font = font;
                _texts.clear();
                _text = text;
                _charactersize = charactersize;
                _position = position;
                _color = color;
                _size = {max, 0};
                _align = align;

                _updateTexts();
            }

            void TextBox::draw(gd::Window &window)
            {
                for (auto &text : _texts)
                    text->draw(window);
            }

            void TextBox::setCharacterSize(int charactersize)
            {
                _charactersize = charactersize;
                _updateTexts();
            }

            void TextBox::setColor(gd::Color color)
            {
                _color = color;
                for (auto &text : _texts)
                    text->setColor(color);
            }

            void TextBox::setPosition(gd::Vector2<int> position)
            {
                _position = position;
                _alignTexts();
            }

            void TextBox::setText(std::string text)
            {
                _text = text;
                _updateTexts();
            }

            void TextBox::setSize(gd::Vector2<float> size)
            {
                _size = size;
                _updateTexts();
            }

            void TextBox::setAlign(Align align)
            {
                _align = align;
                _alignTexts();
            }

            gd::Vector2<int> TextBox::getPosition() const
            {
                return _position;
            }

            int TextBox::getCharacterSize() const
            {
                return _charactersize;
            }

            gd::Color TextBox::getColor() const
            {
                return _color;
            }

            gd::Vector2<float> TextBox::getSize() const
            {
                return _size;
            }

            std::string TextBox::getText() const
            {
                return _text;
            }

            TextBox::Align TextBox::getAlign() const
            {
                return _align;
            }

            void TextBox::_updateTexts()
            {
                _texts.clear();
                std::vector<std::string> lines;
                std::string word = "";
                std::string currentLine = "";
                int currentWidth = 0;
                RType::Game::Components::Text text(_font, "", _charactersize, _color);

                for (int i = 0; i < (int)_text.size();) {
                    word = "";
                    for (; _text[i] != ' ' && _text[i] != '\n' && i < (int)_text.size(); i++)
                        word += _text[i];
                    text.setText(word);
                    int wordWidth = text.getSize().x;
                    if (wordWidth + currentWidth >= _size.x) {
                        if (wordWidth >= _size.x) {
                            if (!currentLine.empty()) currentLine += " ";
                            std::string wordPart = "";
                            for (int j = 0; j < (int)word.size(); j++) {
                                wordPart += word[j];
                                text.setText(wordPart);
                                if (currentWidth + text.getSize().x >= _size.x) {
                                    lines.push_back(currentLine + wordPart);
                                    currentLine = "";
                                    currentWidth = 0;
                                    wordPart = "";
                                }
                            }
                            currentLine = wordPart;
                            currentWidth = text.getSize().x;
                        } else {
                            lines.push_back(currentLine);
                            currentLine = word;
                            currentWidth = wordWidth;
                        }
                    } else {
                        if (!currentLine.empty()) currentLine += " ";
                        currentLine += word;
                        currentWidth += wordWidth;
                    }
                    if (_text[i] == '\n') {
                        lines.push_back(currentLine);
                        currentLine = "";
                        currentWidth = 0;
                    }
                    i++;
                }
                lines.push_back(currentLine);

                for (auto &line : lines)
                    _texts.push_back(std::make_unique<Game::Components::Text>(_font, line, _charactersize, _color));
                _alignTexts();
            }

            void TextBox::_alignTexts()
            {
                gd::Vector2<int> position = _position;
                for (auto &text : _texts) {
                    if (_align == Align::Center)
                        position.x = _position.x + _size.x / 2 - text->getSize().x / 2;
                    else if (_align == Align::Right)
                        position.x = position.x + _size.x - text->getSize().x;
                    text->setPosition(position);
                    position.y += text->getSize().y;
                }
                _size.y = position.y - _position.y;
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
