/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_TEXT_BOX_HPP_
#define RTYPE_GAME_COMPONENT_TEXT_BOX_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include <vector>
#include "GradeDe/Color.hpp"
#include "GradeDe/Font.hpp"
#include "GradeDe/Text.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Managers/Font/FontManager.hpp"
#include "Helpers/Utils/Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class TextBox
            {
                public:
                    enum Align {
                        Left,
                        Center,
                        Right
                    };

                    TextBox(float max, std::string font, std::string text, Align align = Align::Left, float charactersize = 1, gd::Color color = gd::Color::White, gd::Vector2<int> position = {0, 0});
                    ~TextBox() = default;

                    void reload();
                    void draw(gd::Window &window);

                    void setCharacterSize(int charactersize);
                    void setColor(gd::Color color);
                    void setPosition(gd::Vector2<int> position);
                    void setText(std::string text);
                    void setSize(gd::Vector2<float> size);
                    void setAlign(Align align);

                    int getCharacterSize() const;
                    gd::Color getColor() const;
                    gd::Vector2<int> getPosition() const;
                    gd::Vector2<float> getSize() const;
                    std::string getText() const;
                    Align getAlign() const;

                private:
                    std::string _font;
                    std::vector<std::unique_ptr<Game::Components::Text>> _texts;
                    gd::Color _color;
                    std::string _text;
                    float _charactersize;
                    gd::Vector2<int> _position;
                    gd::Vector2<float> _size;
                    Align _align;

                    void _updateTexts();
                    void _alignTexts();
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_ */
