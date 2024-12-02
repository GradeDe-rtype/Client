/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_SCENE_INTERFACE_HPP_
#define RTYPE_DISPLAY_SCENE_INTERFACE_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
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
            };
        } // namespace Scene
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_SCENE_INTERFACE_HPP_ */
