/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_GAME_MANAGERS_RESOLUTION_HPP_
#define RTYPE_GAME_MANAGERS_RESOLUTION_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include <utility>
#include "Helpers/Utils/Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            class Resolution
            {
                public:
                    ~Resolution() = default;

                    static Resolution &get();

                    void updateResolution();
                    void setResolution(std::string resolution);

                    std::string getNextResolution() const;
                    std::string getCurrentResolution() const;
                    std::pair<int, int> getResolution() const;

                private:
                    Resolution() = default;
                    std::string _currentResolution = "";
                    std::string _nextResolution = "";
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_RESOLUTION_HPP_ */
