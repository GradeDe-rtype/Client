/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "AMiniScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                void AMiniScene::load(gd::Vector2<float> coord, gd::Vector2<float> window)
                {
                    _coord = coord;
                    _window = window;

                    loadSections(window);

                    int h = coord.y + _innerPadding;
                    for (auto &section : _sections) {
                        section->setPosition(gd::Vector2<float>((float)(coord.x + _innerPadding), (float)h));
                        h += section->getSizeY() + _sectionGap;
                    }

                    _selected = (int)_sections.size();

                    _save = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("dico.back"));
                    _save->setPosition({(float)(coord.x + _innerPadding), (float)(window.y - _save->getSize().y - _innerPadding)});
                }

                void AMiniScene::reload(gd::Vector2<float> coord, gd::Vector2<float> window)
                {
                    _coord = coord;
                    _window = window;

                    int h = coord.y + 50;
                    for (auto &section : _sections) {
                        section->reload((gd::Vector2<float>){window.x - _innerPadding * 2, 20});
                        section->setPosition(gd::Vector2<float>((float)(coord.x + _innerPadding), (float)h));
                        h += section->getSizeY() + _sectionGap;
                    }

                    _save->setPosition({(float)(coord.x + _innerPadding), (float)(window.y - _save->getSize().y - _innerPadding)});
                }

                bool AMiniScene::handleEvent(gd::Window &window, gd::Event &event)
                {
                    gd::Vector2<float> mouse = event.mouse.getPosition(window);
                    for (int i = 0; i < (int)_sections.size(); i++) {
                        gd::Vector2<float> pos = _sections[i]->getPosition();
                        gd::Vector2<float> size = _sections[i]->getSize();
                        if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y)
                            _moveSelected(i - _selected);
                    }
                    if (mouse.x >= _save->getPosition().x && mouse.x <= _save->getPosition().x + _save->getSize().x && mouse.y >= _save->getPosition().y && mouse.y <= _save->getPosition().y + _save->getSize().y) {
                        _moveSelected((int)_sections.size() - _selected);
                        if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) _saveSettings();
                    }

                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelected(-1);
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelected(1);
                    if (event.joyStick.isConnected()) {
                        if (event.joyStick.getYAxisPosition(false) < -50) _moveSelected(-1);
                        if (event.joyStick.getYAxisPosition(true) > 50) _moveSelected(1);
                    }
                    if (_selected < (int)_sections.size()) {
                        if (_sections[_selected]->handleEvt(window, event) && _changes == false) {
                            _changes = true;
                            _save->setText(Traductor::get()->translate("dico.save"));
                        }
                        return false;
                    } else {
                        if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) _saveSettings();
                        if (event.joyStick.isConnected() && event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) _saveSettings();
                    }
                    return true;
                }

                void AMiniScene::draw(gd::Window &window)
                {
                    for (auto &section : _sections)
                        section->draw(window);
                    _save->draw(window);
                }

                void AMiniScene::loadSections(gd::Vector2<float> window)
                {
                    (void)window;
                }

                bool AMiniScene::changeScene()
                {
                    bool tmp = _changeScene;
                    _changeScene = false;
                    return tmp;
                }

                void AMiniScene::_moveSelected(int value)
                {
                    if (_input.getElapsedTime() < 200) return;
                    _input.reset();
                    _selected += value;
                    if (_selected < 0) _selected = 0;
                    if (_selected >= (int)_sections.size()) _selected = (int)_sections.size();

                    for (auto &section : _sections)
                        section->setColor(gd::Color(255, 255, 255, 150));
                    _save->setColor(gd::Color(255, 255, 255, 150));
                    if (_selected < (int)_sections.size())
                        _sections[_selected]->setColor(gd::Color::White);
                    else
                        _save->setColor(gd::Color::White);
                }

                void AMiniScene::_saveSettings()
                {
                    if (_input.getElapsedTime() < 200) return;
                    _input.reset();
                    if (_changes == false) {
                        _changeScene = true;
                        return;
                    }
                    _changes = false;
                    _save->setText(Traductor::get()->translate("dico.back"));

                    Papaya settings("./assets/data", "settings");
                    for (auto &section : _sections)
                        settings.updateData("setting", RType::Helpers::Utils::split(section->getName(), ".")[1], "value", section->saveValue());
                    settings.save();
                }
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
