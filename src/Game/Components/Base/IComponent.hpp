/*
    Authors:
    >> Caroline Boilly @Aeliondw
    >> Nathan Tirolf @dragusheen

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_INTERFACE_HPP_
#define RTYPE_GAME_COMPONENT_INTERFACE_HPP_

#include "GradeDe/Color.hpp"
#include "GradeDe/Event.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class IComponent
            {
                public:
                    virtual ~IComponent() = default;

                    virtual void draw(gd::Window &window) = 0;
                    virtual void update(gd::Window &window) = 0;
                    virtual void reload(gd::Window &window) = 0;
                    virtual void handleEvent(gd::Window &window, gd::Event &event) = 0;

                    virtual void setPosition(float x, float y) = 0;
                    virtual void setPosition(gd::Vector2<float> position) = 0;
                    virtual void setX(float x) = 0;
                    virtual void setY(float y) = 0;

                    virtual gd::Vector2<float> getPosition() const = 0;
                    virtual float getX() const = 0;
                    virtual float getY() const = 0;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif // RTYPE_GAME_COMPONENT_INTERFACE_HPP_