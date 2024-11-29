/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Server
*/

#ifndef THREAD_HPP
    #define THREAD_HPP

    /*  ---- INCLUDES ---- */
    #include <thread>
    #include <functional>

    /*  ---- CLASS ---- */
namespace RType
{
    /**
     * @brief Thread class
     */
    class Thread
    {
        public:
            /**
             * @brief Construct a new Thread
             */
            Thread();
            ~Thread();

            /**
             * @brief Start the thread with a given function
             *
             * @param function The function to run in the thread
             */
            void start(std::function<void()> function);

            /**
             * @brief Join the thread
             *
             * @brief This function blocks until the thread finishes its execution.
             */
            void join();

        private:
            std::thread _thread;
            bool _running;

    };
}

#endif