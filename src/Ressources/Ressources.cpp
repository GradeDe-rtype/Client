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

    std::unordered_map<std::string, RType::Display::Player> &Ressources::players()
    {
        return _players;
    }

    RType::Display::Player &Ressources::me()
    {
        return _me;
    }

    std::shared_ptr<RType::Communication::SendList> &Ressources::sendList()
    {
        return _sendList;
    }

    void Ressources::setSendList(std::shared_ptr<RType::Communication::SendList> sendList)
    {
        _sendList = sendList;
    }

} // namespace RType