/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_STARS_BACKGROUND_HPP_
#define RTYPE_GAME_COMPONENT_STARS_BACKGROUND_HPP_

/*  ---- INCLUDES ---- */
#include <vector>
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Base/AComponent.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class StarsBackground : public AComponent
            {
                public:
                    class Star : public AComponent
                    {
                        public:
                            Star(gd::Window &window, int _x, int _y, int _size, int _speed = 10);
                            ~Star() = default;

                            void setSpeed(int speed);
                            void draw(gd::Window &window) override;
                            void update(gd::Window &window) override;

                        private:
                            gd::Shape _shape;
                            int _size;
                            int _speed = 10;
                    };

                    StarsBackground(gd::Window &window);
                    ~StarsBackground() = default;

                    void update(gd::Window &window) override;
                    void draw(gd::Window &window) override;

                private:
                    std::vector<Star> _stars;
                    gd::Time _updateClock;
                    gd::Time _spawnclock;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_STARS_BACKGROUND_HPP_ */
