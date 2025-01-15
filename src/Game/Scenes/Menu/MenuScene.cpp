/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "MenuScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void Menu::load(gd::Window &window)
            {
                _addLink("roomsList", "dico.play", window);
                _addLink("settings", "dico.settings", window);
                _addLink("exit", "dico.quit", window);
                _setPositionsLinks();

                std::get<2>(_links[_getIndexLink("roomsList")])->setColor(gd::Color(255, 255, 255, 150));

                _selectArrow = std::make_unique<Game::Entity::SelectArrow>();
                _setSelectArrowPosition();
            }

            std::string Menu::handleEvent(gd::Window &window, gd::Event &event)
            {
                gd::Vector2<float> mouse = event.mouse.getPosition(window);
                for (auto &link : _links) {
                    gd::Vector2<float> pos = std::get<2>(link)->getPosition();
                    gd::Vector2<float> size = std::get<2>(link)->getSize();
                    if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                        if (event.mouse.hasMove(window)) {
                            _selectIndex = _getIndexLink(std::get<0>(link));
                            if (_selectIndex == 0 && !RType::Ressources::get()->isConnected)
                                _selectIndex = 1;
                            _setSelectArrowPosition();
                        }
                        if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) return std::get<0>(_links[_selectIndex]);
                    }
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelectArrow(-1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelectArrow(1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Pressed) return "exit";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) return std::get<0>(_links[_selectIndex]);
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getYAxisPosition(false) < -50) _moveSelectArrow(-1);
                    if (event.joyStick.getYAxisPosition(true) > 50) _moveSelectArrow(1);
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return std::get<0>(_links[_selectIndex]);
                }
                return "";
            }

            void Menu::reload(gd::Window &window)
            {
                for (auto &link : _links) {
                    std::get<2>(link)->reload(window);
                    std::get<2>(link)->setText(Traductor::get()->translate(std::get<1>(link)));
                }
                _setPositionsLinks();
                _setSelectArrowPosition();
            }

            void Menu::draw(gd::Window &window)
            {
                for (auto &link : _links)
                    std::get<2>(link)->draw(window);
                _selectArrow->draw(window);
            }

            void Menu::update(gd::Window &window)
            {
                if (!RType::Ressources::get()->isConnected || _connected) return;
                std::get<2>(_links[_getIndexLink("roomsList")])->setColor(gd::Color::White);
                RType::Ressources::get()->sendList->push("list");
                _connected = true;
            }

            void Menu::_addLink(std::string name, std::string link, gd::Window &window)
            {
                _links.push_back(std::make_tuple(name, link, std::make_unique<Game::Components::Text>("Karma Future", Traductor::get()->translate(link))));
            }

            void Menu::_setPositionsLinks()
            {
                int h = _linkSpacing;
                for (auto &link : _links) {
                    std::get<2>(link)->setPosition({(float)_linkSpacing, (float)h});
                    h += _linkGap + std::get<2>(link)->getSize().y;
                }
            }

            int Menu::_getIndexLink(std::string name)
            {
                for (int i = 0; i < (int)_links.size(); i++)
                    if (std::get<0>(_links[i]) == name)
                        return i;
                return 0;
            }

            void Menu::_moveSelectArrow(int index)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndex += index;
                _selectIndex = _selectIndex % (int)_links.size();
                _selectIndex = (_selectIndex < 0) ? (int)_links.size() - 1 : _selectIndex;

                if (_selectIndex == 0 && !RType::Ressources::get()->isConnected) {
                    _selectIndex += index;
                    _selectIndex = _selectIndex % (int)_links.size();
                    _selectIndex = (_selectIndex < 0) ? (int)_links.size() - 1 : _selectIndex;
                }
                _setSelectArrowPosition();
            }

            void Menu::_setSelectArrowPosition()
            {
                _selectArrow->setPosition({(float)_linkSpacing / 2, (float)std::get<2>(_links[_selectIndex])->getPosition().y + std::get<2>(_links[_selectIndex])->getSize().y / 2});
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
