/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Ressources.hpp"

namespace RType
{
    Ressources *Ressources::get()
    {
        static Ressources instance;
        return &instance;
    }

    Ressources::Ressources()
    {
    }

    std::unordered_map<std::string, RType::Display::Player> &Ressources::players()
    {
        return _players;
    }

    RType::Display::Player &Ressources::me()
    {
        return _me;
    }
} // namespace RType