#pragma once
#include "XSLTProcess.hpp"

#define BUFFER_SIZE 4096
#define PORT 8009

class Server
{
    private:
        int serverSocket;
        int clientSocket;
        struct sockaddr_in serverAddr;

        std::string     createHttpResponse(const std::string& resource);
        std::string     getRequestedResource();
        std::string     getHttpDate();
        void            sendResponse(const std::string& resource);
        void            acceptConnection();
        void            listenSocket();
        void            createSocket();
        void            bindSocket();

    public:
        Server();
        ~Server();
        void            run();
};
