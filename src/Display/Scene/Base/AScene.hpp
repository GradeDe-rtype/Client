/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_SCENE_ABSTRACT_HPP_
#define RTYPE_DISPLAY_SCENE_ABSTRACT_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Event.hpp"
#include "GradeDe/Window.hpp"
#include "IScene.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        namespace Scene
        {
            class AScene : public IScene
            {
                public:
                    /**
                     * @brief Construct a new AScene object
                     */
                    AScene() = default;

                    /**
                     * @brief Destroy the IScene object
                     */
                    ~AScene() override = default;

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
                     * @brief Enter the scene
                     */
                    void enter() override;

                    /**
                     * @brief Leave the scene
                     */
                    void leave() override;

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

#endif /* !RTYPE_DISPLAY_SCENE_ABSTRACT_HPP_ */
