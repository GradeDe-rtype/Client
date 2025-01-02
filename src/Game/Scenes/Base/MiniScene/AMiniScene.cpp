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
                        section->setPos(gd::Vector2<float>((float)(coord.x + _innerPadding), (float)h));
                        h += section->getSizeY() + _sectionGap;
                    }

                    _selected = (int)_sections.size();

                    _save = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("dico.back"));
                    _save->setPosition({(int)(coord.x + _innerPadding), (int)(window.y - _save->getSize().y - _innerPadding)});
                }

                void AMiniScene::reload(gd::Vector2<float> coord, gd::Vector2<float> window)
                {
                    _coord = coord;
                    _window = window;

                    int h = coord.y + 50;
                    for (auto &section : _sections) {
                        section->setTextValue();
                        section->setPos(gd::Vector2<float>((float)(coord.x + _innerPadding), (float)h));
                        h += section->getSizeY() + _sectionGap;
                    }

                    _save->setPosition({(int)(coord.x + _innerPadding), (int)(window.y - _save->getSize().y - _innerPadding)});
                }

                bool AMiniScene::handleEvent(gd::Event &event)
                {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelected(-1);
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelected(1);
                    if (event.joyStick().isConnected()) {
                        if (event.joyStick().getYAxisPosition(false) < -50) _moveSelected(-1);
                        if (event.joyStick().getYAxisPosition(true) > 50) _moveSelected(1);
                    }
                    if (_selected < (int)_sections.size()) {
                        if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _changeRangeValue(-1);
                        if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _changeRangeValue(1);
                        if (event.joyStick().isConnected()) {
                            if (event.joyStick().getXAxisPosition(false) < -50) _changeRangeValue(-1);
                            if (event.joyStick().getXAxisPosition(true) > 50) _changeRangeValue(1);
                        }
                        return false;
                    } else {
                        if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Released) _saveSettings();
                        if (event.joyStick().isConnected() && event.joyStick().getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) _saveSettings();
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

                void AMiniScene::_changeRangeValue(int value)
                {
                    if (_input.getElapsedTime() < 100) return;
                    _input.reset();
                    if (value < 0)
                        _sections[_selected]->range()->downValue();
                    else
                        _sections[_selected]->range()->upValue();

                    _sections[_selected]->setTextValue();
                    _sections[_selected]->setSettingValue();
                    RType::Game::Managers::Scenes::get().needToReload();
                    if (_changes == false) {
                        _changes = true;
                        _save->setText(Traductor::get()->translate("dico.save"));
                    }
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
                    if (_changes == false) return;
                    _changes = false;
                    _save->setText(Traductor::get()->translate("dico.back"));

                    Papaya settings("./assets/data", "settings");
                    for (auto &section : _sections)
                        settings.updateData("setting", RType::Helpers::Utils::split(section->getName(), ".")[1], "value", std::to_string((int)section->getValue()));
                    settings.save();
                }
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
