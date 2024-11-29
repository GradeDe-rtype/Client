/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_

    /*  ---- INCLUDES ---- */
    #include <mutex>

    /*  ---- CLASS ---- */
namespace RType {
    /**
     * @brief A simple mutex class
     */
    class Mutex {
        public:
            Mutex() = default;
            ~Mutex() = default;

            /**
             * @brief Lock the mutex
             */
            void lock();

            /**
             * @brief Unlock the mutex
             */
            void unlock();

            /**
             * @brief Try to lock the mutex.
             *
             * @return `true` if the mutex was successfully locked, `false` if it was already locked
             */
            bool tryLock();

            /**
             * @brief Check if the mutex is locked
             *
             * @return `true` if the mutex is locked, `false` otherwise
             */
            bool isLocked() const;

        private:
            std::mutex _mutex;
            bool _isLocked = false;
    };
}

#endif /* !MUTEX_HPP_ */
