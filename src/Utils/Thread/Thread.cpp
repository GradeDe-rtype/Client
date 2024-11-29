/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Server
*/

#include "Thread.hpp"

namespace RType
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