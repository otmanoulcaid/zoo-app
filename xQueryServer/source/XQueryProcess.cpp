#include "XQueryProcess.hpp"

XQueryProcess::XQueryProcess(std::string ressource) : __ressource(ressource),
                                                        __response("")
{
    processRequest();
}

void    XQueryProcess::execute(int fd)
{
    char *bin;
    if (dup2(fd, STDOUT_FILENO))
        __response.append("<h1>something goes wrong</h1>"), exit(1);
    bin = const_cast<char*>("/usr/bin/basex");
    char *argv [] = {bin, (char *)__ressource.c_str(), NULL};
    execve(bin, argv, NULL);
    __response.append("<h1>something goes wrong</h1>");
    close(fd);
    exit(2);
}

void    XQueryProcess::readFromPipe(int fd)
{
    char buffer[1024] = {0};
    while (read(fd, buffer, 1023))
    {
        __response.append(buffer);
        bzero(buffer, 1024);
    }
    close(fd);
}

void    XQueryProcess::processRequest()
{
    int pid, pip[2];

    if (pipe(pip) || (pid = fork()) < 0)
        __response.append("<h1>something goes wrong</h1>");
    else if (!pid)
        close(pip[0]), execute(pip[1]);
    else
        close(pip[1]), wait(NULL), readFromPipe(pip[0]);
}

std::string XQueryProcess::getResponse()
{
    return __response;
}
