//
// Created by tiquillo on 8/4/21.
//

#ifndef PROYECTO_I_DATOS_II_MEMORYMANAGER_H
#define PROYECTO_I_DATOS_II_MEMORYMANAGER_H

#include "MemList.h"

class MemoryManager {
private:
    MemoryList* memoryList = new MemoryList();
    MemoryList* XMB_mem = new MemoryList();
public:
    MemoryManager();

    Node* GetMemory();
};


#endif //PROYECTO_I_DATOS_II_MEMORYMANAGER_H
