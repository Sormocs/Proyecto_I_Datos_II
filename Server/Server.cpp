/**
 * @file Server.h
 * @author Sergio MB
 * @brief Definicion de metodos de la clase Server.
 */

#include <iostream>
#include "string"
#include "Server.h"
#include "stdio.h"

Server *Server::instance = nullptr;

/**
 * @brief Constructor para evitar instanciacion.
 */
Server::Server() {}

/**
 * @brief Metodo para obtener la instancia del server, ya que solamente puede haber un server.
 * @return
 */
Server* Server::getInstance() {
    if (instance == nullptr){
        instance = new Server;
    }
    return instance;
}

/**
 * @brief Metodo start que se encarga de iniciar el server y lo mantiene abierto y a la escucha de cualquier mensaje del server,
 * solamente actua cuando recibe mensajes por parte del IDE.
 */
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

            Sjson::getInstance()->Reset();
            MemoryManager::Instance()->Restart();

        } else if (received.substr(0, strlen("FULL")) == "FULL"){

            std::string code = received.substr(strlen("FULL"),received.length()-strlen("FULL"));
            CodeParser::Instance()->AddLine(code);

        } else {
            CodeParser::Instance()->CheckLine(received);
            if (CodeParser::Instance()->GetDebug() != "") Send("ERROR"+CodeParser::Instance()->GetDebug());
            else {
                Sjson::getInstance()->ObtainVals();
                std::string jstr = "JSON" + Sjson::getInstance()->GetObj().dump();
                this->Send(jstr.c_str());
                Sjson::getInstance()->Reset();
            }
        }
    }

    close(clientSocket);
}

/**
 * @brief Envia el parametro que recibe como mensaje al cliente por medio de los sockets.
 * @param msg
 */
void Server::Send(std::string msg) {
    send(clientSocket, msg.c_str(), strlen(msg.c_str()) , 0);
}
