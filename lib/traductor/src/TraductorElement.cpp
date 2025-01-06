/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "Traductor.hpp"

/*  ---- CLASS ---- */
void Traductor::TraductorElement::parse(std::string content, std::string key, bool valueMode)
{
    _key = key;

    if (valueMode) {
        _value = content;
        return;
    }

    for (int i = 0; i < (int)content.length(); i++) {
        if (content[i] != '"') continue;
        std::string name = _extract(&content[i], '"', '"');
        for (i += name.length() + 2; content[i] != '"' && content[i] != '{'; i++)
            ;
        std::string tmp = _extract(&content[i], content[i], content[i] == '"' ? '"' : '}');
        bool valueMode = content[i] == '"';
        i += tmp.length() + 1;
        _elements[name].parse(tmp, name, valueMode);
    }
}

std::string Traductor::TraductorElement::getValue(std::vector<std::string> keys)
{
    if (_value != "")
        return _value;
    for (auto elem : _elements) {
        if (elem.first == keys[0]) {
            std::string key = keys[0];
            keys.erase(keys.begin());
            return _elements.at(key).getValue(keys);
        }
    }
    throw Traductor::Error("No key \"" + keys[0] + "\" in \"" + _key + "\"", "translate");
}

std::string Traductor::TraductorElement::_extract(std::string str, const char start, const char end) const
{
    std::string result;
    int startsCount = 0;

    for (int i = 0; i < (int)str.length(); i++) {
        char c = str[i];
        if (c == end && startsCount > 0) {
            startsCount--;
            if (startsCount == 0)
                return result;
            else
                result += c;
        } else if (c == start) {
            if (startsCount > 0)
                result += c;
            startsCount++;
        } else {
            if (startsCount > 0) {
                result += c;
                if (c == '\\') {
                    result += str[i + 1];
                    i++;
                }
            }
        }
    }
    return result;
}
