/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "RoomGameSlot.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            RoomGameSlot::RoomGameSlot(int id, std::unordered_map<std::string, std::string> &datas, float sizeX, gd::Vector2<float> position)
            {
                _size = gd::Vector2<float>(sizeX, 50);
                _position = position;

                _name = std::make_unique<RType::Game::Components::TextBox>(_size.x, "Karma Future", datas["name"], RType::Game::Components::TextBox::Align::Left, 1.2, gd::Color::White);
                _players = std::make_unique<RType::Game::Components::TextBox>(_size.x, "Karma Future", datas["count"], RType::Game::Components::TextBox::Align::Center, 1.8, gd::Color::White);
                _gameMode = std::make_unique<RType::Game::Components::TextBox>(_size.x, "Karma Future", datas["mode"], RType::Game::Components::TextBox::Align::Left, 0.8, gd::Color::White);

                _background = std::make_unique<gd::RectangleShape>();
                _background->create(_size);
                _background->setFillColor(gd::Color(0, 0, 0, 0));
                _background->setOutlineColor(gd::Color::White);
                _background->setOutlineThickness(2);

                setSizeX(sizeX);
                setPosition(_position);
                setColor(gd::Color(255, 255, 255, 150));
            }

            void RoomGameSlot::draw(gd::Window &window)
            {
                window.draw(*_background);
                _name->draw(window);
                _players->draw(window);
                _gameMode->draw(window);
            }

            void RoomGameSlot::setColor(gd::Color color)
            {
                _name->setColor(color);
                _players->setColor(color);
                _gameMode->setColor(color);
                _background->setOutlineColor(color);
            }

            gd::Vector2<float> RoomGameSlot::getSize() const
            {
                return _size;
            }

            void RoomGameSlot::setPosition(gd::Vector2<float> position)
            {
                _position = position;

                _name->setPosition(gd::Vector2<float>(_position.x + _innerPadding, _position.y + _innerPadding));
                _gameMode->setPosition(gd::Vector2<float>(_position.x + _innerPadding, _position.y + _size.y - _gameMode->getSize().y - _innerPadding));
                _players->setPosition(gd::Vector2<float>(_position.x + _size.x - _players->getSize().x - _innerPadding, _position.y + _size.y / 2 - _players->getSize().y / 2));
                _background->setPosition(_position);
            }

            void RoomGameSlot::setPosition(float x, float y)
            {
                setPosition(gd::Vector2<float>(x, y));
            }

            void RoomGameSlot::setSizeX(float x)
            {
                _size.x = x;
                _name->setSizeX(_size.x - _innerPadding * 3);
                _gameMode->setSizeX(_size.x - _innerPadding * 3);

                _players->setSizeX(_name->getSize().y + _innerPadding + _gameMode->getSize().y);
                _name->setSizeX(_size.x - _innerPadding * 3 - _players->getSize().x);
                _gameMode->setSizeX(_size.x - _innerPadding * 3 - _players->getSize().x);

                _size.y = _name->getSize().y + _innerPadding * 3 + _gameMode->getSize().y;
                _background->setSize(_size);

                setPosition(_position);
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
