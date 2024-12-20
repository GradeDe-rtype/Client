/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SettingsScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void Settings::load(gd::Window &window)
            {
                _loadSettings();
                _links.push_back(std::make_tuple("graphics", std::make_unique<Game::Components::Text>("Karma Future", "Graphics"), std::make_unique<Game::Scenes::MiniScene::Settings::GraphicsMiniScene>()));
                _links.push_back(std::make_tuple("sound", std::make_unique<Game::Components::Text>("Karma Future", "Sound"), std::make_unique<Game::Scenes::MiniScene::Settings::SoundsMiniScene>()));

                for (int i = 0; i < (int)_links.size(); i++) {
                    std::get<1>(_links[i])->setPosition({(int)(_linkSpacing * 1.5), (int)(_linkGap * i + _linkSpacing)});
                    std::get<2>(_links[i])->load({(float)(window.getWidth() / 3 + _linkSpacing), (float)(_linkSpacing)}, {(float)(window.getWidth() / 3 * 2 - _linkSpacing * 2), (float)(window.getHeight() - _linkSpacing * 2)});
                }

                _selectArrow = std::make_unique<Game::Entity::SelectArrow>();
                _selectArrow->setPosition({(float)_linkSpacing, (float)(std::get<1>(_links[_selectIndex])->getPosition().y + std::get<1>(_links[_selectIndex])->getSize().y / 2)});

                _rectangles.push_back(gd::Shape());
                _rectangles.push_back(gd::Shape());

                _rectangles[0].createRectangle((float)(window.getWidth() / 3 - _linkSpacing / 2), (float)(window.getHeight() - _linkSpacing));
                _rectangles[0].setPosition({(float)(_linkSpacing / 2), (float)(_linkSpacing / 2)});
                _rectangles[0].setFillColor(gd::Color::Transparent);
                _rectangles[0].setOutlineColor(gd::Color::White);
                _rectangles[0].setOutlineThickness(4);

                _rectangles[1].createRectangle((float)(window.getWidth() / 3 * 2 - _linkSpacing), (float)(window.getHeight() - _linkSpacing));
                _rectangles[1].setPosition({(float)(window.getWidth() / 3 + _linkSpacing / 2), (float)(_linkSpacing / 2)});
                _rectangles[1].setFillColor(gd::Color::Transparent);
                _rectangles[1].setOutlineColor(gd::Color(255, 255, 255, 150));
                _rectangles[1].setOutlineThickness(4);
            }

            void Settings::draw(gd::Window &window)
            {
                for (auto &link : _links)
                    std::get<1>(link)->draw(window);
                _selectArrow->draw(window);
                window.draw(_rectangles[0]);
                window.draw(_rectangles[1]);
                std::get<2>(_links[_selectIndex])->draw(window);
            }

            std::string Settings::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (_columnIndex == 0) {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelectArrow(-1);
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelectArrow(1);
                }
                if (_columnIndex == 0 || std::get<2>(_links[_selectIndex])->handleEvent(event)) {
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(-1);
                    if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(1);
                }
                if (event.keyBoard().getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (event.joyStick().isConnected()) {
                    if (_columnIndex == 0) {
                        if (event.joyStick().getYAxisPosition(false) < -50) _moveSelectArrow(-1);
                        if (event.joyStick().getYAxisPosition(true) > 50) _moveSelectArrow(1);
                    }
                    if (_columnIndex == 0 || std::get<2>(_links[_selectIndex])->handleEvent(event)) {
                        if (event.joyStick().getXAxisPosition(false) < -50) _moveSelectedColumn(-1);
                        if (event.joyStick().getXAxisPosition(true) > 50) _moveSelectedColumn(1);
                    }
                    if (event.joyStick().getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
                }
                return "";
            }

            void Settings::_moveSelectArrow(int index)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                _selectIndex += index;
                _selectIndex = _selectIndex % (int)_links.size();
                _selectIndex = (_selectIndex < 0) ? (int)_links.size() - 1 : _selectIndex;
                _selectArrow->setPosition({(float)_linkSpacing, (float)(std::get<1>(_links[_selectIndex])->getPosition().y + std::get<1>(_links[_selectIndex])->getSize().y / 2)});
            }

            void Settings::_moveSelectedColumn(int index)
            {
                if (index < 0 and _columnIndex <= 0) return;
                if (index > 0 and _columnIndex >= 1) return;
                _columnIndex += index;

                for (int i = 0; i < (int)_rectangles.size(); i++)
                    _rectangles[i].setOutlineColor((i == _columnIndex) ? gd::Color::White : gd::Color(255, 255, 255, 150));
            }

            void Settings::_loadSettings(void)
            {
                Papaya settings("./assets/data", "settings");
                RType::Game::Managers::Music::get().setVolume(std::stoi(settings.getData("setting", "music", "value")));
                gd::FrameRate::get().setFrameRate(std::stoi(settings.getData("setting", "frameRate", "value")));
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
