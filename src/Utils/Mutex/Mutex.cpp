/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Mutex
*/

#include "Mutex.hpp"

namespace RType {
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