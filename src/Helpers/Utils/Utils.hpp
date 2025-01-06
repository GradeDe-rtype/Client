/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_HELPERS_UTILS_HPP_
#define RTYPE_HELPERS_UTILS_HPP_

/*  ---- INCLUDES ---- */
#include <algorithm>
#include <string>
#include <sys/stat.h>
#include <vector>

/*  ---- CLASS ---- */
namespace RType
{
    namespace Helpers
    {
        namespace Utils
        {
            /**
             * @brief Split a string into a vector of strings
             *
             * @param str The string to split
             * @param delimiter The delimiter to split the string with
             *
             * @return A vector of strings
             */
            std::vector<std::string> split(const std::string &str, const std::string &delimList);

            /**
             * @brief Check if a directory exists
             *
             * @param path The path to the directory
             *
             * @return true if the directory exists, false otherwise
             */
            bool DirectoryExists(const char *path);

            /**
             * @brief Check if a string is made of only numbers
             *
             * @param str The string to check
             *
             * @return `true` if the string is made of only numbers, `false` otherwise
             */
            bool isNumber(const std::string &str);

            /**
             * @brief Check if a string is an IP adress
             *
             * @param str The string to check
             *
             * @return `true` if the string is an IP adress, `false` otherwise
             */
            bool isIpAdress(const std::string &str);

            /**
             * @brief Trim a string
             *
             * @param str The string to trim
             *
             * @return The trimmed string
             */
            std::string trim(const std::string &str);
        } // namespace Utils
    } // namespace Helpers
} // namespace RType

#endif /* !RTYPE_HELPERS_UTILS_HPP_ */
