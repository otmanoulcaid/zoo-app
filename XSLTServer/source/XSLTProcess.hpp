#pragma once

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <ctime>

class XSLTProcess
{
    private:
        std::string     __ressource;
        std::string     __response;
        XSLTProcess(){}

    public:
        ~XSLTProcess(){}
        XSLTProcess(std::string ressource);
        std::string     getResponse( void );
        void            processRequest( void );
        void            readFromPipe(int fd);
        void            execute(int fd);
};