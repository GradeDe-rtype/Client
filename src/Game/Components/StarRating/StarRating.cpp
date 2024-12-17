/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "StarRating.hpp"

namespace RType
{
    namespace Game
    {
        namespace Components
        {
            StarRating::StarRating(gd::Window &window)
            {
                for (int i = 0; i < 5; i++) {
                    _stars.push_back(std::make_unique<RType::Game::Entity::Star>());
                    _stars[i]->setPosition({(int)(window.getWidth() / 2 - _stars[i]->getSize() / 2) + i * 100, (int)(window.getHeight() / 2 - _stars[i]->getSize() / 2)});
                }
            }

            void StarRating::draw(gd::Window &window)
            {
                for (auto &star : _stars)
                    window.draw(star->shape());
            }

            void StarRating::update(gd::Window &window)
            {
                if (_currentRating != RType::Ressources::get()->endScore) {
                    _currentRating = RType::Ressources::get()->endScore;
                    for (int i = 0; i < 5; i++) {
                        if (i < _currentRating)
                            _stars[i]->setColor(gd::Color::Yellow);
                        else
                            _stars[i]->setColor(gd::Color::Transparent);
                    }
                }
            }
        } // namespace Components
    } // namespace Game
} // namespace RType
