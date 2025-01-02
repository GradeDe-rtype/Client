/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_TEXT_HPP_
#define RTYPE_GAME_COMPONENT_TEXT_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "GradeDe/Color.hpp"
#include "GradeDe/Font.hpp"
#include "GradeDe/Text.hpp"
#include "GradeDe/Vector.hpp"
#include "GradeDe/Window.hpp"
#include "Game/Managers/Accessibility/AccessibilityManager.hpp"
#include "Game/Managers/Font/FontManager.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class Text
            {
                public:
                    Text(std::string font, std::string text, float charactersize = 1, gd::Color color = gd::Color::White, gd::Vector2<int> position = {0, 0});
                    ~Text() = default;

                    void reload();
                    void draw(gd::Window &window);

                    void setCharacterSize(int charactersize);
                    void setColor(gd::Color color);
                    void setPosition(gd::Vector2<int> position);
                    void setText(std::string text);

                    int getCharacterSize() const;
                    gd::Color getColor() const;
                    gd::Vector2<int> getPosition() const;
                    gd::Vector2<float> getSize() const;
                    std::string getText() const;

                private:
                    gd::Font _gdFont;
                    gd::Text _gdText;
                    gd::Color _color;
                    std::string _text;
                    float _charactersize;
                    gd::Vector2<int> _position;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_ */
