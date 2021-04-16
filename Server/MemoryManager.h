//
// Created by tiquillo on 8/4/21.
//

#ifndef SERVER_MEMORYMANAGER_H
#define SERVER_MEMORYMANAGER_H

#include "MemoryList.h"


class MemoryManager {
private:

//    MemoryList* usedMem;
    AvaiList* XMB;
public:
    MemoryList* usedMem;

    MemoryManager();

    template <class T>
    void AddVar(T value, std::string varName, std::string varType){
        usedMem->AddBegin(XMB->GetDeleteFirst(), value, varName, varType);
    }
    std::string GetAddress(std::string varName);
    std::string GetType(std::string varName);

    template <class T>
    T GetValOf(std::string varName){
        return usedMem->GetNodeOf(varName)->value;
    }
};


#endif //SERVER_MEMORYMANAGER_H