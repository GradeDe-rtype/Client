/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "LanguagesMiniScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                namespace Settings
                {
                    void LanguagesMiniScene::load(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;
                        int h = coord.y + _innerPadding;

                        _selectArrow = std::make_unique<RType::Game::Entity::SelectArrow>();
                        _selectArrow->setColor(gd::Color(255, 255, 255, 150));

                        for (auto &lang : Traductor::get()->getLangs()) {
                            _langs.push_back(std::make_tuple(lang, std::make_shared<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("languages." + lang))));
                            std::get<1>(_langs.back())->setPosition({(float)(coord.x + _innerPadding), (float)h});
                            h += std::get<1>(_langs.back())->getSize().y + _innerPadding;
                            std::get<1>(_langs.back())->setColor(gd::Color(255, 255, 255, 150));

                            if (Traductor::get()->getLang() == lang) {
                                _selectedLang = std::get<1>(_langs.back());
                                _selectArrow->setPosition({(float)(_selectedLang->getPosition().x - _selectArrow->getSize().x - 10), (float)(_selectedLang->getPosition().y + _selectedLang->getSize().y / 2)});
                            }
                        }

                        _save = std::make_unique<RType::Game::Components::Text>("Karma Future", Traductor::get()->translate("dico.back"));
                        _save->setPosition({(float)(coord.x + _innerPadding), (float)(window.y - _save->getSize().y - _innerPadding)});
                        _selected = _langs.size();
                    }

                    void LanguagesMiniScene::reload(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;
                        int h = coord.y + _innerPadding;

                        _selectArrow->setColor(gd::Color(255, 255, 255, 150));

                        for (auto &lang : _langs) {
                            std::get<1>(lang)->setText(Traductor::get()->translate("languages." + std::get<0>(lang)));
                            std::get<1>(lang)->setPosition({(float)(coord.x + _innerPadding), (float)h});
                            h += std::get<1>(lang)->getSize().y + _innerPadding;
                            std::get<1>(lang)->setColor(gd::Color(255, 255, 255, 150));
                        }

                        _selectArrow->setPosition({(float)(_selectedLang->getPosition().x - _selectArrow->getSize().x - 10), (float)(_selectedLang->getPosition().y + _selectedLang->getSize().y / 2)});

                        _save->setPosition({(float)(coord.x + _innerPadding), (float)(window.y - _save->getSize().y - _innerPadding)});
                        _save->setColor(gd::Color(255, 255, 255, 150));
                        _selected = _langs.size();
                    }

                    bool LanguagesMiniScene::handleEvent(gd::Window &window, gd::Event &event)
                    {
                        gd::Vector2<float> mouse = event.mouse.getPosition(window);
                        for (int i = 0; i < (int)_langs.size(); i++) {
                            gd::Vector2<float> pos = std::get<1>(_langs[i])->getPosition();
                            gd::Vector2<float> size = std::get<1>(_langs[i])->getSize();
                            if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y) {
                                if (event.mouse.hasMove(window))
                                    _moveSelected(i - _selected);
                                if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) _changeSelectedLang();
                            }
                        }
                        if (mouse.x >= _save->getPosition().x && mouse.x <= _save->getPosition().x + _save->getSize().x && mouse.y >= _save->getPosition().y && mouse.y <= _save->getPosition().y + _save->getSize().y) {
                            if (event.mouse.hasMove(window))
                                _moveSelected((int)_langs.size() - _selected);
                            if (event.mouse.getButtonState(gd::Mouse::Button::Left) == gd::Mouse::State::Released) _saveSettings();
                        }
                        if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelected(-1);
                        if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelected(1);
                        if (event.joyStick.isConnected()) {
                            if (event.joyStick.getYAxisPosition(false) < -50) _moveSelected(-1);
                            if (event.joyStick.getYAxisPosition(true) > 50) _moveSelected(1);
                        }
                        if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Return) == gd::KeyBoard::State::Pressed) _changeSelectedLang();
                        if (event.joyStick.isConnected() && event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Pressed) _changeSelectedLang();
                        return true;
                    }

                    void LanguagesMiniScene::draw(gd::Window &window)
                    {
                        for (auto &lang : _langs)
                            std::get<1>(lang)->draw(window);
                        _selectArrow->draw(window);
                        _save->draw(window);
                    }

                    void LanguagesMiniScene::_moveSelected(int value)
                    {
                        if (_input.getElapsedTime() < 200) return;
                        _input.reset();
                        _selected += value;
                        if (_selected < 0) _selected = 0;
                        if (_selected >= (int)_langs.size()) _selected = (int)_langs.size();

                        for (int i = 0; i < (int)_langs.size(); i++)
                            std::get<1>(_langs[i])->setColor(gd::Color(255, 255, 255, 150));
                        _save->setColor(gd::Color(255, 255, 255, 150));
                        _selectArrow->setColor(gd::Color(255, 255, 255, 150));
                        if (_selected < (int)_langs.size()) {
                            std::get<1>(_langs[_selected])->setColor(gd::Color::White);
                            if (_selectedLang == std::get<1>(_langs[_selected]))
                                _selectArrow->setColor(gd::Color::White);
                        } else
                            _save->setColor(gd::Color::White);
                    }

                    void LanguagesMiniScene::_changeSelectedLang()
                    {
                        if (_changes == false) {
                            _changes = true;
                            _save->setText(Traductor::get()->translate("dico.save"));
                        }
                        if (_selected == (int)_langs.size()) {
                            _saveSettings();
                            return;
                        }
                        _selectedLang = std::get<1>(_langs[_selected]);
                        _selectArrow->setPosition({(float)(_selectedLang->getPosition().x - _selectArrow->getSize().x - 10), (float)(_selectedLang->getPosition().y + _selectedLang->getSize().y / 2)});
                        Traductor::get()->setLang(std::get<0>(_langs[_selected]));
                        RType::Game::Managers::Scenes::get().needToReload();
                    }

                    void LanguagesMiniScene::_saveSettings()
                    {
                        if (_changes == false) {
                            _changeScene = true;
                            return;
                        }
                        _changes = false;
                        _save->setText(Traductor::get()->translate("dico.back"));

                        Papaya settings("./assets/data", "settings");
                        settings.updateData("setting", "lang", "value", Traductor::get()->getLang());
                        settings.save();
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
