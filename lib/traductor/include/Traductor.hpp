/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef TRADUCTOR_LIBRARY_HPP_
#define TRADUCTOR_LIBRARY_HPP_

/*  ---- INCLUDES ---- */
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

/*  ---- CLASS ---- */
class Traductor
{
    public:
        class Error : public std::exception
        {
            public:
                Error(const std::string &what, const std::string &where = "");
                ~Error() = default;
                const char *what() const noexcept override;
                const std::string &where() const noexcept;
                void read() const noexcept;

            private:
                std::string _what;
                std::string _where;
        };

        class TraductorElement
        {
            public:
                TraductorElement() = default;
                ~TraductorElement() = default;

                void parse(std::string content, std::string key, bool valueMode);
                std::string getValue(std::vector<std::string> keys);

            private:
                std::string _key;
                std::string _value = "";
                std::unordered_map<std::string, TraductorElement> _elements;
                std::unordered_map<std::string, std::vector<std::string>> _parseLayer(std::string content);
                std::string _extract(std::string str, const char start, const char end) const;
        };

        static Traductor *get();
        ~Traductor() = default;

        void setLang(std::string lang);
        void loadLang(std::string filepath, std::string lang);
        std::string translate(std::string key);
        std::string getLang(void) const;

    private:
        Traductor() = default;
        std::string _lang = "";
        std::unordered_map<std::string, TraductorElement> _traductions;

        std::string _readFile(std::string filepath);
        std::vector<std::string> _split(std::string str, char delimiter);
};

#endif /* TRADUCTOR_LIBRARY_HPP_ */
