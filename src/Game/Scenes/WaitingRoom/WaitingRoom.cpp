/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "WaitingRoom.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            void WaitingRoom::load(gd::Window &window)
            {
                _waitMessage = std::make_unique<RType::Game::Components::TextBox>(window.getWidth() - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("scenes.waitingRoom.waitMessage"), RType::Game::Components::TextBox::Align::Center, 1.8);
                _waitMessage->setPosition({(float)_linkSpacing, (float)(window.getHeight() / 3 - _waitMessage->getSize().y / 2)});
                _pressEnter = std::make_unique<RType::Game::Components::TextBox>(window.getWidth() - _linkSpacing * 2, "Karma Future", Traductor::get()->translate("scenes.waitingRoom.pressEnter"), RType::Game::Components::TextBox::Align::Center);
                _pressEnter->setPosition({(float)_linkSpacing, (float)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});
                _timeout.reset();
            }

            void WaitingRoom::reload(gd::Window &window)
            {
                std::string message = "scenes.waitingRoom.";
                message += (_error ? "errorMessage" : "waitMessage");
                _waitMessage->setText(Traductor::get()->translate(message));
                _waitMessage->setPosition({(float)_linkSpacing, (float)(window.getHeight() / (_error ? 3 : 2) - _waitMessage->getSize().y / 2)});
                _pressEnter->setText(Traductor::get()->translate("scenes.waitingRoom.pressEnter"));
                _pressEnter->setPosition({(float)_linkSpacing, (float)(window.getHeight() / 3 * 2 - _pressEnter->getSize().y / 2)});
            }

            void WaitingRoom::enter(gd::Window &window)
            {
                _timeout.reset();
                _error = false;
                reload(window);
            }

            std::string WaitingRoom::handleEvent(gd::Window &window, gd::Event &event)
            {
                if (!_error) return "";
                if (event.keyBoard.getKeyState(gd::KeyBoard::Key::Enter) == gd::KeyBoard::State::Released) return "roomsList";
                if (event.joyStick.isConnected() && event.joyStick.getButtonState(gd::JoyStick::Button::A) == gd::JoyStick::State::Released) return "roomsList";
                return "";
            }

            void WaitingRoom::draw(gd::Window &window)
            {
                _waitMessage->draw(window);
                if (_error) _pressEnter->draw(window);
            }

            void WaitingRoom::update(gd::Window &window)
            {
                if (_timeout.getElapsedTime() >= _timeoutValue && !_error) {
                    _error = true;
                    reload(window);
                }
            }
        } // namespace Scenes
    } // namespace Game
} // namespace RType
