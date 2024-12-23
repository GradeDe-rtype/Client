/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_END_INDICATOR_HPP_
#define RTYPE_GAME_COMPONENT_END_INDICATOR_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include "GradeDe/Color.hpp"
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Ressources/Ressources.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class EndIndicator
            {
                public:
                    EndIndicator(gd::Window &window);
                    ~EndIndicator() = default;

                    void handleEvent(gd::Window &window, gd::Event &event);
                    void draw(gd::Window &window);
                    void update(gd::Window &window);
                    void reload(gd::Window &window);

                private:
                    int _endScore = 0;
                    std::unique_ptr<RType::Game::Components::Text> _endText;
                    std::unique_ptr<RType::Game::Components::Text> _scoreText;
                    std::unique_ptr<RType::Game::Components::Text> _pressEnter;
                    gd::Time _fade;
                    int _opacity = 0;
                    int _fadeSpeed = 20;
                    int _fadeTime = 50;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_END_INDICATOR_HPP_ */
