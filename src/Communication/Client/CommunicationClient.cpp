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
            _connect();
        }

        void Client::run()
        {
            while (_state != DOWN) {
                switch (_state) {
                    case TRY_CONNECT:
                        _connect();
                        break;
                    case CONNECTED:
                        _connected();
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
            boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(_ip), _port);
            boost::system::error_code error;

            _socket.connect(endpoint, error);
            if (error) return;
            _state = CONNECTED;
            _sendList->unlock();
        }

        void Client::_connected()
        {
            _checkOpen();
            _read();

            if (_buffer.size() > 0) {
                for (std::string message : _buffer)
                    _commands.handleCommand(message);
                _buffer.clear();
            }

            _write();
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
                std::array<char, sizeof(rfcArgParser::DataPacket)> buffer;
                std::cout << "Reading..." << std::endl;
                boost::asio::read(_socket, boost::asio::buffer(buffer, 16));
                std::cout << "Received:" << std::endl;
                std::string data(buffer.begin(), buffer.end());
                rfcArgParser::DataPacket packet = rfcArgParser::DeserializePacket(data, sizeof(data));
                std::cout << "Command: " << packet.command << "Args :" << packet.args << std::endl;
                _buffer.push_back(rfcArgParser::DeserializePacket(packet));
                // _read();
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