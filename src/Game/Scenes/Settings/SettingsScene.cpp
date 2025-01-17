/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "SettingsScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Accessibility/AccessibilityMiniScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Graphics/GraphicsMiniScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Languages/LanguagesMiniScene.hpp"
#include "Game/Scenes/Settings/MiniScene/Sounds/SoundsMiniScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void Settings::load(gd::Window &window)
            {
                _links.push_back(std::make_tuple("dico.accessibility", std::make_unique<RType::Game::Components::TextBox>(window.getWidth() / 5 * 2 - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("dico.accessibility")), std::make_unique<RType::Game::Scenes::MiniScene::Settings::AccessibilityMiniScene>()));
                _links.push_back(std::make_tuple("dico.graphic", std::make_unique<RType::Game::Components::TextBox>(window.getWidth() / 5 * 2 - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("dico.graphic")), std::make_unique<RType::Game::Scenes::MiniScene::Settings::GraphicsMiniScene>()));
                _links.push_back(std::make_tuple("dico.language", std::make_unique<RType::Game::Components::TextBox>(window.getWidth() / 5 * 2 - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("dico.language")), std::make_unique<RType::Game::Scenes::MiniScene::Settings::LanguagesMiniScene>()));
                _links.push_back(std::make_tuple("dico.sound", std::make_unique<RType::Game::Components::TextBox>(window.getWidth() / 5 * 2 - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("dico.sound")), std::make_unique<RType::Game::Scenes::MiniScene::Settings::SoundsMiniScene>()));

                int h = _linkSpacing;
                for (auto &link : _links) {
                    std::get<1>(link)->setPosition({(float)(_linkSpacing * 1.5), (float)h});
                    h += _linkGap + std::get<1>(link)->getSize().y;
                    std::get<2>(link)->load({(float)(window.getWidth() / 5 * 2 + _linkSpacing), (float)(_linkSpacing)}, {(float)(window.getWidth() / 5 * 3 - _linkSpacing * 2), (float)(window.getHeight() - _linkSpacing * 2)});
                }

                _selectArrow = std::make_unique<RType::Game::Entity::SelectArrow>();
                _selectArrow->setPosition({(float)_linkSpacing, (float)(std::get<1>(_links[_selectIndex])->getPosition().y + std::get<1>(_links[_selectIndex])->getSize().y / 2)});

                _rectangles.push_back(gd::RectangleShape());
                _rectangles.push_back(gd::RectangleShape());

                _rectangles[0].create(gd::Vector2<float>((float)(window.getWidth() / 5 * 2 - _linkSpacing / 2), (float)(window.getHeight() - _linkSpacing)));
                _rectangles[0].setPosition({(float)(_linkSpacing / 2), (float)(_linkSpacing / 2)});
                _rectangles[0].setFillColor(gd::Color::Transparent);
                _rectangles[0].setOutlineColor(gd::Color::White);
                _rectangles[0].setOutlineThickness(4);

                _rectangles[1].create(gd::Vector2<float>((float)(window.getWidth() / 5 * 3 - _linkSpacing), (float)(window.getHeight() - _linkSpacing)));
                _rectangles[1].setPosition({(float)(window.getWidth() / 5 * 2 + _linkSpacing / 2), (float)(_linkSpacing / 2)});
                _rectangles[1].setFillColor(gd::Color::Transparent);
                _rectangles[1].setOutlineColor(gd::Color(255, 255, 255, 150));
                _rectangles[1].setOutlineThickness(4);
            }

            void Settings::reload(gd::Window &window)
            {
                int h = _linkSpacing;
                for (auto &link : _links) {
                    std::get<1>(link)->setText(Traductor::get()->translate(std::get<0>(link)));
                    std::get<1>(link)->setPosition({(float)(_linkSpacing * 1.5), (float)h});
                    h += _linkGap + std::get<1>(link)->getSize().y;
                    std::get<2>(link)->reload({(float)(window.getWidth() / 5 * 2 + _linkSpacing), (float)(_linkSpacing)}, {(float)(window.getWidth() / 5 * 3 - _linkSpacing * 2), (float)(window.getHeight() - _linkSpacing * 2)});
                }
                _selectArrow->setPosition({(float)_linkSpacing, (float)(std::get<1>(_links[_selectIndex])->getPosition().y + std::get<1>(_links[_selectIndex])->getSize().y / 2)});
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
                gd::Vector2<float> mouse = event.mouse.getPosition(window);
                for (int i = 0; i < (int)_rectangles.size(); i++) {
                    gd::Vector2<float> pos = _rectangles[i].getPosition();
                    gd::Vector2<float> size = _rectangles[i].getSize();
                    if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y && event.mouse.hasMove(window))
                        _moveSelectedColumn(i - _columnIndex);
                }

                if (_columnIndex == 0) {
                    if (event.joyStick.isConnected()) {
                        if (event.joyStick.getYAxisPosition(false) < -50) _moveSelectArrow(-1);
                        if (event.joyStick.getYAxisPosition(true) > 50) _moveSelectArrow(1);
                    }
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Up) == gd::KeyBoard::State::Pressed) _moveSelectArrow(-1);
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Down) == gd::KeyBoard::State::Pressed) _moveSelectArrow(1);
                    for (int i = 0; i < (int)_links.size(); i++) {
                        gd::Vector2<float> pos = std::get<1>(_links[i])->getPosition();
                        gd::Vector2<float> size = std::get<1>(_links[i])->getSize();
                        if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y && mouse.y <= pos.y + size.y && event.mouse.hasMove(window)) {
                            _selectIndex = i;
                            _selectArrow->setPosition({(float)_linkSpacing, (float)(std::get<1>(_links[_selectIndex])->getPosition().y + std::get<1>(_links[_selectIndex])->getSize().y / 2)});
                        }
                    }
                }
                if (_columnIndex == 0 || std::get<2>(_links[_selectIndex])->handleEvent(window, event)) {
                    if (event.joyStick.isConnected()) {
                        if (event.joyStick.getXAxisPosition(false) < -50) _moveSelectedColumn(-1);
                        if (event.joyStick.getXAxisPosition(true) > 50) _moveSelectedColumn(1);
                    }
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Left) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(-1);
                    if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Right) == gd::KeyBoard::State::Pressed) _moveSelectedColumn(1);
                }
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Escape) == gd::KeyBoard::State::Released) return "menu";
                if (std::get<2>(_links[_selectIndex])->changeScene()) return "menu";
                if (event.joyStick.isConnected() && event.joyStick.getButtonState(gd::JoyStick::Button::Home) == gd::JoyStick::State::Released) return "menu";
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
        } // namespace Scenes
    } // namespace Game
} // namespace RType
