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
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Managers/Accessibility/AccessibilityManager.hpp"
#include "Game/Managers/Font/FontManager.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class Text : public AComponent
            {
                public:
                    Text(std::string font, std::string text, float charactersize = 1, gd::Color color = gd::Color::White, gd::Vector2<float> position = {0, 0});
                    ~Text() = default;

                    void reload(gd::Window &window) override;
                    void draw(gd::Window &window) override;

                    void setCharacterSize(int charactersize);
                    void setColor(gd::Color color);
                    void setPosition(gd::Vector2<float> position) override;
                    void setText(std::string text);

                    int getCharacterSize() const;
                    gd::Color getColor() const;
                    gd::Vector2<float> getSize() const;
                    std::string getText() const;

                private:
                    gd::Font _gdFont;
                    gd::Text _gdText;
                    gd::Color _color;
                    std::string _text;
                    float _charactersize;
            };
        } // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_WAVE_NOTIF_HPP_ */
