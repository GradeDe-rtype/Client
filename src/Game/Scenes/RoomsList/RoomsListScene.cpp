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

                _moveSelectedColumn(window, 0, true);

                _linksComponent[_getIndexLink("dico.refresh")]->setText(Traductor::get()->translate("dico.wait"));
            }

            std::string RoomsList::handleEvent(gd::Window &window, gd::Event &event)
            {
                gd::Vector2<float> mouse = event.mouse.getPosition(window);
                if (_selectColumn == 0) {
                    for (int i = 0; i < (int)_linksComponent.size(); i++) {
                        gd::Vector2<float> pos = _linksComponent[i]->getPosition();
                        gd::Vector2<float> size = _linksComponent[i]->getSize();
                        if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                            if (event.mouse.hasMove(window)) {
                                _selectIndex = i;
                                _moveSelectIndexLink(0);
                            }
                            if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) return (this->*std::get<0>(_linksDatas[i]))();
                        }
                    }
                } else {
                    for (int i = 0; i < _displayRoomGameSlot + _roomGameSlotIndex && i < (int)RType::Ressources::get()->roomGameSlots.size(); i++) {
                        gd::Vector2<float> pos = RType::Ressources::get()->roomGameSlots[i]->getPosition();
                        gd::Vector2<float> size = RType::Ressources::get()->roomGameSlots[i]->getSize();
                        if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                            if (event.mouse.hasMove(window)) {
                                _selectIndex = i;
                                _moveSelectIndexLink(0);
                            }
                            if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) return _joinRoom();
                        }
                    }
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) (_selectColumn == 0) ? _moveSelectIndexLink(-1) : _moveSelectIndexRoomGameSlot(window, -1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) (_selectColumn == 0) ? _moveSelectIndexLink(1) : _moveSelectIndexRoomGameSlot(window, 1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(window, -1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(window, 1);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Pressed) return "exit";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) {
                    if (_selectColumn == 0) return (this->*std::get<0>(_linksDatas[_selectIndex]))();
                    if (_selectColumn == 1) return _joinRoom();
                }
                if (event.joyStick.isConnected()) {
                    if (event.joyStick.getXAxisPosition(false) < -50) _moveSelectIndexLink(-1);
                    if (event.joyStick.getXAxisPosition(true) > 50) _moveSelectIndexLink(1);
                    if (event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) {
                        if (_selectColumn == 0) return (this->*std::get<0>(_linksDatas[_selectIndex]))();
                        if (_selectColumn == 1) return _joinRoom();
                    }
                }
                return "";
            }

            void RoomsList::reload(gd::Window &window)
            {
                for (int i = 0; i < (int)_linksComponent.size(); i++) {
                    _linksComponent[i]->reload(window);
                    _linksComponent[i]->setText(Traductor::get()->translate(std::get<1>(_linksDatas[i])));
                }
            }

            void RoomsList::update(gd::Window &window)
            {
                if (_refreshTimer.getElapsedTime() > _refreshTimeout && _linksComponent[_getIndexLink("dico.refresh")]->getText() == Traductor::get()->translate("dico.wait")) {
                    _refreshTimer.reset();
                    _linksComponent[_getIndexLink("dico.refresh")]->setText(Traductor::get()->translate("dico.refresh"));
                }
                if (RType::Ressources::get()->majRoom) {
                    _setRoomGameSlotIndex(window, 0);
                    RType::Ressources::get()->majRoom = false;
                }
            }

            void RoomsList::draw(gd::Window &window)
            {
                for (auto &link : _linksComponent)
                    link->draw(window);
                for (int i = _roomGameSlotIndex; i < _displayRoomGameSlot + _roomGameSlotIndex && i < (int)RType::Ressources::get()->roomGameSlots.size(); i++)
                    RType::Ressources::get()->roomGameSlots[i]->draw(window);
            }

            void RoomsList::_createLinks(std::vector<std::pair<std::string (RoomsList::*)(), std::string>> datas, gd::Window &window)
            {
                float maxSize = window.getWidth() / 4 - _linkPadding * 2;
                for (int i = 0; i < (int)datas.size(); i++) {
                    _linksComponent.push_back(std::make_unique<RType::Game::Components::TextBox>(maxSize, "Karma Future", Traductor::get()->translate(datas[i].second), RType::Game::Components::TextBox::Align::Center));
                    _linksComponent.back()->setPosition(gd::Vector2<float>(_linkPadding, window.getHeight() / ((int)datas.size() + 1) * (i + 1) - _linksComponent.back()->getSize().y / 2));
                    _linksDatas.push_back(datas[i]);
                }
            }

            int RoomsList::_getIndexLink(std::string name)
            {
                for (int i = 0; i < (int)_linksDatas.size(); i++)
                    if (std::get<1>(_linksDatas[i]) == name)
                        return i;
                return 0;
            }

            void RoomsList::_moveSelectIndexLink(int index, bool forced)
            {
                if (!forced && _input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndex += index;
                _selectIndex = _selectIndex % (int)_linksDatas.size();
                _selectIndex = (_selectIndex < 0) ? (int)_linksDatas.size() - 1 : _selectIndex;

                for (auto &link : _linksComponent)
                    link->setColor(gd::Color(255, 255, 255, 150));
                _linksComponent[_selectIndex]->setColor(gd::Color(255, 255, 255, 255));
            }

            void RoomsList::_moveSelectIndexRoomGameSlot(gd::Window &window, int index, bool forced)
            {
                if (!forced && _input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndex += index;
                _selectIndex = _selectIndex % (int)RType::Ressources::get()->roomGameSlots.size();
                _selectIndex = (_selectIndex < 0) ? (int)RType::Ressources::get()->roomGameSlots.size() - 1 : _selectIndex;

                if (_selectIndex < _roomGameSlotIndex)
                    _setRoomGameSlotIndex(window, _selectIndex);
                if (_selectIndex >= _roomGameSlotIndex + _displayRoomGameSlot)
                    _setRoomGameSlotIndex(window, _roomGameSlotIndex + 1);

                for (int i = 0; i < (int)RType::Ressources::get()->roomGameSlots.size(); i++)
                    RType::Ressources::get()->roomGameSlots[i]->setColor(gd::Color(255, 255, 255, 150));
                RType::Ressources::get()->roomGameSlots[_selectIndex]->setColor(gd::Color(255, 255, 255, 255));
            }

            std::string RoomsList::_linkBack()
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                return "menu";
            }

            std::string RoomsList::_linkRefresh()
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                if (_refreshTimer.getElapsedTime() >= _refreshTimeout) {
                    _linksComponent[_getIndexLink("dico.refresh")]->setText(Traductor::get()->translate("dico.wait"));
                    RType::Ressources::get()->sendList->push("list");
                    _selectIndex = _getIndexLink("dico.refresh");
                    _refreshTimer.reset();
                }
                return "";
            }

            std::string RoomsList::_joinRoom()
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                RType::Ressources::get()->sendList->push("join " + std::to_string(RType::Ressources::get()->roomGameSlots[_selectIndex]->getId()));
                return "waitingRoom";
            }

            std::string RoomsList::_linkJoin()
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                return "";
            }

            std::string RoomsList::_linkCreate()
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                RType::Ressources::get()->sendList->push("create");
                return "waitingRoom";
            }

            void RoomsList::_setRoomGameSlotIndex(gd::Window &window, int index)
            {
                _roomGameSlotIndex = index;
                float x = window.getWidth() / 4 + _linkPadding;
                float maxSize = window.getWidth() / 4 * 3 - _linkPadding * 2;
                for (int i = _roomGameSlotIndex; i < _displayRoomGameSlot + _roomGameSlotIndex && i < (int)RType::Ressources::get()->roomGameSlots.size(); i++) {
                    RType::Ressources::get()->roomGameSlots[i]->setSizeX(maxSize);
                    RType::Ressources::get()->roomGameSlots[i]->setPosition(gd::Vector2<float>(x, window.getHeight() / (_displayRoomGameSlot + 1) * (i + 1 - _roomGameSlotIndex) - RType::Ressources::get()->roomGameSlots[i]->getSize().y / 2));
                }
            }

            void RoomsList::_moveSelectedColumn(gd::Window &window, int index, bool forced)
            {
                if (!forced && _input.getElapsedTime() < 200) return;
                _input.reset();

                _selectColumn += index;
                _selectColumn = (_selectColumn < 0) ? 0 : _selectColumn;
                _selectColumn = (_selectColumn > 1) ? 1 : _selectColumn;

                _selectIndex = 0;
                for (int i = 0; i < (int)_linksComponent.size(); i++)
                    _linksComponent[i]->setColor(gd::Color(255, 255, 255, 150));
                for (auto &room : RType::Ressources::get()->roomGameSlots)
                    room->setColor(gd::Color(255, 255, 255, 150));

                if (_selectColumn == 0)
                    _moveSelectIndexLink(0, true);
                else
                    _moveSelectIndexRoomGameSlot(window, 0, true);
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
