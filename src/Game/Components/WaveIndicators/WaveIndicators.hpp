/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_
#define RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include "Game/Components/Text/Text.hpp"
#include "GradeDe/Color.hpp"
#include "GradeDe/Event.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Ressources.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class WaveIndicators
            {
                public:
                    WaveIndicators(gd::Window &window);
                    ~WaveIndicators() = default;

                    void handleEvent(gd::Window &window, gd::Event &event);
                    void draw(gd::Window &window);
                    void update(gd::Window &window);

                private:
                    int _currentWave = 0;
                    std::unique_ptr<RType::Game::Components::Text> _nextWave;
                    std::unique_ptr<RType::Game::Components::Text> _waveUpgrade;
                    std::unique_ptr<RType::Game::Components::Text> _pressEnter;
                    std::unique_ptr<RType::Game::Components::Text> _waveIndicator;
                    gd::Time _fade;
                    int _opacity = 0;
                    int _fadeSpeed = 20;
                    int _fadeTime = 50;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_ */
