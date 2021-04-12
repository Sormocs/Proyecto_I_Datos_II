//
// Created by tiquillo on 12/4/21.
//

#include "MemoryList.h"

Node *AvaiList::Get(int index) {
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

Node *AvaiList::AddFirst(Node* newFirst) {
    if (first == NULL) first = newFirst; last = newFirst;
    first->previous = newFirst;
    newFirst->next = first;
    first = newFirst;
}

Node *AvaiList::AddLast(Node *newLast) {
    if (first == NULL) first = newLast;
    last->next = newLast;
    newLast->previous = last;
    last = newLast;
}

Node *AvaiList::GetDeleteFirst() {
    Node* temp = first;
    first = first->next;
    temp->next = NULL;

    if (first == NULL) return temp;

    first->previous = NULL;
    return temp;

}

//Node::Node(int *intValue, long *longValue, char *charValue, float *floatValue, double *doublevalue, void *referenceValue) {
//    this->intValue = intValue;
//    this->longValue = longValue;
//    this->charValue = charValue;
//    this->floatValue = floatValue;
//    this->doublevalue = doublevalue;
//    this->referenceValue = referenceValue;
//
//}

Node::Node(void *value) {
    this->value = value;
}

void *MemoryList::GetValOf(std::string valName) {
    if (first == NULL) throw ("List is empty.");

    else return SearchForValByName(valName, first->next);
}

void *MemoryList::SearchForValByName(std::string valName, Node* node) {
    if (node == NULL) throw ("Val is not in list.");

    else if (node->varName == valName) return node;

    else return SearchForValByName(valName, node->next);
}

Node *MemoryList::AddBegin(Node *newFirst) {
    return MemoryList::AddFirst(newFirst);
}
