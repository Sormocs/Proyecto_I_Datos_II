/**
 * @file MemoryList.cpp
 * @author Luis Delgado
 * @brief Definicion de métodos de las clases de listas de memoria.
 */

#include "MemoryList.h"

/**
 * @brief Constructor de Node.
 */
Node::Node() {
    varName = "";
    varType = "";
    parentClass = "";
    next = nullptr;
    previous = nullptr;
}

/**
 * @brief Obtiene la dirección de memoria y la retorna.
 * @return string
 */
std::string Node::GetAddress() {
    std::ostringstream address;
    address << this->value;
    return address.str();
}



// AvaiList methods

/**
 * @brief Obtiene el nodo en el índice específico y lo retorna.
 * @return Node*
 */
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

/**
 * @brief Obtiene el nodo recursivamente mediante un índice.
 * @return Node*
 */
Node *AvaiList::GetRecursively(int index, Node* node) {
    if (index == 0) return node;
    else if (index < 0) return GetRecursively(index + 1, node->previous);
    else return GetRecursively(index - 1, node->next);
}

/**
 * @brief Añade el nodo pasado por parámetro al inicio de la lista.
 */
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

/**
 * @brief Añade el nodo pasado por parámetro al final de la lista.
 */
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

/**
 * @brief Obtiene, elimina el primer nodo de la lista.
 * @return Node*
 */
Node *AvaiList::GetDeleteFirst() {

    if (first == nullptr) throw ("List is empty");

    Node* temp = first;
    first = first->next;
    temp->next = nullptr;

    if (first != nullptr) first->previous = nullptr;
    size--;
    return temp;

}

/**
 * @brief Obtiene el largo de la lista.
 * @return int
 */
int AvaiList::GetSize() {
    return size;
}



// MemoryList methods

/**
 * @brief Obtiene un nodo solicitado mediante el nombre de la variable que tiene guardada.
 * @return Node*
 */
Node *MemoryList::GetNodeOf(std::string varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first);
}

/**
 * @brief Obtiene un nodo solicitado mediante el nombre de la variable que tiene guardada, pasado por referencia.
 * @return Node*
 */
Node *MemoryList::GetNodeOfRef(std::string &varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first);
}

/**
 * @brief Busca el nodo recursivamente.
 * @return Node*
 */
Node *MemoryList::SearchForNodeByName(std::string& varName, Node *node, int index) {
    if (index == size) return NULL; // calls debugger that var is not declared

    else if (node->varName == varName) {
        node->references++;
        return node;
    }

    else return SearchForNodeByName(varName, node->next, index + 1);
}

/**
 * @brief Obtiene el puntero vacío al valor de una variable solicitada por su nombre.
 * @return void*
 */
void *MemoryList::GetValOf(std::string varName) {
    if (first == nullptr) throw ("List is empty.");

    else return SearchForNodeByName(varName, first)->value;
}

/**
 * @brief Añade un nodo a la lista con los valores de la variable que va a guardar.
 */
void MemoryList::AddFront(Node *newFirst, void *value, std::string& varName, std::string& varType, std::string& parentClass, std::string& structCode) {
    newFirst->value = value;
    newFirst->varName = varName;
    newFirst->varType = varType;
    newFirst->parentClass = parentClass;
    this->AddFirst(newFirst);
}

/**
 * @brief Cambia el valor de una variable mediante su nombre, con el nuevo valor pasado por parámetros.
 */
void MemoryList::ChangeValOf(std::string valName, void *newValue) {
    GetNodeOfRef(valName)->value = newValue;
}

/**
 * @brief Obtiene un nodo solicitado mediante el índice.
 * @return Node*
 */
Node *MemoryList::Get(int index) {
    return this->GetNode(index);
}

/**
 * @brief Obtiene el largo de la lista mediante un llamada al método de la clase padre.
 * @return int
 */
int MemoryList::Size() {
    return this->GetSize();
}

/**
 * @brief Obtiene, elimina y retorna el primer elemento de la lista mediante una llamada a su clase padre.
 * @return Node*
 */
Node *MemoryList::GetDelFirst() {
    return this->GetDeleteFirst();
}