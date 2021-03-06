/**
 * @file Server.h
 * @author Sergio MB
 * @brief Contiene declaracion de clase Server
 */

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "CodeParser.h"
#include "Sjson.h"
#include "thread"


#pragma once

/**
 * @brief Clase server que conecta con el IDE que seria el cliente.
 */
class Server {
private:
    int listening;
    int PORT = 5000;
    int clientSocket;
    int bytesReceived;
    sockaddr_in hint;
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    char buf[4096];

    static Server *instance;

public:
    Server();
    void Start();
    void Send(std::string);
    static Server* getInstance();
};
