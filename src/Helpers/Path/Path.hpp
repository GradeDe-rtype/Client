/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_HELPERS_PATH_HPP_
#define RTYPE_HELPERS_PATH_HPP_

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

#endif /* !RTYPE_HELPERS_PATH_HPP_ */
