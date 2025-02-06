#include "Server.hpp"
#include <fstream>

Server::Server() : serverSocket(-1), clientSocket(-1)
{
    memset(&serverAddr, 0, sizeof(serverAddr));
    createSocket();
    bindSocket();
    listenSocket();
}

Server::~Server()
{
    if (clientSocket != -1) close(clientSocket);
    if (serverSocket != -1) close(serverSocket);
}

std::string Server::getHttpDate()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *gmtime(&now);
    strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S GMT", &tstruct);
    return buf;
}

std::string Server::createHttpResponse(const std::string& body)
{
    std::ostringstream response;
    response << "HTTP/1.1 200 OK\r\n";
    response << "Date: " << getHttpDate() << "\r\n";
    response << "Content-Type: text/html; charset=UTF-8\r\n";
    response << "Content-Length: " << body.size() << "\r\n";
    response << "Connection: close\r\n";
    response << "Server: CustomCPPServer/1.0\r\n";
    response << "\r\n";
    response << body;

    return response.str();
}

void Server::createSocket()
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        perror("Socket creation failed"), exit(EXIT_FAILURE);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);
}

void Server::bindSocket()
{
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Bind failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
}

void Server::listenSocket()
{
    if (listen(serverSocket, 3) < 0)
    {
        perror("Listen failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
    std::cout << "Server is listening on port " << PORT << "..." << std::endl;
}

void Server::acceptConnection()
{
    clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket < 0)
    {
        perror("Accept failed");
        close(serverSocket);
        exit(EXIT_FAILURE);
    }
}

void Server::handlePostRequest()
{
    char buffer[BUFFER_SIZE] = {0};
    std::string body;
    bool headersEnded = false;

    memset(buffer, 0, BUFFER_SIZE);
    read(clientSocket, buffer, sizeof(buffer));
	body.append(buffer);
	size_t pos = body.find("\r\n\r\n");
	body = body.substr(pos + 4);
    std::ofstream outFile("data/xml/added.xml", std::ios::app);
    if (outFile.is_open())
    {
        outFile << body;
        outFile.close();
    }
}

void Server::sendResponse()
{
    std::string response = createHttpResponse("<h1 style=\"text-align:center\">XML data reçu avec succes.</h1>");
    send(clientSocket, response.c_str(), response.size(), 0);
}

void Server::run()
{
    while (true)
    {
        acceptConnection();
        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);
		handlePostRequest();
		sendResponse();
        close(clientSocket);
        clientSocket = -1;
    }
}

int main()
{
    Server server;
    server.run();
}
