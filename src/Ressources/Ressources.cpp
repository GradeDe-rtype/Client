/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Ressources.hpp"

namespace RType
{
    Ressources::Ressources()
    {
        _timers.push_back(std::make_tuple(gd::Time(), 1, &Ressources::_sendPlayerPosition));
    }

    Ressources *Ressources::get()
    {
        static Ressources instance;
        return &instance;
    }

    std::unordered_map<std::string, std::shared_ptr<RType::Display::Player>> &Ressources::players()
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

    std::vector<std::unique_ptr<RType::Display::Shoot>> &Ressources::shoots()
    {
        return _shoots;
    }

    std::unordered_map<std::string, std::shared_ptr<RType::Display::Enemy>> &Ressources::enemies()
    {
        return _enemies;
    }

    void Ressources::update()
    {
        for (auto &timer : _timers) {
            if (std::get<0>(timer).getElapsedTime() >= std::get<1>(timer)) {
                (this->*std::get<2>(timer))();
                std::get<0>(timer).reset();
            }
        }
    }

    void Ressources::_sendPlayerPosition()
    {
        if (_me.hasMoved())
            _sendList->push("position " + _me.getPlayerPosition());
    }

} // namespace RType