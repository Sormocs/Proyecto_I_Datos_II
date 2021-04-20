//
// Created by tiquillo on 12/4/21.
//

#include "MemoryList.h"


// Node methods

template <class T>
Node::Node(T *value, std::string varName) {
    this->varName = varName;
}



// AvaiList methods

Node *AvaiList::GetNode(int index) {
    if (index + 1 > size) throw ("Out of borders");

    else if (index == - 1)return last;

    else if (index == 0) return first;

    else if (index < 0){
        if ((index * - 1) + 1 > size) throw ("Out of borders");
        else return GetRecursively(index, last);
    }
    else return GetRecursively(index, first);
}

Node *AvaiList::GetRecursively(int index, Node* node) {
    if (index == 0) return node;
    else if (index < 0) return GetRecursively(index + 1, node->previous);
    else return GetRecursively(index - 1, node->next);
}

void AvaiList::AddFirst(Node* newFirst) {
    newFirst->next = nullptr;
    newFirst->previous = nullptr;
    if (first == nullptr) {
        first = newFirst;
        last = newFirst;
    }
    first->previous = newFirst;
    newFirst->next = first;
    first = newFirst;
}

void AvaiList::AddLast(Node *newLast) {
    if (first == nullptr) first = newLast;
    last->next = newLast;
    newLast->previous = last;
    last = newLast;
}

Node *AvaiList::GetDeleteFirst() {

    if (first == nullptr) throw ("List is empty");

    Node* temp = first;
    first = first->next;
    temp->next = nullptr;

    if (first != nullptr) first->previous = nullptr;
    return temp;

}



// MemoryList methods

Node *MemoryList::GetNodeOf(std::string varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first);
}

Node *MemoryList::SearchForNodeByName(std::string varName, Node *node) {
    if (node == nullptr) throw ("Val is not in list.");

    else if (node->varName == varName) return node;

    else return SearchForNodeByName(varName, node->next);
}


void *MemoryList::GetValOf(std::string valName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForValByName(valName, first);
}

void *MemoryList::SearchForValByName(std::string valName, Node* node) {
    if (node == nullptr) throw ("Val is not in list.");

    else if (node->varName == valName) return node->value;

    else return SearchForValByName(valName, node->next);
}

void MemoryList::AddFront(Node *newFirst, void *value, std::string& varName, std::string& varType) {
    newFirst->value = value;
    newFirst->varName = varName;
    newFirst->varType = varType;
    this->AddFirst(newFirst);
}

//template <class T>
//Node *MemoryList::AddBegin(Node *newFirst, T value, std::string varName) {
//    newFirst->value = (void*) new T(value);
//    return this->AddFirst(newFirst);
//}