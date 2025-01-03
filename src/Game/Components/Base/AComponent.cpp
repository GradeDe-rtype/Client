/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "AComponent.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            void AComponent::draw(gd::Window &window)
            {
                (void)window;
            }

            void AComponent::update(gd::Window &window)
            {
                (void)window;
            }

            void AComponent::reload(gd::Window &window)
            {
                (void)window;
            }

            void AComponent::handleEvent(gd::Window &window, gd::Event &event)
            {
                (void)window;
                (void)event;
            }

            void AComponent::setPosition(gd::Vector2<float> position)
            {
                _position = position;
            }

            void AComponent::setPosition(float x, float y)
            {
                setPosition(gd::Vector2<float>(x, y));
            }

            void AComponent::setX(float x)
            {
                _position.x = x;
                setPosition(_position);
            }

            void AComponent::setY(float y)
            {
                _position.y = y;
                setPosition(_position);
            }

            gd::Vector2<float> AComponent::getPosition() const
            {
                return _position;
            }

            float AComponent::getX() const
            {
                return _position.x;
            }

            float AComponent::getY() const
            {
                return _position.y;
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
