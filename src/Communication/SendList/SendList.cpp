/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

    /*  ---- INCLUDES ---- */
    #include "SendList.hpp"


    /*  ---- FUNCTIONS ---- */
namespace RType {
    namespace Communication {
        void SendList::push(std::string message)
        {
            _mutex.lock();
            _list.push_back(message);
            _mutex.unlock();
        }

        std::vector<std::string> SendList::pop()
        {
            std::vector<std::string> list;

            _mutex.lock();
            list = _list;
            _list.clear();
            _mutex.unlock();
            return list;
        }

        int SendList::size()
        {
            int size;

            _mutex.lock();
            size = _list.size();
            _mutex.unlock();
            return size;
        }
    }
}