/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SoundsMiniScene.hpp"

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
                    void SoundsMiniScene::load(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;

                        int h = coord.y + 50;
                        std::vector<std::string> sections = {"settings.sound", "settings.music"};

                        for (int i = 0; i < (int)sections.size(); i++) {
                            _datas.push_back(std::make_tuple(sections[i], std::make_shared<Game::Components::Text>("Karma Future", Traductor::get()->translate(sections[i])), std::make_shared<Game::Components::Range>(0, 100, 2, (gd::Vector2<float>){(float)(coord.x + _innerPadding), (float)(h + 50)}, (gd::Vector2<float>){window.x - _innerPadding * 2, 20})));
                            std::get<1>(_datas[i])->setPosition({(int)(coord.x + _innerPadding), h});
                            h = std::get<1>(_datas[i])->getPosition().y + std::get<1>(_datas[i])->getSize().y + 100;

                            if (sections[i] == "settings.music")
                                std::get<2>(_datas[i])->setValue(RType::Game::Managers::Music::get().getVolume());

                            std::string text = Traductor::get()->translate(sections[i]);
                            text.replace(text.find("{value}"), 7, std::to_string((int)(std::get<2>(_datas[i])->getValue())));
                            std::get<1>(_datas[i])->setText(text);
                            std::get<2>(_datas[i])->setColor(gd::Color(255, 255, 255, 150));
                            std::get<1>(_datas[i])->setColor(gd::Color(255, 255, 255, 150));
                        }
                        _selected = (int)sections.size();

                        _save = std::make_unique<Game::Components::Text>("Karma Future", Traductor::get()->translate("dico.back"));
                        _save->setPosition({(int)(coord.x + _innerPadding), (int)(window.y - _save->getSize().y - _innerPadding)});
                    }

                    void SoundsMiniScene::reload(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;

                        int h = coord.y + 50;
                        for (auto &data : _datas) {
                            std::string text = Traductor::get()->translate(std::get<0>(data));
                            text.replace(text.find("{value}"), 7, std::to_string((int)(std::get<2>(data)->getValue())));
                            std::get<1>(data)->setText(text);
                            std::get<1>(data)->setPosition({(int)(coord.x + _innerPadding), h});
                            h = std::get<1>(data)->getPosition().y + std::get<1>(data)->getSize().y + 100;
                            std::get<1>(data)->setColor(gd::Color(255, 255, 255, 150));
                            std::get<2>(data)->setColor(gd::Color(255, 255, 255, 150));
                        }
                        _save->setPosition({(int)(coord.x + _innerPadding), (int)(window.y - _save->getSize().y - _innerPadding)});
                        _save->setColor(gd::Color(255, 255, 255, 150));
                    }

                    bool SoundsMiniScene::handleEvent(gd::Event &event)
                    {
                        if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelected(-1);
                        if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelected(1);
                        if (event.joyStick().isConnected()) {
                            if (event.joyStick().getYAxisPosition(false) < -50) _moveSelected(-1);
                            if (event.joyStick().getYAxisPosition(true) > 50) _moveSelected(1);
                        }
                        if (_selected < (int)_datas.size()) {
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

                    void SoundsMiniScene::draw(gd::Window &window)
                    {
                        for (auto &data : _datas) {
                            std::get<1>(data)->draw(window);
                            std::get<2>(data)->draw(window);
                        }
                        _save->draw(window);
                    }

                    void SoundsMiniScene::_changeRangeValue(int value)
                    {
                        if (_input.getElapsedTime() < 100) return;
                        _input.reset();
                        if (value < 0)
                            std::get<2>(_datas[_selected])->downValue();
                        else
                            std::get<2>(_datas[_selected])->upValue();
                        std::string text = Traductor::get()->translate(std::get<0>(_datas[_selected]));
                        text.replace(text.find("{value}"), 7, std::to_string((int)(std::get<2>(_datas[_selected])->getValue())));
                        std::get<1>(_datas[_selected])->setText(text);
                        if (std::get<0>(_datas[_selected]) == "settings.sound") {
                            RType::Game::Managers::Sound::get().setVolume(std::get<2>(_datas[0])->getValue());
                            RType::Game::Managers::Sound::get().play("beep");
                        } else if (std::get<0>(_datas[_selected]) == "settings.music")
                            RType::Game::Managers::Music::get().setVolume(std::get<2>(_datas[1])->getValue());
                        if (_changes == false) {
                            _changes = true;
                            _save->setText(Traductor::get()->translate("dico.save"));
                        }
                    }

                    void SoundsMiniScene::_moveSelected(int value)
                    {
                        if (_input.getElapsedTime() < 200) return;
                        _input.reset();
                        _selected += value;
                        if (_selected < 0) _selected = 0;
                        if (_selected >= (int)_datas.size()) _selected = (int)_datas.size();

                        for (int i = 0; i < (int)_datas.size(); i++) {
                            std::get<2>(_datas[i])->setColor(gd::Color(255, 255, 255, 150));
                            std::get<1>(_datas[i])->setColor(gd::Color(255, 255, 255, 150));
                        }
                        _save->setColor(gd::Color(255, 255, 255, 150));
                        if (_selected < (int)_datas.size()) {
                            std::get<2>(_datas[_selected])->setColor(gd::Color::White);
                            std::get<1>(_datas[_selected])->setColor(gd::Color::White);
                        } else
                            _save->setColor(gd::Color::White);
                    }

                    void SoundsMiniScene::_saveSettings()
                    {
                        if (_changes == false) return;
                        _changes = false;
                        _save->setText(Traductor::get()->translate("dico.back"));

                        Papaya settings("./assets/data", "settings");
                        settings.updateData("setting", "music", "value", std::to_string((int)std::get<2>(_datas[1])->getValue()));
                        settings.updateData("setting", "sound", "value", std::to_string((int)std::get<2>(_datas[0])->getValue()));
                        settings.save();
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
