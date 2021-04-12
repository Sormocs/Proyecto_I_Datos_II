//
// Created by tiquillo on 8/4/21.
//

#include "MemoryManager.h"

MemoryManager::MemoryManager() {
    /*
     * Asigns 10 MB of memory at the begginning of the run
     */
    for (int i = 0; i < 1310720; i++){
//        Node* temp = new Node(((int*)malloc(1024)), ((long*)malloc(1024)),
//                              ((char*)malloc(1024)), ((float*)malloc(1024)),
//                              ((double*)malloc(1024)), ((void*)malloc(1024)));

        XMB->AddFirst(new Node(malloc(8)));
    }
}

