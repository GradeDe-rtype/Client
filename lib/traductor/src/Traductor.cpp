/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "Traductor.hpp"

/*  ---- CLASS ---- */
Traductor *Traductor::get()
{
    static Traductor instance;
    return &instance;
}

void Traductor::setLang(std::string lang)
{
    if (_traductions.find(lang) == _traductions.end())
        throw Error("Unknow lang", "setLang");
    _lang = lang;
}

void Traductor::loadLang(std::string filepath, std::string lang)
{
    std::string file = _readFile(filepath);
    file = file.substr(2, file.length() - 4);
    _traductions[lang].parse(file, lang, false);
}

std::string Traductor::translate(std::string key)
{
    try {
        if (_lang == "") throw Error("No language setted", "translate");
        return _traductions.at(_lang).getValue(_split(key, '.'));
    } catch (Error &e) {
        e.read();
    }
    return key;
}

std::string Traductor::getLang(void) const
{
    return _lang;
}

std::vector<std::string> Traductor::getLangs(void) const
{
    std::vector<std::string> langs;
    for (auto &lang : _traductions)
        langs.push_back(lang.first);
    return langs;
}

std::vector<std::string> Traductor::_split(std::string str, char delimiter)
{
    std::vector<std::string> result;
    std::string tmp = "";

    for (char c : str) {
        if (c == delimiter) {
            result.push_back(tmp);
            tmp = "";
        } else
            tmp += c;
    }
    result.push_back(tmp);
    return result;
}

std::string Traductor::_readFile(std::string filepath)
{
    std::ifstream file(filepath, std::ios::in | std::ios::binary);
    if (!file.is_open())
        throw Error("Failed to open file: " + filepath, "loadLang");

    std::ostringstream content;
    content << file.rdbuf();
    return content.str();
}
