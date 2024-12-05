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
#include <iostream>
#include <memory>
#include <string>
#include "Commands.hpp"
#include "SendList.hpp"
#include "Utils.hpp"

/*  ---- CLASS ---- */
namespace RType
{
    namespace Communication
    {
        class Client
        {
            public:
                Client(std::string ip, int port, std::shared_ptr<RType::Communication::SendList> sendList);
                ~Client() = default;

                void run();
                void shutdown();

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
                RType::Communication::Commands _commands;

                void _connect();
                void _connected();
                void _disconnect();
                void _read();
                void _write();
                void _checkOpen();
        };
    } // namespace Communication
} // namespace RType

#endif /* !RTYPE_COMMUNICATION_CLIENT_HPP_ */
