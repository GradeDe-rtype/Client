/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Ressources.hpp"

namespace RType {
    Ressources *Ressources::get()
    {
        static Ressources instance;
        return &instance;
    }

    Ressources::Ressources()
    {
    }

    std::unordered_map<std::string, Player> &Ressources::players()
    {
        return _players;
    }

    Player &Ressources::me()
    {
        return _me;
    }
}