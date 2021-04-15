//
// Created by tiquillo on 8/4/21.
//

#ifndef PROYECTO_I_DATOS_II_MEMORYMANAGER_H
#define PROYECTO_I_DATOS_II_MEMORYMANAGER_H

#include "MemoryList.h"


class MemoryManager {
private:

//    MemoryList* usedMem;
    AvaiList* XMB;
public:
    MemoryList* usedMem;

    MemoryManager();

    template <class T>
    void AddVar(T value, std::string varName){
        usedMem->AddBegin(XMB->GetDeleteFirst(), value, varName);
    }
    std::string GetAddress(std::string varName);
};


#endif //PROYECTO_I_DATOS_II_MEMORYMANAGER_H
