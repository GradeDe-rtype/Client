/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "ResolutionManager.hpp"

namespace RType
{
    namespace Game
    {
        namespace Managers
        {
            Resolution &Resolution::get()
            {
                static Resolution instance;
                return instance;
            }

            void Resolution::updateResolution()
            {
                _currentResolution = _nextResolution;
                _ratio = static_cast<float>(getResolution().first) / 800.0f;
            }

            void Resolution::setResolution(std::string resolution)
            {
                _nextResolution = resolution;
            }

            std::string Resolution::getNextResolution() const
            {
                return _nextResolution;
            }

            std::string Resolution::getCurrentResolution() const
            {
                return _currentResolution;
            }

            std::pair<int, int> Resolution::getResolution() const
            {
                std::pair<int, int> dimension;
                std::vector<std::string> parts = RType::Helpers::Utils::split(_currentResolution, "x");
                dimension.first = std::stoi(parts[0]);
                dimension.second = std::stoi(parts[1]);
                return dimension;
            }

            std::vector<std::string> Resolution::getAvailableResolutions() const
            {
                return _availableResolutions;
            }

            float Resolution::getRatio() const
            {
                return _ratio;
            }
        } // namespace Managers
    } // namespace Game
} // namespace RType