/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ENTITY_SELECT_ARROW_HPP_
#define RTYPE_GAME_COMPONENT_ENTITY_SELECT_ARROW_HPP_

/*  ---- INCLUDES ---- */
#include <unordered_map>
#include "GradeDe/Color.hpp"
#include "Game/Entity/Base/AEntity.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Entity
        {
            class SelectArrow : public AEntity
            {
                public:
                    typedef enum {
                        UP = 270,
                        DOWN = 90,
                        LEFT = 0,
                        RIGHT = 180
                    } Direction;

                    SelectArrow(Direction direction = LEFT, gd::Color color = gd::Color::White, int size = 10, gd::Vector2<float> position = {0, 0});
                    ~SelectArrow() = default;

                    void setColor(std::string color) override;
                    void setColor(gd::Color color) override;
                    void setDirection(Direction direction);

                    Direction getDirection() const;

                private:
                    Direction _direction;
            };
        } // namespace Entity
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ENTITY_SELECT_ARROW_HPP_ */
