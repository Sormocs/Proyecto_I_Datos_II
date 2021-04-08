//
// Created by tiquillo on 8/4/21.
//

#include "MemoryManager.h"

Node *MemoryManager::GetMemory() {
    return XMB_mem->GetDeleteFirst();
}

MemoryManager::MemoryManager() {
    for (int i = 0; i < 10240; i++){
        XMB_mem->AddFirst((Node*)malloc(1024));
    }
}
