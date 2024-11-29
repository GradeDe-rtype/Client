/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

    /*  ---- INCLUDES ---- */
#include "Utils.hpp"


    /*  ---- FUNCTIONS ---- */
namespace RType {
    namespace Utils {
        std::vector<std::string> split(const std::string &str, const std::string &delim)
        {
            if (str.empty())
                return {};
            if (str.find(delim) == std::string::npos)
                return {str};

            std::vector<std::string> tokens;
            std::size_t start = 0;

            while (true) {
                std::size_t end = str.find(delim, start);
                if (end == std::string::npos) {
                    tokens.push_back(str.substr(start));
                    break;
                }
                tokens.push_back(str.substr(start, end - start));
                start = end + delim.size();
                while (delim.find(str[start]) != std::string::npos && start < str.size())
                    start++;
            }
            return tokens;
        }

        bool DirectoryExists(const char *path)
        {
            struct stat info;

            if (stat(path, &info) != 0)
                return false;
            else if (info.st_mode & S_IFDIR)
                return true;
            return false;
        }

        bool isNumber(const std::string &str)
        {
            for (const auto &c : str)
                if (!std::isdigit(c) && c != '-')
                    return false;
            return true;
        }
    }
}