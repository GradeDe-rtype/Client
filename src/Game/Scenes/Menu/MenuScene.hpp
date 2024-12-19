/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_SCENE_MENU_HPP_
#define RTYPE_GAME_SCENE_MENU_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Music.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Scenes/Base/AScene.hpp"
#include "Ressources/Ressources.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            class Menu : public AScene
            {
                public:
                    /**
                     * @brief Construct a new AScene object
                     */
                    Menu() = default;

                    /**
                     * @brief Destroy the IScene object
                     */
                    ~Menu() override = default;

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

                private:
                    std::unique_ptr<RType::Game::Components::Text> _text;
            };
        } // namespace Scenes
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_SCENE_MENU_HPP_ */
