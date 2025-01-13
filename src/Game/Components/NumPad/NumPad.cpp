/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "NumPad.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            NumPad::NumPad(gd::Vector2<float> size, gd::Vector2<float> position)
            {
                _size = size;
                float maxSizeX = size.x / 3 - _gap * 2;
                float maxSizeY = size.y / 4 - _gap * 2;
                for (int i = 0; i < 3; i++) {
                    std::vector<std::shared_ptr<RType::Game::Components::TextBox>> row;
                    for (int j = 0; j < 3; j++)
                        row.push_back(std::make_unique<RType::Game::Components::TextBox>(maxSizeX, "Karma Future", std::to_string(i * 3 + j + 1), RType::Game::Components::TextBox::Align::Center, 1.4f, gd::Color(255, 255, 255, 150)));
                    _numPad.push_back(row);
                }
                std::vector<std::shared_ptr<RType::Game::Components::TextBox>> row;
                row.push_back(std::make_shared<RType::Game::Components::TextBox>(maxSizeX, "Karma Future", "<", RType::Game::Components::TextBox::Align::Center, 1.4f, gd::Color(255, 255, 255, 150)));
                row.push_back(std::make_shared<RType::Game::Components::TextBox>(maxSizeX, "Karma Future", "0", RType::Game::Components::TextBox::Align::Center, 1.4f, gd::Color(255, 255, 255, 150)));
                row.push_back(std::make_shared<RType::Game::Components::TextBox>(maxSizeX, "Karma Future", ">", RType::Game::Components::TextBox::Align::Center, 1.4f, gd::Color(255, 255, 255, 150)));
                _numPad.push_back(row);
                _numPad[_index.y][_index.x]->setColor(gd::Color(255, 255, 255, 255));
                setPosition(position);
                _inputTime.reset();
            }

            void NumPad::reload(gd::Window &window)
            {
                for (auto &row : _numPad)
                    for (auto &textBox : row)
                        textBox->reload(window);
                _inputTime.reset();
            }

            void NumPad::draw(gd::Window &window)
            {
                for (auto &row : _numPad)
                    for (auto &textBox : row)
                        textBox->draw(window);
            }

            void NumPad::setPosition(gd::Vector2<float> position)
            {
                _position = position;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 3; j++) {
                        float posX = _position.x + _size.x / 3 * j + _size.x / 6 - _numPad[i][j]->getSize().x / 2;
                        float posY = _position.y + _size.y / 4 * i + _size.y / 8 - _numPad[i][j]->getSize().y / 2;
                        _numPad[i][j]->setPosition({posX, posY});
                    }
                }
            }

            void NumPad::handleEvent(gd::Window &window, gd::Event &event)
            {
                _input = 0;
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _updateIndex({_index.x, _index.y - 1});
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _updateIndex({_index.x, _index.y + 1});
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _updateIndex({_index.x - 1, _index.y});
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _updateIndex({_index.x + 1, _index.y});
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Pressed) _input = _numPad[_index.y][_index.x]->getText()[0];
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getYAxisPosition(false) < -50) _updateIndex({_index.x, _index.y - 1});
                    if (event.joyStick.getYAxisPosition(true) > 50) _updateIndex({_index.x, _index.y + 1});
                    if (event.joyStick.getXAxisPosition(false) < -50) _updateIndex({_index.x - 1, _index.y});
                    if (event.joyStick.getXAxisPosition(true) > 50) _updateIndex({_index.x + 1, _index.y});
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Pressed) _input = _numPad[_index.y][_index.x]->getText()[0];
                }
                gd::Vector2<float> mouse = event.mouse.getPosition(window);
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 3; j++) {
                        gd::Vector2<float> pos = _numPad[i][j]->getPosition();
                        gd::Vector2<float> size = _numPad[i][j]->getSize();
                        if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                            if (event.mouse.hasMove(window)) _updateIndex({j, i});
                            if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) _input = _numPad[i][j]->getText()[0];
                        }
                    }
                }
            }

            char NumPad::getInput() const
            {
                return _input;
            }

            gd::Vector2<float> NumPad::getSize() const
            {
                return _size;
            }

            void NumPad::_updateIndex(gd::Vector2<int> index)
            {
                if (_inputTime.getElapsedTime() < 200) return;
                _inputTime.reset();

                _index = index;
                for (auto &row : _numPad)
                    for (auto &textBox : row)
                        textBox->setColor(gd::Color(255, 255, 255, 150));
                _numPad[_index.y][_index.x]->setColor(gd::Color(255, 255, 255, 255));
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
