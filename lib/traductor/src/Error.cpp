/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

/*  ---- INCLUDES ---- */
#include "Traductor.hpp"

/*  ---- CLASS ---- */
Traductor::Error::Error(std::string const &what, std::string const &where)
{
    _what = what;
    _where = where;
}

const char *Traductor::Error::what() const noexcept
{
    return _what.c_str();
}

const std::string &Traductor::Error::where() const noexcept
{
    return _where;
}

void Traductor::Error::read() const noexcept
{
    std::cerr << _what;
    if (_where != "")
        std::cerr << " (at " << _where << ")";
    std::cerr << std::endl;
}
