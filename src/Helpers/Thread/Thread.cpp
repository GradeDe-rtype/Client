/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

    /*  ---- INCLUDES ---- */
#include "Thread.hpp"


    /*  ---- FUNCTIONS ---- */
namespace RType
{
    namespace Helpers
    {
        Thread::Thread()
        {
            _running = false;
        }

        Thread::~Thread()
        {
            this->join();
        }

        void Thread::start(std::function<void()> function)
        {
            if (!_running) {
                _running = true;
                _thread = std::thread(function);
            }
        }

        void Thread::join()
        {
            if (_running && _thread.joinable()) {
                _thread.join();
                _running = false;
            }
        }
    }
}
