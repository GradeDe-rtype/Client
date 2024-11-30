/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef THREAD_HPP
#define THREAD_HPP

/*  ---- INCLUDES ---- */
#include <functional>
#include <thread>

/*  ---- CLASS ---- */
namespace RType
{
    namespace Helpers
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
    } // namespace Helpers
} // namespace RType

#endif