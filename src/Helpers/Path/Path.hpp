/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef HELPERS_PATH_HPP_
#define HELPERS_PATH_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include "Helpers/Utils/Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Helpers
    {
        class Path
        {
            public:
                static Path *get();
                std::string path() const;

            private:
                Path();
                ~Path() = default;

                std::string _path;
        };
    } // namespace Helpers
} // namespace RType

#endif /* !HELPERS_PATH_HPP_ */
