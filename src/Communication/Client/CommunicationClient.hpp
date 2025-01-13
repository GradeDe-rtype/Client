/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef RTYPE_COMMUNICATION_CLIENT_HPP_
#define RTYPE_COMMUNICATION_CLIENT_HPP_

/*  ---- INCLUDES ---- */
#include <boost/asio.hpp>
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include "Communication/Commands/Commands.hpp"
#include "Communication/SendList/SendList.hpp"
#include "Helpers/Utils/Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Communication
    {
        class Client
        {
            public:
                Client(const std::string &ip, int port, std::shared_ptr<SendList> sendList);
                ~Client() = default;

                void run();
                void shutdown();
                void write(std::vector<std::string> messages);

            private:
                typedef enum {
                    TRY_CONNECT,
                    CONNECTED,
                    DISCONNECT,
                    DOWN
                } State;

                std::string _ip;
                int _port;
                State _state;
                boost::asio::io_context _io_context;
                boost::asio::ip::tcp::socket _socket;
                std::vector<std::string> _buffer;
                std::shared_ptr<RType::Communication::SendList> _sendList;
                std::unique_ptr<RType::Communication::Commands> _commands;

                void _connect();
                void _disconnect();
                void _read();
                void _checkOpen();
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_CLIENT_HPP_ */
