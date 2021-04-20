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
    std::cout << "Listas creadas." << std::endl;

    for (int i = 0; i < 10240; i++){
        XMB->AddFirst((Node*)malloc(1024));
        std::cout << "Nodo añadido #" << i << std::endl;
    }
    std::cout << "Nodos añadidos." << std::endl;
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

void MemoryManager::Add(void *value, std::string varName, std::string varType) {
    usedMem->AddFront(XMB->GetDeleteFirst(), value, varName, varType);
}

void *MemoryManager::GetValOf(std::string varName) {
    return usedMem->GetNodeOfRef(varName)->value;
}
