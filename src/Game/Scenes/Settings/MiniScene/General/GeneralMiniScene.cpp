/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GeneralMiniScene.hpp"

namespace RType
{
    namespace Game
    {
        namespace Scenes
        {
            namespace MiniScene
            {
                namespace Settings
                {
                    void GeneralMiniScene::load(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;

                        _title = std::make_unique<Game::Components::Text>("Karma Future", "General");
                        _title->setPosition({(int)(coord.x + window.x / 2 - _title->getSize().x / 2), (int)(coord.y + 50)});
                    }

                    bool GeneralMiniScene::handleEvent(gd::Event &event)
                    {
                        return true;
                    }

                    void GeneralMiniScene::draw(gd::Window &window)
                    {
                        _title->draw(window);
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
