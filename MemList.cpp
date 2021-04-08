//
// Created by tiquillo on 8/4/21.
//

#include "MemList.h"

Node *MemoryList::Get(int index) {
    if (index + 1 > size) throw ("Out of borders");

    else if (index == - 1)return last;

    else if (index == 0) return first;

    else if (index < 0){
        if ((index * - 1) + 1 > size) throw ("Out of borders");
        else return GetRecursively(index, last);
    }
    else return GetRecursively(index, first);
}

Node *MemoryList::GetRecursively(int index, Node* node) {
    if (index == 0) return node;
    else if (index < 0) return GetRecursively(index + 1, node->previous);
    else return GetRecursively(index - 1, node->next);
}

Node *MemoryList::AddFirst(Node* newFirst) {
    if (first == NULL) first = newFirst;
    first->previous = newFirst;
    newFirst->next = first;
    first = newFirst;
}

Node *MemoryList::AddLast(Node *newLast) {
    if (first == NULL) first = newLast;
    last->next = newLast;
    newLast->previous = last;
    last = newLast;
}

Node *MemoryList::GetDeleteFirst() {
    Node* temp = first;
    first = first->next;
    temp->next = NULL;

    if (first == NULL) return temp;

    first->previous = NULL;
    return temp;

}

void *Node::operator new(size_t size) {
    return nullptr;
}
