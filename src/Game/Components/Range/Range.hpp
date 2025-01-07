/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_RANGE_HPP_
#define RTYPE_GAME_COMPONENT_RANGE_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Color.hpp"
#include "GradeDe/RectangleShape.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Managers/Font/FontManager.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class Range : public AComponent
            {
                public:
                    Range(int start, int end, int step, gd::Vector2<float> position, gd::Vector2<float> size);
                    ~Range() = default;

                    void draw(gd::Window &window) override;
                    void reload(gd::Vector2<float> window);
                    void upValue();
                    void downValue();

                    void setValue(float value);
                    void setValuePercentage(float percentage);
                    void setColor(gd::Color color);
                    void setPosition(gd::Vector2<float> position) override;
                    void setEnd(int end);

                    float getValue() const;
                    gd::Vector2<float> getSize() const;

                private:
                    gd::RectangleShape _range;
                    gd::RectangleShape _background;
                    gd::Vector2<float> _size;
                    int _start;
                    int _end;
                    int _step;
                    float _value;

                    void _setValueWithStep();
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_RANGE_HPP_ */
