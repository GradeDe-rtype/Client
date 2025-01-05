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
                    std::vector<std::string> getAvailableResolutions() const;
                    float getRatio() const;

                private:
                    Resolution() = default;
                    std::string _currentResolution = "";
                    std::string _nextResolution = "";
                    std::vector<std::string> _availableResolutions = {
                        "640x480",
                        "800x600",
                        "960x720",
                        "1024x768",
                        "1280x960",
                        "1400x1050",
                        "1440x1080",
                        "1600x1200",
                        "1856x1392",
                        "1920x1440",
                        "2048x1536"};
                    float _ratio = 1.0f;
            };
        } // namespace Managers
    } // namespace Game
} // namespace RType

#endif /* !RTYPE_GAME_MANAGERS_RESOLUTION_HPP_ */
