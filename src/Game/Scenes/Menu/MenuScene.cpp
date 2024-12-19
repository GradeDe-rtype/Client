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
                _addLink("game", "Play", window);
                _addLink("exit", "Quit", window);
                _setPositionsLinks();

                _links[_getIndexLink("game")].second->setColor(gd::Color(255, 255, 255, 150));

                _selectArrow = std::make_unique<Game::Entity::SelectArrow>();
                _setSelectArrowPosition();
            }

            std::string Menu::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelectArrow(-1);
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelectArrow(1);
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "exit";
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) return _links[_selectIndex].first;
                if (event.joyStick().isConnected()) {
                    if (event.joyStick().getYAxisPosition(false) < -50) _moveSelectArrow(-1);
                    if (event.joyStick().getYAxisPosition(true) > 50) _moveSelectArrow(1);
                    if (event.joyStick().getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return _links[_selectIndex].first;
                }
                return "";
            }

            void Menu::draw(gd::Window &window)
            {
                for (auto &link : _links)
                    link.second->draw(window);
                _selectArrow->draw(window);
            }

            void Menu::update(gd::Window &window)
            {
                if (!RType::Ressources::get()->isConnected || _connected) return;
                _links[_getIndexLink("game")].second->setColor(gd::Color::White);
            }

            void Menu::_addLink(std::string name, std::string link, gd::Window &window)
            {
                _links.push_back(std::make_pair(name, std::make_unique<Game::Components::Text>("Karma Future", link)));
            }

            void Menu::_setPositionsLinks()
            {
                for (int i = 0; i < (int)_links.size(); i++)
                    _links[i].second->setPosition({_linkSpacing, (int)(_linkGap * i + _linkSpacing)});
            }

            int Menu::_getIndexLink(std::string name)
            {
                for (int i = 0; i < (int)_links.size(); i++)
                    if (_links[i].first == name)
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
                _selectArrow->setPosition({(float)_linkSpacing / 2, (float)_links[_selectIndex].second->getPosition().y + _links[_selectIndex].second->getSize().y / 2});
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
