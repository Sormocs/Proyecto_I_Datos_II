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
    std::string parentClass;
    std::string structCode;
    Node* next;
    Node* previous;

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
    Node* SearchForNodeByName(std::string& varName, Node* node, int index = 0);

public:

    void AddFront(Node* newFirst, void* value, std::string& varName, std::string& varType, std::string& parentClass, std::string& structCode);

    void ChangeValOf(std::string valName, void* newValue);

    Node* Get(int index);
    Node* GetNodeOf(std::string varName);
    Node* GetNodeOfRef(std::string& varName);
    void* GetValOf(std::string varName);
};


#endif //SERVER_MEMORYLIST_H