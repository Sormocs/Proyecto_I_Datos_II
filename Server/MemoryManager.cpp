//
// Created by tiquillo on 8/4/21.
//

#include <sstream>
#include <iostream>
#include "MemoryManager.h"

MemoryManager* MemoryManager::instance = nullptr;

MemoryManager::MemoryManager() {
    /*
     * Asigns 10 MB of memory at the begginning of the run
     */

    usedMem = new MemoryList();
    XMB = new AvaiList();

    for (int i = 0; i < 10240; i++){
        XMB->AddFirst((Node*)malloc(1024));
    }
}

//template<class T>
//void MemoryManager::AddVar(T value, std::string varName) {
//    usedMem->AddBegin(XMB->GetDeleteFirst(), value, varName);
//}

std::string MemoryManager::GetAddress(std::string varName) {
    std::ostringstream address;
    address << usedMem->GetNodeOf(varName);
    return address.str();
}

std::string MemoryManager::GetType(std::string varName) {
    return usedMem->GetNodeOf(varName)->varType;
}

MemoryManager* MemoryManager::Instance() {
    if (instance == nullptr) instance = new MemoryManager();
    return instance;
}

void MemoryManager::Add(void *value, std::string varName, std::string varType, std::string& parentClass, std::string& structCode) {
    usedMem->AddFront(XMB->GetDeleteFirst(), value, varName, varType, parentClass);
}

void *MemoryManager::GetValOf(std::string varName) {
    return usedMem->GetNodeOfRef(varName)->value;
}

int MemoryManager::GetValOfInt(std::string varName) {
    return *(int*) GetValOf(varName);
}

long MemoryManager::GetValOfLong(std::string varName) {
    return *(long*) GetValOf(varName);
}

float MemoryManager::GetValOfFloat(std::string varName) {
    return *(float*) GetValOf(varName);
}

double MemoryManager::GetValOfDouble(std::string varName) {
    return *(double*) GetValOf(varName);
}

char MemoryManager::GetValOfChar(std::string varName) {
    return *(char*) GetValOf(varName);
}

std::string MemoryManager::GetValOfStruct(std::string varName) {
    return *(std::string*) GetValOf(varName);
}


