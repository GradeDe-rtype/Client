/*
    Authors:
    >> Caroline Boilly @Aeliondw
    >> Nathan Tirolf @dragusheen

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ABSTRACT_HPP_
#define RTYPE_GAME_COMPONENT_ABSTRACT_HPP_

#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "GradeDe/Event.hpp"
#include "Game/Components/Base/IComponent.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class AComponent : public IComponent
            {
                public:
                    AComponent() = default;
                    ~AComponent() = default;

                    void draw(gd::Window &window) override;
                    void update(gd::Window &window) override;
                    void reload(gd::Window &window) override;
                    void handleEvent(gd::Window &window, gd::Event &event) override;

                    void setPosition(float x, float y) override;
                    void setPosition(gd::Vector2<float> position) override;
                    void setX(float x) override;
                    void setY(float y) override;

                    gd::Vector2<float> getPosition() const override;
                    float getX() const override;
                    float getY() const override;

                protected:
                    gd::Vector2<float> _position;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif // RTYPE_GAME_COMPONENT_INTERFACE_HPP_