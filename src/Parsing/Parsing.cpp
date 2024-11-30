/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#include "Parsing.hpp"

namespace RType
{
    Parsing::Parsing(int argc, char **argv)
    {
        if (argc == 2 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h"))
            throw Help();

        if (argc == 1) {
            _parseNoArgs();
            return;
        }
        if (argc != 5)
            throw ParsingError("Invalid number of arguments. Got " + std::to_string(argc) + " expected 5.");
        for (int i = 1; i < argc; i++) {
            if (std::string(argv[i]) == "-p") {
                _parseArgPort(argc, argv, i);
                i++;
                continue;
            }
            if (std::string(argv[i]) == "-i") {
                _parseArgIpAdress(argc, argv, i);
                i++;
                continue;
            }
            throw ParsingError("Invalid argument: \"" + std::string(argv[i]) + "\".");
        }
        if (_port == -1)
            throw ParsingError("Invalid argument: \"-p\". Port not set.");
        if (_ipAdress.empty())
            throw ParsingError("Invalid argument: \"-i\". Ip adress not set.");
    }

    int Parsing::getPort()
    {
        return _port;
    }

    std::string Parsing::getIpAdress()
    {
        return _ipAdress;
    }

    void Parsing::_parseArgPort(int argc, char **argv, int i)
    {
        if (_port != -1)
            throw ParsingError("Invalid argument: \"-p\". Port already set.");
        if (i + 1 >= argc)
            throw ParsingError("Invalid argument for \"-p\": \". Expect a value.");
        if (!RType::Helpers::Utils::isNumber(argv[i + 1]))
            throw ParsingError("Invalid argument for \"-p\": \"" + std::string(argv[i + 1]) + "\". Expect a number.");
        if (std::stoi(argv[i + 1]) < 0 || std::stoi(argv[i + 1]) > 65535)
            throw ParsingError("Invalid argument for \"-p\": \"" + std::string(argv[i + 1]) + "\". Expect a number between 0 and 65535.");
        _port = std::stoi(argv[i + 1]);
    }

    void Parsing::_parseArgIpAdress(int argc, char **argv, int i)
    {
        if (!_ipAdress.empty())
            throw ParsingError("Invalid argument: \"-i\". Host already set.");
        if (i + 1 >= argc)
            throw ParsingError("Invalid argument for \"-i\". Expect a value.");
        if (std::string(argv[i + 1]).empty())
            throw ParsingError("Invalid argument for \"-i\". Expect an ip adress.");
        if (!RType::Helpers::Utils::isIpAdress(argv[i + 1]) && (std::string(argv[i + 1]) != "localhost"))
            throw ParsingError("Invalid argument for \"-p\": \"" + std::string(argv[i + 1]) + "\". Expect a number.");
        if (std::string(argv[i + 1]) == "localhost")
            _ipAdress = "0.0.0.0";
        else
            _ipAdress = argv[i + 1];
    }

    void Parsing::_parseNoArgs()
    {
        Papaya tmp = Papaya(RType::Helpers::Path::get()->path() + "data", "connect");
        std::string tmpPort = tmp.getData("ref", "ref", "port");
        if (tmpPort.empty())
            throw ParsingError("No port in the data file.");
        if (!RType::Helpers::Utils::isNumber(tmpPort))
            throw ParsingError("Invalid port in the data file. Expect a number.");
        _port = std::stoi(tmpPort);

        std::string tmpIpAdress = tmp.getData("ref", "ref", "ip adress");
        if (tmpIpAdress.empty())
            throw ParsingError("No ip adress in the data file.");
        _ipAdress = tmpIpAdress;
    }
} // namespace RType