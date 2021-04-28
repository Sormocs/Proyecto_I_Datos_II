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
    static MemoryManager* instance;

public:

    MemoryManager();
    static MemoryManager* Instance();

    void Add(void* value, std::string varName, std::string varType, std::string& parentClass, std::string& structCode);

    bool IsVariable(std::string name);

    std::string GetAddress(std::string varName);
    std::string GetType(std::string varName);

    // value getters
    void* GetValOf(std::string varName);
    int GetValOfInt(std::string varName);
    long GetValOfLong(std::string varName);
    float GetValOfFloat(std::string varName);
    double GetValOfDouble(std::string varName);
    char GetValOfChar(std::string varName);
    std::string GetValOfStruct(std::string varName);

    MemoryList* GetList();

    void Restart();
};

#endif //SERVER_MEMORYMANAGER_H