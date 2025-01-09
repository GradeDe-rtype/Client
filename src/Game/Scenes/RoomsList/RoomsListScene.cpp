/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "RoomsListScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void RoomsList::load(gd::Window &window)
            {
                _createLinks({{&RoomsList::_linkBack, "dico.back"},
                              {&RoomsList::_linkRefresh, "dico.refresh"},
                              {&RoomsList::_linkJoin, "dico.join"},
                              {&RoomsList::_linkCreate, "dico.create"}},
                             window);
                _input.reset();
                _refreshTimer.reset();

                for (auto &link : _links)
                    std::get<2>(link)->setColor(gd::Color(255, 255, 255, 150));
                std::get<2>(_links[_selectIndex])->setColor(gd::Color(255, 255, 255, 255));
                std::get<2>(_links[_getIndexLink("dico.refresh")])->setText(Traductor::get()->translate("dico.wait"));
            }

            std::string RoomsList::handleEvent(gd::Window &window, gd::Event &event)
            {
                gd::Vector2<float> mouse = event.mouse.getPosition(window);
                for (auto &link : _links) {
                    gd::Vector2<float> pos = std::get<2>(link)->getPosition();
                    gd::Vector2<float> size = std::get<2>(link)->getSize();
                    if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                        if (event.mouse.hasMove(window)) {
                            _selectIndex = _getIndexLink(std::get<1>(link));
                            if (_selectIndex == 0 && !RType::Ressources::get()->isConnected)
                                _selectIndex = 1;
                            _moveSelectedIndex(0);
                        }
                        if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) return (this->*std::get<0>(_links[_selectIndex]))();
                    }
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _moveSelectedIndex(-1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _moveSelectedIndex(1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Pressed) return "exit";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) return (this->*std::get<0>(_links[_selectIndex]))();
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getXAxisPosition(false) < -50) _moveSelectedIndex(-1);
                    if (event.joyStick.getXAxisPosition(true) > 50) _moveSelectedIndex(1);
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return (this->*std::get<0>(_links[_selectIndex]))();
                }
                return "";
            }

            void RoomsList::reload(gd::Window &window)
            {
                for (auto &link : _links) {
                    std::get<2>(link)->reload(window);
                    std::get<2>(link)->setText(Traductor::get()->translate(std::get<1>(link)));
                }
            }

            void RoomsList::update(gd::Window &window)
            {
                if (_refreshTimer.getElapsedTime() > 1000 && std::get<2>(_links[_getIndexLink("dico.refresh")])->getText() == Traductor::get()->translate("dico.wait")) {
                    _refreshTimer.reset();
                    std::get<2>(_links[_getIndexLink("dico.refresh")])->setText(Traductor::get()->translate("dico.refresh"));
                }
            }

            void RoomsList::draw(gd::Window &window)
            {
                for (auto &link : _links)
                    std::get<2>(link)->draw(window);
            }

            void RoomsList::_createLinks(std::vector<std::pair<std::string (RoomsList::*)(), std::string>> datas, gd::Window &window)
            {
                float maxSize = (window.getWidth() - _linkPadding * 2) / datas.size();
                float x = _linkPadding;
                for (auto &data : datas) {
                    _links.push_back(
                        std::make_tuple(
                            data.first,
                            data.second,
                            std::make_unique<Game::Components::TextBox>(maxSize, "Karma Future", Traductor::get()->translate(data.second), RType::Game::Components::TextBox::Align::Center)));
                    std::get<2>(_links.back())->setPosition(gd::Vector2<float>(x, window.getHeight() - _linkPadding - std::get<2>(_links.back())->getSize().y));
                    x += maxSize;
                }
            }

            int RoomsList::_getIndexLink(std::string name)
            {
                for (int i = 0; i < (int)_links.size(); i++)
                    if (std::get<1>(_links[i]) == name)
                        return i;
                return 0;
            }

            void RoomsList::_moveSelectedIndex(int index)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndex += index;
                _selectIndex = _selectIndex % (int)_links.size();
                _selectIndex = (_selectIndex < 0) ? (int)_links.size() - 1 : _selectIndex;

                for (auto &link : _links)
                    std::get<2>(link)->setColor(gd::Color(255, 255, 255, 150));
                if (_selectRow == 1)
                    std::get<2>(_links[_selectIndex])->setColor(gd::Color(255, 255, 255, 255));
            }

            std::string RoomsList::_linkBack()
            {
                return "menu";
            }

            std::string RoomsList::_linkRefresh()
            {
                if (_refreshTimer.getElapsedTime() >= 1000) {
                    std::get<2>(_links[_getIndexLink("dico.refresh")])->setText(Traductor::get()->translate("dico.wait"));
                    RType::Ressources::get()->sendList->push("list");
                    _refreshTimer.reset();
                }
                return "";
            }

            std::string RoomsList::_linkJoin()
            {
                return "";
            }

            std::string RoomsList::_linkCreate()
            {
                return "";
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
