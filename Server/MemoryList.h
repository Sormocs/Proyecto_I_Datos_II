//
// Created by tiquillo on 12/4/21.
//

#ifndef SERVER_MEMORYLIST_H
#define SERVER_MEMORYLIST_H


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
    void AddFirst(Node* newFirst);
    void AddLast(Node* newLast);

    Node* GetDeleteFirst();
};




class MemoryList : protected AvaiList {
private:
    void* SearchForValByName(std::string valName, Node* node);
    Node* SearchForNodeByName(std::string varName, Node* node);

public:

    template <class T>
    void AddBegin(Node* newFirst, T value, std::string varName) {
        newFirst->value = (void*) new T(value);
        newFirst->varName = varName;
        this->AddFirst(newFirst);
    }

    template <class T>
    void ChangeValOf(std::string valName, T newValue);

    Node* Get(int index);
    Node* GetNodeOf(std::string varName);
    void* GetValOf(std::string valName);
};


#endif //SERVER_MEMORYLIST_H