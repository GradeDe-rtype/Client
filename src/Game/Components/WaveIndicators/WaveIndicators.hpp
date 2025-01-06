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
            class WaveIndicators : public AComponent
            {
                public:
                    WaveIndicators(gd::Window &window);
                    ~WaveIndicators() = default;

                    void handleEvent(gd::Window &window, gd::Event &event) override;
                    void draw(gd::Window &window) override;
                    void update(gd::Window &window) override;
                    void reload(gd::Window &window) override;

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
