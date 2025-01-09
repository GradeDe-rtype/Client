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
#include "Game/Components/Base/AComponent.hpp"
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
            class EndIndicator : public AComponent
            {
                public:
                    EndIndicator(gd::Window &window);
                    ~EndIndicator() = default;

                    void handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;
                    void update(gd::Window &window) override;
                    void reload(gd::Window &window) override;

                private:
                    bool _endWin = false;
                    std::unique_ptr<RType::Game::Components::Text> _endText;
                    std::unique_ptr<RType::Game::Components::Text> _wavesCompleted;
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
