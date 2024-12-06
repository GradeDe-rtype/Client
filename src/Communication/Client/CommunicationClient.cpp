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
                boost::asio::streambuf streambuf;
                boost::asio::read_until(_socket, streambuf, "\n");
                std::istream is(&streambuf);
                std::string line;
                while (std::getline(is, line)) {
                    std::string trimmed = RType::Helpers::Utils::trim(line);
                    if (!trimmed.empty()) _buffer.push_back(trimmed);
                }
            } catch (const std::exception &e) {
                std::cerr << "Read error: " << e.what() << std::endl;
                _state = DISCONNECT;
            }
        }

        void Client::_write()
        {
            if (_sendList->size() > 0) {
                std::vector<std::string> messages = _sendList->pop();
                for (std::string message : messages) {
                    message += "\r\n";
                    boost::asio::write(_socket, boost::asio::buffer(message));
                }
            }
        }

        void Client::_checkOpen()
        {
            if (!_socket.is_open()) _state = DISCONNECT;
        }
    } // namespace Communication
} // namespace RType