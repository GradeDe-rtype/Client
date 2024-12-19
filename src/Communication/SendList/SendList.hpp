/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_COMMUNICATION_SEND_LIST_HPP_
#define RTYPE_COMMUNICATION_SEND_LIST_HPP_

/*  ---- INCLUDES ---- */
#include <string>
#include <vector>
#include "Helpers/Mutex/Mutex.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Communication
    {
        class Client;
        class SendList
        {
            public:
                SendList() = default;
                ~SendList() = default;

                void unlock();
                void push(std::string message);
                std::vector<std::string> pop();
                int size();
                void setClient(Client *client) { _client = client; }

            private:
                RType::Helpers::Mutex _mutex;
                std::vector<std::string> _list;
                bool _isLocked = false;
                RType::Communication::Client *_client = nullptr;
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_SENDLIST_HPP_ */
