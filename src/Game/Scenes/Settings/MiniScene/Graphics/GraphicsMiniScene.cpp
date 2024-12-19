/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "GraphicsMiniScene.hpp"

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
                    void GraphicsMiniScene::load(gd::Vector2<float> coord, gd::Vector2<float> window)
                    {
                        _coord = coord;
                        _window = window;

                        _title = std::make_unique<Game::Components::Text>("Karma Future", "Graphics");
                        _title->setPosition({(int)(coord.x + window.x / 2 - _title->getSize().x / 2), (int)(coord.y + 50)});
                    }

                    bool GraphicsMiniScene::handleEvent(gd::Event &event)
                    {
                        return true;
                    }

                    void GraphicsMiniScene::draw(gd::Window &window)
                    {
                        _title->draw(window);
                    }
                } // namespace Settings
            } // namespace MiniScene
        } // namespace Scenes
    } // namespace Game
} // namespace RType
