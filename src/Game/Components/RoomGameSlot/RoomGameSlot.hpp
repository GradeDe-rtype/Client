/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_ROOM_GAME_SLOT_HPP_
#define RTYPE_GAME_COMPONENT_ROOM_GAME_SLOT_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <unordered_map>
#include "GradeDe/RectangleShape.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Components/TextBox/TextBox.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class RoomGameSlot : public AComponent
            {
                public:
                    RoomGameSlot(int id, std::unordered_map<std::string, std::string> &datas, float sizeX = 400, gd::Vector2<float> position = {0, 0});
                    ~RoomGameSlot() = default;

                    void draw(gd::Window &window) override;
                    void setPosition(gd::Vector2<float> position) override;
                    void setPosition(float x, float y) override;
                    void setSizeX(float x);
                    void setColor(gd::Color color);

                    gd::Vector2<float> getSize() const;

                private:
                    int _id;
                    gd::Vector2<float> _size;
                    std::unique_ptr<RType::Game::Components::TextBox> _name;
                    std::unique_ptr<RType::Game::Components::TextBox> _players;
                    std::unique_ptr<RType::Game::Components::TextBox> _gameMode;
                    std::unique_ptr<gd::RectangleShape> _background;
                    int _innerPadding = 10;
            };
        }; // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_ROOM_GAME_SLOT_HPP_ */
