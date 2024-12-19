/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_SCENE_GAME_HPP_
#define RTYPE_Game_SCENE_GAME_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Music.hpp"
#include "GradeDe/Sound.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/EndIndicator/EndIndicator.hpp"
#include "Game/Components/WaveIndicators/WaveIndicators.hpp"
#include "Game/Scene/Base/AScene.hpp"
#include "Ressources/Ressources.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scene
        {
            class Game : public AScene
            {
                public:
                    /**
                     * @brief Construct a new AScene object
                     */
                    Game() = default;

                    /**
                     * @brief Destroy the IScene object
                     */
                    ~Game() override = default;

                    /**
                     * @brief Load the scene
                     *
                     * @param `window` The window
                     */
                    void load(gd::Window &window) override;

                    /**
                     * @brief Update the scene
                     *
                     * @param `window` The window
                     * @param `event` The event
                     */
                    std::string handleEvent(gd::Window &window, gd::Event &event) override;

                    /**
                     * @brief Draw the scene
                     *
                     * @param `window` The window
                     */
                    void draw(gd::Window &window) override;

                    /**
                     * @brief Update the scene
                     */
                    void update(gd::Window &window) override;

                private:
                    std::unique_ptr<RType::Game::Components::WaveIndicators> _waveIndicators;
                    std::unique_ptr<RType::Game::Components::EndIndicator> _endIndicator;
            };
        } // namespace Scene
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_SCENE_GAME_HPP_ */
