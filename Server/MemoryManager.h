//
// Created by tiquillo on 8/4/21.
//

#ifndef SERVER_MEMORYMANAGER_H
#define SERVER_MEMORYMANAGER_H

#include "MemoryList.h"

class MemoryManager {
private:
    MemoryList* usedMem;
    AvaiList* XMB;

protected:
    static MemoryManager* instance;

public:

    static MemoryManager* Instance();

    MemoryManager();

    void Add(void* value, std::string varName, std::string varType, std::string& parentClass);

    template <class T>
    void AddVar(T value, std::string varName, std::string varType){
        usedMem->AddBegin(XMB->GetDeleteFirst(), value, varName, varType);
    }
    std::string GetAddress(std::string varName);
    std::string GetType(std::string varName);


    void* GetValOf(std::string varName);

};

#endif //SERVER_MEMORYMANAGER_H