/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "CommunicationClient.hpp"

namespace RType
{
    namespace Communication
    {
        Client::Client(std::string ip, int port, std::shared_ptr<RType::Communication::SendList> sendList)
            : _ip(ip), _port(port), _sendList(sendList), _state(TRY_CONNECT), _socket(_io_context)
        {
        }

        void Client::run()
        {
            while (_state != DOWN) {
                switch (_state) {
                    case TRY_CONNECT:
                        _connect();
                        break;
                    case CONNECTED:
                        _read();
                        break;
                    case DISCONNECT:
                        _disconnect();
                        break;
                    default:
                        std::cerr << "Unknown state: " << _state << std::endl;
                        _state = DOWN;
                        break;
                }
            }
        }

        void Client::shutdown()
        {
            _state = (_state == CONNECTED) ? DISCONNECT : DOWN;
        }

        void Client::_connect()
        {
            try {
                boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(_ip), _port);
                _socket.connect(endpoint);
                _state = CONNECTED;
            } catch (const boost::system::system_error &e) {
                std::cerr << "Connection error: " << e.what() << std::endl;
                _state = DISCONNECT;
            }
        }

        void Client::_disconnect()
        {
            _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_receive);
            _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send);
            _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
            _socket.close();
            _buffer.clear();
            _state = DOWN;
        }

        void Client::_read()
        {
            try {
                if (_socket.available() == 0) return;
                std::cout << "Reading..." << std::endl;
                auto buffer = std::make_shared<std::array<char, sizeof(rfcArgParser::DataPacket)>>();
                boost::asio::async_read(_socket, boost::asio::buffer(*buffer),
                [this, buffer](const boost::system::error_code &error, const std::size_t length) {
                     if (!error) {
                         const std::string data(buffer->begin(), buffer->begin() + length);
                         rfcArgParser::DataPacket packet = rfcArgParser::DeserializePacket(data, length);
                         _commands.handleCommand(rfcArgParser::DeserializePacket(packet));
                         std::cout << "sent a packet with command: " << packet.command << "\n";
                         std::cout << "Arguments: " << packet.args << "\n";
                         _read();
                     } else {
                         std::cerr << "Client disconnected" << error.message() << "\n";
                         _state = DISCONNECT;
                     }
                });
            } catch (const boost::system::system_error &e) {
                std::cerr << "Read error: " << e.what() << std::endl;
                _state = DISCONNECT;
            } catch (const std::exception &e) {
                std::cerr << "Unexpected error: " << e.what() << std::endl;
                _state = DISCONNECT;
            }
        }

        void Client::_write()
        {
            if (_sendList->size() > 0) {
                int i = 0;
                std::string args;
                std::vector<std::string> messages = _sendList->pop();
                std::string command;
                rfcArgParser::DataPacket packet{};
                for (std::string message : messages) {
                    command = message.substr(0, message.find(" "));
                    args = message.substr(message.find(" ") + 1);
                    packet = rfcArgParser::SerializePacket(command, args);
                    try {
                        boost::asio::write(
                            _socket, boost::asio::buffer(&packet, sizeof(packet)));
                    } catch (const boost::system::system_error &e) {
                        std::cerr << "Write error: " << e.what() << std::endl;
                        _state = DISCONNECT;
                    }
                }
            }
        }


        void Client::_checkOpen()
        {
            if (!_socket.is_open()) _state = DISCONNECT;
        }
    } // namespace Communication
} // namespace RType