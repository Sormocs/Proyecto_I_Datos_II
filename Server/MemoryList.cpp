//
// Created by tiquillo on 12/4/21.
//

#include "MemoryList.h"

Node::Node() {
    varName = "";
    varType = "";
    parentClass = "";
    structCode = "";
    next = nullptr;
    previous = nullptr;
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
    } else{
        first->previous = newFirst;
        newFirst->next = first;
        first = newFirst;
    }
    size++;
}

void AvaiList::AddLast(Node *newLast) {
    if (first == nullptr) {
        first = newLast;
        last = first;
    } else {
        last->next = newLast;
        newLast->previous = last;
        last = newLast;
    }
    size++;
}

Node *AvaiList::GetDeleteFirst() {

    if (first == nullptr) throw ("List is empty");

    Node* temp = first;
    first = first->next;
    temp->next = nullptr;

    if (first != nullptr) first->previous = nullptr;
    size--;
    return temp;

}



// MemoryList methods

Node *MemoryList::GetNodeOf(std::string varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first);
}

Node *MemoryList::GetNodeOfRef(std::string &varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first);
}

Node *MemoryList::SearchForNodeByName(std::string& varName, Node *node, int index) {
    if (index == size) return NULL; // calls debugger that var is not declared

    else if (node->varName == varName) {
        node->references++;
        return node;
    }

    else return SearchForNodeByName(varName, node->next, index + 1);
}


void *MemoryList::GetValOf(std::string varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first)->value;
}

void MemoryList::AddFront(Node *newFirst, void *value, std::string& varName, std::string& varType, std::string& parentClass, std::string& structCode) {
    newFirst->value = value;
    newFirst->varName = varName;
    newFirst->varType = varType;
    newFirst->parentClass = parentClass;
    newFirst->structCode = structCode;
    this->AddFirst(newFirst);
}

void MemoryList::ChangeValOf(std::string valName, void *newValue) {
    GetNodeOfRef(valName)->value = newValue;

}

Node *MemoryList::Get(int index) {
    return this->GetNode(index);
}
