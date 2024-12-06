/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_SCENE_GAME_HPP_
#define RTYPE_DISPLAY_SCENE_GAME_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "AScene.hpp"
#include "GradeDe/Event.hpp"
#include "GradeDe/Window.hpp"
#include "Ressources.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
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
                     * @brief Unload the scene
                     */
                    void unload() override;

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
                    void update() override;
            };
        } // namespace Scene
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_SCENE_GAME_HPP_ */
