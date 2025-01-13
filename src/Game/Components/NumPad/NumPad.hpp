/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_Num_Pad_HPP_
#define RTYPE_GAME_COMPONENT_Num_Pad_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Color.hpp"
#include "GradeDe/Time.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Components/TextBox/TextBox.hpp"
#include "Game/Managers/Font/FontManager.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class NumPad : public AComponent
            {
                public:
                    NumPad(gd::Vector2<float> size, gd::Vector2<float> position = {0, 0});
                    ~NumPad() = default;

                    void draw(gd::Window &window) override;
                    void handleEvent(gd::Window &window, gd::Event &event) override;
                    void reload(gd::Window &window) override;
                    void setPosition(gd::Vector2<float> position) override;

                    gd::Vector2<float> getSize() const;
                    char getInput() const;

                private:
                    int _gap = 25;
                    gd::Vector2<float> _size;
                    std::vector<std::vector<std::shared_ptr<RType::Game::Components::TextBox>>> _numPad;
                    char _input = 0;
                    gd::Vector2<int> _index = {1, 3};
                    gd::Time _inputTime;

                    void _updateIndex(gd::Vector2<int> index);
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_Num_Pad_HPP_ */
