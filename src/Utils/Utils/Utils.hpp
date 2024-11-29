/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_UTILS_HPP_
    #define RTYPE_UTILS_HPP_

    /*  ---- INCLUDES ---- */
    #include <string>
    #include <vector>
    #include <sys/stat.h>


    /*  ---- CLASS ---- */
namespace RType {
    namespace Utils {
        /**
         * @brief Split a string into a vector of strings
         *
         * @param str The string to split
         * @param delimiter The delimiter to split the string with
         *
         * @return A vector of strings
         */
        std::vector<std::string> split(const std::string &str, const std::string &delimiter);

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
    }
}

#endif /* !RTYPE_UTILS_HPP_ */
