/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_DISPLAY_COMPONENT_STARS_BACKGROUND_HPP_
#define RTYPE_DISPLAY_COMPONENT_STARS_BACKGROUND_HPP_

/*  ---- INCLUDES ---- */
#include <vector>
#include "GradeDe/Shape.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Window.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Display
    {
        namespace Components
        {
            class StarsBackground
            {
                public:
                    class Star
                    {
                        public:
                            Star(gd::Window &window, int _x, int _y, int _size, int _speed = 10);
                            ~Star() = default;

                            void update();
                            void setSpeed(int speed);
                            void draw(gd::Window &window);

                            gd::Vector2<float> getPosition() const;

                        private:
                            gd::Shape _shape;
                            gd::Vector2<float> _position;
                            int _size;
                            int _speed = 10;
                    };

                    StarsBackground(gd::Window &window);
                    ~StarsBackground() = default;

                    void update(gd::Window &window);
                    void draw(gd::Window &window);

                private:
                    std::vector<Star> _stars;
                    gd::Time _updateClock;
                    gd::Time _spawnclock;
            };
        } // namespace Components
    } // namespace Display
} // namespace RType

#endif /* !RTYPE_DISPLAY_COMPONENT_STARS_BACKGROUND_HPP_ */
