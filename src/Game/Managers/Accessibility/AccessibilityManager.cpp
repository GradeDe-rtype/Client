/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "AccessibilityManager.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Accessibility &Accessibility::get()
            {
                static Accessibility instance;
                return instance;
            }

            void Accessibility::setTextSize(int size)
            {
                textSize = size;
            }

            int Accessibility::getTextSize() const
            {
                return textSize;
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType