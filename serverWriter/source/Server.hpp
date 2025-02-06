#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <fstream>

#define PORT 8009
#define BUFFER_SIZE 4096

class Server
{
private:
    int serverSocket;
    int clientSocket;
    struct sockaddr_in serverAddr;

    std::string getHttpDate();
    std::string createHttpResponse(const std::string& body);
    void createSocket();
    void bindSocket();
    void listenSocket();
    void acceptConnection();
    void handlePostRequest();
    void sendResponse();

public:
    Server();
    ~Server();
    void run();
};

#endif // SERVER_HPP
