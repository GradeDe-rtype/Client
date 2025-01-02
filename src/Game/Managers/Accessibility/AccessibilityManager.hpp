/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_ACCESSIBILITY_HPP_
#define RTYPE_GAME_MANAGERS_ACCESSIBILITY_HPP_

/*  ---- INCLUDES ---- */

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Accessibility
            {
                public:
                    ~Accessibility() = default;

                    static Accessibility &get();

                    void setTextSize(int size);

                    int getTextSize() const;

                private:
                    Accessibility() = default;
                    int textSize = 30;
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_ACCESSIBILITY_HPP_ */
