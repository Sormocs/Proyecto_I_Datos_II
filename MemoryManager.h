//
// Created by tiquillo on 8/4/21.
//

#ifndef PROYECTO_I_DATOS_II_MEMORYMANAGER_H
#define PROYECTO_I_DATOS_II_MEMORYMANAGER_H

#include "MemoryList.h"

class MemoryManager {
private:
    MemoryList* memoryList = new MemoryList();
    AvaiList* XMB = new AvaiList();
public:
    MemoryManager();

    Node* GetMemory();
};


#endif //PROYECTO_I_DATOS_II_MEMORYMANAGER_H
