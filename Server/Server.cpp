#include <iostream>
#include "string"
#include "Server.h"
#include "stdio.h"

Server *Server::instance = nullptr;

Server::Server() {}

Server* Server::getInstance() {
    if (instance == nullptr){
        instance = new Server;
    }
    return instance;
}

void Server::Start() {
    listening = socket(AF_INET, SOCK_STREAM,0);
    if (listening == -1)
    {
        std::cerr << "Can't create a socket! Quitting" << std::endl;
        exit(-1);
    }

    hint.sin_family = AF_INET;
    hint.sin_port = htons(PORT);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        std::cout << host << " connected on port " << service << std::endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        std::cout << host << " connected on port " << ntohs(client.sin_port) << std::endl;
    }

    // Close listening socket
    close(listening);

    while (true)
    {
        memset(buf, 0, 4096);

        // Wait for client to send data
        bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (bytesReceived == 0)
        {
            std::cout << "Client disconnected " << std::endl;
            break;
        }

        std::string received = std::string(buf,bytesReceived);
        if (received == "FINISHED"){
            std::cout << "Finish received" << std::endl;
            Sjson::getInstance()->Reset();
            MemoryManager::Instance()->Restart();
        } else {
            //std::cout << received << std::endl;
            CodeParser::Instance()->CheckLine(received);
            if (CodeParser::Instance()->GetDebug() != "") Send("ERROR"+CodeParser::Instance()->GetDebug());
            else {
                std::cout << "entered?" << std::endl;
                Sjson::getInstance()->ObtainVals();
                std::string jstr = "JSON" + Sjson::getInstance()->GetObj().dump();
                this->Send(jstr.c_str());
                Sjson::getInstance()->Reset();
                std::cout << "Json sent?" << std::endl;
            }
        }
    }

    close(clientSocket);
}

void Server::Send(std::string msg) {
    send(clientSocket, msg.c_str(), strlen(msg.c_str()) , 0);
}
