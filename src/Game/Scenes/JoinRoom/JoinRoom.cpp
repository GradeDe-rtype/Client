/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "JoinRoom.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void JoinRoom::load(gd::Window &window)
            {
                for (int i = 0; i < _codeSize; i++)
                    _code += "- ";
                _code.pop_back();
                _codePreview = std::make_unique<RType::Game::Components::TextBox>(window.getWidth() - _linkSpacing * 2, "Karma Future", _code, RType::Game::Components::TextBox::Align::Center, 1.8);
                _codePreview->setPosition({(float)_linkSpacing, (float)(window.getHeight() / 2 - _codePreview->getSize().y / 2)});
                _input.reset();
            }

            void JoinRoom::reload(gd::Window &window)
            {
                _codePreview->setText(_code);
                _codePreview->setPosition({(float)_linkSpacing, (float)(window.getHeight() / 2 - _codePreview->getSize().y / 2)});
                _input.reset();
            }

            void JoinRoom::enter(gd::Window &window)
            {
                _code.clear();
                for (int i = 0; i < _codeSize; i++)
                    _code += "- ";
                _code.pop_back();
                reload(window);
                _input.reset();
            }

            std::string JoinRoom::handleEvent(gd::Window &window, gd::Event &event)
            {
                for (int i = gd::KeyBoard::Key::Num0; i <= gd::KeyBoard::Key::Num9; i++)
                    if (event.keyBoard.getKeyState((gd::KeyBoard::Key)i) == gd::KeyBoard::State::Pressed) _updateCode(window, '0' + i - gd::KeyBoard::Key::Num0);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::BackSpace) == gd::KeyBoard::State::Pressed) _deleteCode(window);
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Released) return _validateCode(window);
                return "";
            }

            void JoinRoom::draw(gd::Window &window)
            {
                _codePreview->draw(window);
            }

            void JoinRoom::_updateCode(gd::Window &window, char c)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                if (_codeIndex >= _code.size()) return;
                int _trueIndex = 0;
                for (int i = 0; i < _codeIndex; i++, _trueIndex += 2)
                    ;
                _code[_trueIndex] = c;
                _codeIndex++;
                reload(window);
            }

            void JoinRoom::_deleteCode(gd::Window &window)
            {
                if (_input.getElapsedTime() < 200) return;
                _input.reset();

                if (_codeIndex <= 0) return;
                _codeIndex--;
                int _trueIndex = 0;
                for (int i = 0; i < _codeIndex; i++, _trueIndex += 2)
                    ;
                _code[_trueIndex] = '-';
                reload(window);
            }

            std::string JoinRoom::_validateCode(gd::Window &window)
            {
                if (_input.getElapsedTime() < 200) return "";
                _input.reset();

                if (_codeIndex < _codeSize) return "";
                int intCode = 0;
                for (int i = 0; i < _code.size(); i++) {
                    if (_code[i] < '0' || _code[i] > '9') continue;
                    intCode = intCode * 10 + (_code[i] - '0');
                }
                RType::Ressources::get()->sendList->push("join " + std::to_string(intCode));
                return "waitingRoom";
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
