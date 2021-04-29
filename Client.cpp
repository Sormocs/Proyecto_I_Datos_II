/**
 * @file Client.h
 * @author Sergio MB
 * @brief Declaracion de los metodos de la clase cliente.
 */

#include "Client.h"
#include "GUI.h"

Client *Client::instance = nullptr;

/**
 * @brief Metodo para obtener la insrtancia de la clase Client, ya que es un singleton.
 * @return
 */
Client* Client::getInstance() {
    if (instance == nullptr){
        instance = new Client;
    }
    return instance;
}

/**
 * @brief Metodo para empezar a correr el cliente y se mantiene corriendo constantemente recibiendo lo que provenga del server.
 * Realiza procesos segun lo recibido, conecta con GUI para acceder a todas sus funciones.
 */
void Client::Start() {

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        exit(1);
    }

    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    connectRes = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        exit(1);
    }

    bool run = true;
    while (run){
        memset(buf, 0, 4096);
        int bytesReceived = recv(sock, buf, 4096, 0);
        if (bytesReceived == -1)
        {
            std::cout << "Error getting response" << std::endl;
        }
        else {

            //		Display response
            std::string received = std::string(buf, bytesReceived);
            GUI* gui = GUI::getInstance();

            if (received.substr(0, strlen("ERROR")) == "ERROR"){

                std::string error = received.substr(strlen("ERROR"),received.length()-strlen("ERROR"));
                gui->GetLogCons()->AddLog(error);

            } else if (received.substr(0, strlen("JSON")) == "JSON" ){

                std::string toparse = received.substr(strlen("JSON"),received.length()-strlen("JSON"));
                json js = json::parse(toparse);
                gui->GetRamV()->SetDrawt(false);
                gui->GetRamV()->Reset();
                gui->GetRamV()->SetJson(js);
                gui->GetRamV()->SetDrawt(true);

            }

            std::cout << "From Server:" << std::string(buf, bytesReceived) << std::endl;
        }
    }
    close(sock);
    exit(0);
}

/**
 * @brief Metodo para enviar mensajes al servidor. Recibe un string que es el mensaje que se desea enviar.
 * @param msg
 */
void Client::Send(std::string msg) {
    int sendRes = send(sock, msg.c_str(), msg.length(), 0);
    if (sendRes == -1) {
        std::cout << "Send message failed" << std::endl;
    }
}

