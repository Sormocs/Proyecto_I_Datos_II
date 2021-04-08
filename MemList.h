//
// Created by tiquillo on 8/4/21.
//

#ifndef PROYECTO_I_DATOS_II_MEMLIST_H
#define PROYECTO_I_DATOS_II_MEMLIST_H

#include <string>


class Node {
public:
    int memCell;
    std::string varName;
    Node* next;
    Node* previous;

    // value
    int* intValue;
    long* longValue;
    char* charValue;
    float* floatValue;
    double* doublevalue;
    void* referenceValue;

    void* operator new(size_t size);
    void operator delete(void *pVoid);
};

class MemoryList{
private:
    Node* first;
    Node* last;
    int size;

    Node* GetRecursively(int index, Node* node);

public:
    MemoryList() = default;

    Node* Get(int index);
    Node* AddFirst(Node* newFirst);
    Node* AddLast(Node* newLast);

    Node* GetDeleteFirst();
};


#endif //PROYECTO_I_DATOS_II_MEMLIST_H
