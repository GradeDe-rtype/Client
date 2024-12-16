/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_Game_SCENE_INTERFACE_HPP_
#define RTYPE_Game_SCENE_INTERFACE_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Scene
        {
            class IScene
            {
                public:
                    /**
                     * @brief Destroy the IScene object
                     */
                    virtual ~IScene() = default;

                    /**
                     * @brief Load the scene
                     *
                     * @param `window` The window
                     */
                    virtual void load(gd::Window &window) = 0;

                    /**
                     * @brief Unload the scene
                     */
                    virtual void unload() = 0;

                    /**
                     * @brief Enter the scene
                     */
                    virtual void enter() = 0;

                    /**
                     * @brief Leave the scene
                     */
                    virtual void leave() = 0;

                    /**
                     * @brief Update the scene
                     *
                     * @param `window` The window
                     * @param `event` The event
                     */
                    virtual std::string handleEvent(gd::Window &window, gd::Event &event) = 0;

                    /**
                     * @brief Draw the scene
                     *
                     * @param `window` The window
                     */
                    virtual void draw(gd::Window &window) = 0;

                    /**
                     * @brief Update the scene
                     */
                    virtual void update(gd::Window &window) = 0;
            };
        } // namespace Scene
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_Game_SCENE_INTERFACE_HPP_ */
