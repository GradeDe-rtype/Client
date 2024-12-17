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

    void Ressources::update()
    {
        for (auto &timer : _timers) {
            if (std::get<0>(timer).getElapsedTime() >= std::get<1>(timer)) {
                (this->*std::get<2>(timer))();
                std::get<0>(timer).reset();
            }
        }

        if (roomState == RoomState::WAVE_READY) {
            roomState = RoomState::GAME;
            sendList->push("ready");
        }
    }

    void Ressources::_sendPlayerPosition()
    {
        if (me == nullptr) return;
        if (me->hasMoved())
            sendList->push("position " + me->getEntityPosition());
    }

} // namespace RType