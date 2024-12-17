/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_STAR_RATING_HPP_
#define RTYPE_GAME_COMPONENT_STAR_RATING_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <vector>
#include "GradeDe/Window.hpp"
#include "Ressources.hpp"
#include "Star.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class StarRating
            {
                public:
                    StarRating(gd::Window &window);
                    ~StarRating() = default;

                    void draw(gd::Window &window);
                    void update(gd::Window &window);

                private:
                    int _currentRating = -1;
                    std::vector<std::unique_ptr<RType::Game::Entity::Star>> _stars;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_STAR_RATING_HPP_ */
