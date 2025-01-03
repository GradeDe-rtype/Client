/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_COMPONENT_SECTION_RANGE_HPP_
#define RTYPE_GAME_COMPONENT_SECTION_RANGE_HPP_

/*  ---- INCLUDES ---- */
#include <memory>
#include <string>
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Components/Range/Range.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Traductor.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Components
        {
            class ISectionRange : public AComponent
            {
                public:
                    virtual ~ISectionRange() = default;

                    virtual void setColor(gd::Color color) = 0;
                    virtual void setTextValue() = 0;
                    virtual void setSettingValue() = 0;

                    virtual float getSizeY() const = 0;
                    virtual float getValue() const = 0;
                    virtual std::string getName() const = 0;
                    virtual std::shared_ptr<RType::Game::Components::Range> range() = 0;
                    virtual std::string saveValue() const = 0;
            };

            class SectionRange : public ISectionRange
            {
                public:
                    SectionRange(std::string name, gd::Vector2<float> size, int start = 0, int end = 100, int step = 2);
                    ~SectionRange() = default;

                    void draw(gd::Window &window) override;

                    void setPosition(gd::Vector2<float> position) override;
                    void setColor(gd::Color color) override;
                    void setTextValue() override;
                    void setSettingValue() override;

                    float getSizeY() const override;
                    float getValue() const override;
                    std::string getName() const override;
                    std::shared_ptr<RType::Game::Components::Range> range() override;
                    std::string saveValue() const override;

                protected:
                    std::string _name;
                    std::shared_ptr<RType::Game::Components::Text> _text;
                    std::shared_ptr<RType::Game::Components::Range> _range;
            };
        }; // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_SECTION_RANGE_HPP_ */
