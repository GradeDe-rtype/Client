/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_RESSOURCES_HPP_
    #define RTYPE_RESSOURCES_HPP_

    /*  ---- INCLUDES ---- */
    #include <string>
    #include <unordered_map>

    #include "Utils.hpp"
    #include "Player.hpp"


    /*  ---- CLASS ---- */
namespace RType {
    class Ressources {
        public:
            static Ressources *get();
            ~Ressources() = default;

            std::unordered_map<std::string, Player> &players();
            Player &me();

        private:
            Ressources();

            Player _me;
            std::unordered_map<std::string, Player> _players;
    };
}

#endif /* !RTYPE_RESSOURCES_HPP_ */
