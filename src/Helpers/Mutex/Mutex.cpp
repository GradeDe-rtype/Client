/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

    /*  ---- INCLUDES ---- */
#include "Mutex.hpp"


    /*  ---- FUNCTIONS ---- */
namespace RType
{
    namespace Helpers
    {
        void Mutex::lock()
        {
            _isLocked = true;
            _mutex.lock();
        }

        void Mutex::unlock()
        {
            _mutex.unlock();
            _isLocked = false;
        }

        bool Mutex::tryLock()
        {
            if (_isLocked) return false;
            _mutex.lock();
            _isLocked = true;
            return true;
        }

        bool Mutex::isLocked() const
        {
            return _isLocked;
        }
    }
}