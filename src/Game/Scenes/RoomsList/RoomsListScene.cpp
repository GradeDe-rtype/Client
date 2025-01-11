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
                std::get<2>(_links[_selectIndexLink])->setColor(gd::Color(255, 255, 255, 255));
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
                            _selectIndexLink = _getIndexLink(std::get<1>(link));
                            if (_selectIndexLink == 0 && !RType::Ressources::get()->isConnected)
                                _selectIndexLink = 1;
                            _moveSelectIndexLink(0);
                        }
                        if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) return (this->*std::get<0>(_links[_selectIndexLink]))();
                    }
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _moveSelectIndexLink(-1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _moveSelectIndexLink(1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Pressed) return "exit";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) return (this->*std::get<0>(_links[_selectIndexLink]))();
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getXAxisPosition(false) < -50) _moveSelectIndexLink(-1);
                    if (event.joyStick.getXAxisPosition(true) > 50) _moveSelectIndexLink(1);
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return (this->*std::get<0>(_links[_selectIndexLink]))();
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
                if (_refreshTimer.getElapsedTime() > _refreshTimeout && std::get<2>(_links[_getIndexLink("dico.refresh")])->getText() == Traductor::get()->translate("dico.wait")) {
                    _refreshTimer.reset();
                    std::get<2>(_links[_getIndexLink("dico.refresh")])->setText(Traductor::get()->translate("dico.refresh"));
                }
                if (RType::Ressources::get()->majRoom) {
                    _setRoomGameSlotIndex(window, 0);
                    RType::Ressources::get()->majRoom = false;
                }
            }

            void RoomsList::draw(gd::Window &window)
            {
                for (auto &link : _links)
                    std::get<2>(link)->draw(window);
                for (int i = _roomGameSlotIndex; i < _displayRoomGameSlot && i < (int)RType::Ressources::get()->roomGameSlots.size(); i++)
                    RType::Ressources::get()->roomGameSlots[i]->draw(window);
            }

            void RoomsList::_createLinks(std::vector<std::pair<std::string (RoomsList::*)(), std::string>> datas, gd::Window &window)
            {
                float maxSize = window.getWidth() / 4 - _linkPadding * 2;
                for (int i = 0; i < (int)datas.size(); i++) {
                    _links.push_back(std::make_tuple(datas[i].first, datas[i].second, std::make_unique<Game::Components::TextBox>(maxSize, "Karma Future", Traductor::get()->translate(datas[i].second), RType::Game::Components::TextBox::Align::Center)));
                    std::get<2>(_links.back())->setPosition(gd::Vector2<float>(_linkPadding, window.getHeight() / ((int)datas.size() + 1) * (i + 1) - std::get<2>(_links.back())->getSize().y / 2));
                }
            }

            int RoomsList::_getIndexLink(std::string name)
            {
                for (int i = 0; i < (int)_links.size(); i++)
                    if (std::get<1>(_links[i]) == name)
                        return i;
                return 0;
            }

            void RoomsList::_moveSelectIndexLink(int index)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndexLink += index;
                _selectIndexLink = _selectIndexLink % (int)_links.size();
                _selectIndexLink = (_selectIndexLink < 0) ? (int)_links.size() - 1 : _selectIndexLink;

                for (auto &link : _links)
                    std::get<2>(link)->setColor(gd::Color(255, 255, 255, 150));
                if (_selectColumn == 1)
                    std::get<2>(_links[_selectIndexLink])->setColor(gd::Color(255, 255, 255, 255));
            }

            std::string RoomsList::_linkBack()
            {
                return "menu";
            }

            std::string RoomsList::_linkRefresh()
            {
                if (_refreshTimer.getElapsedTime() >= _refreshTimeout) {
                    std::get<2>(_links[_getIndexLink("dico.refresh")])->setText(Traductor::get()->translate("dico.wait"));
                    RType::Ressources::get()->sendList->push("list");
                    _roomGameSlotIndex = 0;
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

            void RoomsList::_setRoomGameSlotIndex(gd::Window &window, int index)
            {
                float x = window.getWidth() / 4 + _linkPadding;
                float maxSize = window.getWidth() / 4 * 3 - _linkPadding * 2;
                for (int i = _roomGameSlotIndex; i < _displayRoomGameSlot && i < (int)RType::Ressources::get()->roomGameSlots.size(); i++) {
                    RType::Ressources::get()->roomGameSlots[i]->setSizeX(maxSize);
                    RType::Ressources::get()->roomGameSlots[i]->setPosition(gd::Vector2<float>(x, window.getHeight() / (_displayRoomGameSlot + 1) * (i + 1) - RType::Ressources::get()->roomGameSlots[i]->getSize().y / 2));
                }
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
