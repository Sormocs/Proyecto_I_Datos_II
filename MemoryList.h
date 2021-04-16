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
    std::type_info varT;
    Node* next;
    Node* previous;

    template <class T>
    Node(T* value, std::string varName);
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

    Node* GetNode(int index);
    Node* AddFirst(Node* newFirst);
    Node* AddLast(Node* newLast);

    Node* GetDeleteFirst();
};




class MemoryList : protected AvaiList {
private:
    void* SearchForValByName(std::string valName, Node* node);
    Node* SearchForNodeByName(std::string varName, Node* node);

public:

    template <class T>
    Node* AddBegin(Node* newFirst, T value, std::string varName) {
        newFirst->value = (void*) new T(value);
        newFirst->varName = varName;
        return this->AddFirst(newFirst);
    }

    template <class T>
    void ChangeValOf(std::string valName, T newValue);

    Node* Get(int index);
    Node* GetNodeOf(std::string varName);
    void* GetValOf(std::string valName);
};


#endif //PROYECTO_I_DATOS_II_MEMORYLIST_H
