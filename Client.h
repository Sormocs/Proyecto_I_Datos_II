#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include "json.hpp"

#pragma once

using json = nlohmann::json;

class Client {
private:
    int sock;
    int port = 5000;
    int connectRes;
    sockaddr_in hint;
    std::string ipAddress = "127.0.0.1";
    char buf[4092];
    static Client *instance;
    Client() = default;

public:
    static Client* getInstance();
    void Start();
    void Send(char*);

};
