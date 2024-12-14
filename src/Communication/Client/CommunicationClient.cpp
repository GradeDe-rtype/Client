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
        }

        void Client::run() {
            std::cout << "Running client" << std::endl;
            _connect();
            _io_context.run();
        }

        void Client::shutdown() {
            _state = (_state == CONNECTED) ? DISCONNECT : DOWN;
            _io_context.stop();
        }

        void Client::_connect() {
            boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(_ip), _port);
            _socket.async_connect(endpoint, [this](const boost::system::error_code &error) {
                if (!error) {
                    _state = CONNECTED;
                    std::cout << "Connected to " << _ip << ":" << _port << std::endl;
                    _read();
                } else {
                    std::cerr << "Connection error: " << error.message() << std::endl;
                    _state = DISCONNECT;
                }
            });
        }

        void Client::_disconnect() {
            _socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
            _socket.close();
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

        void Client::_write(std::vector<std::string> messages)
        {
            for (const std::string& message : messages) {
                try {
                    size_t spacePos = message.find(" ");
                    std::string command = message.substr(0, spacePos);
                    std::string args = (spacePos != std::string::npos) ? message.substr(spacePos + 1) : "";
                    rfcArgParser::DataPacket packet = rfcArgParser::SerializePacket(command, args);
                    std::cout << "Sending packet - Command: " << command
                              << ", Arguments: " << args << std::endl;
                    boost::asio::async_write(_socket, boost::asio::buffer(&packet, sizeof(packet)),
                        [this, command, args](const boost::system::error_code& ec, std::size_t bytes_transferred) {
                            if (ec) {
                                std::cerr << "Transmission Error: "
                                          << "Failed to send packet "
                                          << "(Command: " << command << "). "
                                          << "Error: " << ec.message() << std::endl;
                                _state = DISCONNECT;
                                return;
                            }
                            std::cout << "Packet Sent Successfully" << std::endl;
                        });
                }
                catch (const std::exception& e) {
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