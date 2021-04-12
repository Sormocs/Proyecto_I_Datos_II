//
// Created by tiquillo on 12/4/21.
//

#ifndef PROYECTO_I_DATOS_II_MEMORYLIST_H
#define PROYECTO_I_DATOS_II_MEMORYLIST_H


#include <string>


class Node {
public:
    void* value;
    std::string varName;
    std::string varType;
    Node* next;
    Node* previous;

    Node(void* value);
    Node() = default;
};




class AvaiList{
protected:
    Node* first;
    Node* last;
    int size;

    Node* GetRecursively(int index, Node* node);

public:
    AvaiList() = default;

    Node* Get(int index);
    Node* AddFirst(Node* newFirst);
    Node* AddLast(Node* newLast);

    Node* GetDeleteFirst();
};




class MemoryList : protected AvaiList {
private:

    void* SearchForValByName(std::string valName, Node* node);

public:

    Node* AddBegin(Node* newFirst);
    Node* AddEnd(Node* newLast);

    void ChangeValOf(int index);
    void ChangeValOf(std::string valName);

    void* GetValOf(int index);
    void* GetValOf(std::string valName);
};


#endif //PROYECTO_I_DATOS_II_MEMORYLIST_H
