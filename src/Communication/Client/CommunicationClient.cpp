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
        Client::Client(const std::string &ip, int port, std::shared_ptr<SendList> sendList)
            : _ip(ip), _port(port), _state(TRY_CONNECT), _socket(_io_context), _sendList(sendList)
        {
            _commands = std::make_unique<Commands>(sendList);
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
                        std::this_thread::sleep_for(std::chrono::milliseconds(10));
                        _checkOpen();
                        break;
                    case DISCONNECT:
                        _disconnect();
                        break;
                    case DOWN:
                        break;
                    default:
                        break;
                }
            }
        }

        void Client::shutdown()
        {
            _state = (_state == CONNECTED) ? DISCONNECT : DOWN;
            _io_context.stop();
        }

        void Client::_connect()
        {
            try {
                boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(_ip), _port);
                _socket.connect(endpoint);
                _state = CONNECTED;
                _read();
                _io_context.run();
                RType::Ressources::get()->isConnected = true;
            } catch (const boost::system::system_error &e) {
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
                boost::system::error_code ec;
                auto buffer = std::make_shared<std::array<char, sizeof(rfcArgParser::DataPacket)>>();
                while (_socket.available() != 0) {
                    std::size_t length = boost::asio::read(_socket,
                                                           boost::asio::buffer(*buffer, sizeof(rfcArgParser::DataPacket)),
                                                           ec);
                    if (ec) {
                        std::cerr << "Read error: " << ec.message() << std::endl;
                        _state = DISCONNECT;
                        return;
                    }
                    const std::string data(buffer->begin(), buffer->begin() + length);
                    rfcArgParser::DataPacket packet = rfcArgParser::DeserializePacket(data, length);
                    if (length == sizeof(rfcArgParser::DataPacket)) {
                        std::string stringPacket = rfcArgParser::DeserializePacket(packet);
                        _commands->handleCommand(stringPacket);
                    } else {
                        std::cerr << "Incomplete packet received" << std::endl;
                    }
                }
            } catch (const boost::system::system_error &e) {
                std::cerr << "Socket read error: " << e.what() << std::endl;
                _state = DISCONNECT;
            } catch (const std::exception &e) {
                std::cerr << "Unexpected error during read: " << e.what() << std::endl;
                _state = DISCONNECT;
            }
        }

        void Client::write(std::vector<std::string> messages)
        {
            for (const std::string &message : messages) {
                try {
                    size_t spacePos = message.find(" ");
                    std::string command = message.substr(0, spacePos);
                    std::string args = (spacePos != std::string::npos) ? message.substr(spacePos + 1) : "";
                    rfcArgParser::DataPacket packet = rfcArgParser::SerializePacket(command, args);
                    boost::asio::async_write(_socket, boost::asio::buffer(&packet, sizeof(packet)),
                                             [this, command, args](const boost::system::error_code &ec, std::size_t bytes_transferred) {
                                                 if (ec) {
                                                     std::cerr << "Transmission Error: "
                                                               << "Failed to send packet "
                                                               << "(Command: " << command << "). "
                                                               << "Error: " << ec.message() << std::endl;
                                                     _state = DISCONNECT;
                                                     return;
                                                 }
                                             });
                } catch (const std::exception &e) {
                    std::cerr << "Packet Processing Error: "
                              << e.what() << std::endl;
                    _state = DISCONNECT;
                    break;
                }
            }
        }

        void Client::_checkOpen()
        {
            if (!_socket.is_open()) _state = DISCONNECT;
        }
    } // namespace Communication
} // namespace RType