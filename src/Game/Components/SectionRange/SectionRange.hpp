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
#include "GradeDe/Time.hpp"
#include "Game/Components/Base/AComponent.hpp"
#include "Game/Components/Range/Range.hpp"
#include "Game/Components/Text/Text.hpp"
#include "Game/Managers/Scenes/Scenes.hpp"
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

                    virtual gd::Vector2<float> getSize() const = 0;
                    virtual float getSizeX() const = 0;
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
                    void reload(gd::Vector2<float> window);
                    bool handleEvt(gd::Window &window, gd::Event &event);

                    void setPosition(gd::Vector2<float> position) override;
                    void setColor(gd::Color color) override;
                    void setTextValue() override;
                    void setSettingValue() override;

                    gd::Vector2<float> getSize() const override;
                    float getSizeX() const override;
                    float getSizeY() const override;
                    float getValue() const override;
                    std::string getName() const override;
                    std::shared_ptr<RType::Game::Components::Range> range() override;
                    std::string saveValue() const override;

                protected:
                    std::string _name;
                    std::shared_ptr<RType::Game::Components::Text> _text;
                    std::shared_ptr<RType::Game::Components::Range> _range;
                    gd::Time _input;

                    void _changeRangeValue(int value);
            };
        }; // namespace Components
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_COMPONENT_SECTION_RANGE_HPP_ */
