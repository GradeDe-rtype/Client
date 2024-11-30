/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_COMMUNICATION_SENDLIST_HPP_
    #define RTYPE_COMMUNICATION_SENDLIST_HPP_

    /*  ---- INCLUDES ---- */
    #include <vector>
    #include <string>

    #include "Mutex.hpp"

    /*  ---- CLASS ---- */
namespace RType {
    namespace Communication {
        class SendList {
            public:
                SendList() = default;
                ~SendList() = default;

                void push(std::string message);
                std::vector<std::string> pop();
                int size();

            private:
                RType::Helpers::Mutex _mutex;
                std::vector<std::string> _list;
        };
    }
}

#endif /* !RTYPE_COMMUNICATION_SENDLIST_HPP_ */
