#include "Client.h"
#include "GUI.h"

Client *Client::instance = nullptr;

Client* Client::getInstance() {
    if (instance == nullptr){
        instance = new Client;
    }
    return instance;
}

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
            std::string jstring = "JSON";
            if (received.substr(0,jstring.length()) == "JSON" ){

                std::string toparse = received.substr(jstring.length(),received.length()-jstring.length());
                json js = json::parse(toparse);
                GUI* gui = GUI::getInstance();
                std::cout << "From Server:" << std::string(buf, bytesReceived) << std::endl;
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

void Client::Send(char *msg) {
    int sendRes = send(sock, msg, strlen(msg), 0);
    if (sendRes == -1) {
        std::cout << "Send message failed" << std::endl;
    }
}

