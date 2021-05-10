/**
 * @file CodeParser.h
 * @author Luis Delgado
 * @brief Definicion de métodos de la clase MemoryManager.
 */

#include <iostream>
#include "MemoryManager.h"

MemoryManager* MemoryManager::instance = nullptr;

/**
 * @brief Crea los 10 MB de memoria inicial en el constructor del administrador de memoria.
 */
MemoryManager::MemoryManager() {
    /*
     * Asigns 10 MB of memory at the begginning of the run
     */

    usedMem = new MemoryList();
    XMB = new AvaiList();

    for (int i = 0; i < 10240; i++){
        XMB->AddFirst((Node*)malloc(1024));
    }
}

/**
 * @brief Obtiene la dirección de memoria de un nodo.
 * @return string
 */
std::string MemoryManager::GetAddress(std::string varName) {
    std::ostringstream address;
    address << usedMem->GetNodeOf(varName);
    return address.str();
}

/**
 * @brief Obtiene el tipo de una variable almacenada en un nodo solicitada por su nombre.
 * @return string
 */
std::string MemoryManager::GetType(std::string varName) {
    return usedMem->GetNodeOf(varName)->varType;
}

/**
 * @brief Crea una instancia del admnistrador de memoria si no existe una y la retorna si existe. Es parte del sigleton.
 * @return MemoryManager*
 */
MemoryManager* MemoryManager::Instance() {
    if (instance == nullptr) instance = new MemoryManager();
    return instance;
}

/**
 * @brief Añade una variable a la memoria en uso y en su proceso, solicita un nodo disponible a la lista con memoria libre.
 */
void MemoryManager::Add(void *value, std::string varName, std::string varType, std::string& parentClass) {
    usedMem->AddFront(XMB->GetDeleteFirst(), value, varName, varType, parentClass);
}

/**
 * @brief Obtiene el valor de una variable almacenada en un nodo.
 * @return void*
 */
void *MemoryManager::GetValOf(std::string varName) {
    return usedMem->GetNodeOfRef(varName)->value;
}

/**
 * @brief Obtiene el valor de una variable entera almacenada en un nodo.
 * @return int
 */
int MemoryManager::GetValOfInt(std::string varName) {
    return *(int*) GetValOf(std::move(varName));
}

/**
 * @brief Obtiene el valor de una variable entera de gran tamaño almacenada en un nodo.
 * @return long
 */
long MemoryManager::GetValOfLong(std::string varName) {
    return *(long*) GetValOf(std::move(varName));
}

/**
 * @brief Obtiene el valor de una variable de punto flotante almacenada en un nodo.
 * @return float
 */
float MemoryManager::GetValOfFloat(std::string varName) {
    return *(float*) GetValOf(std::move(varName));
}

/**
 * @brief Obtiene el valor de una variable de punto flotante de gran tamaño almacenada en un nodo.
 * @return double
 */
double MemoryManager::GetValOfDouble(std::string varName) {
    return *(double*) GetValOf(std::move(varName));
}

/**
 * @brief Obtiene el valor de una variable char almacenada en un nodo.
 * @return char
 */
char MemoryManager::GetValOfChar(std::string varName) {
    return *(char*) GetValOf(std::move(varName));
}

/**
 * @brief Obtiene el valor de una variable struct almacenada en un nodo.
 * @return stirng
 */
std::string MemoryManager::GetValOfStruct(std::string varName) {
    return *(std::string*) GetValOf(std::move(varName));
}

/**
 * @brief Retorna un puntero la lista de memoria en uso.
 * @return MemoryList*
 */
MemoryList *MemoryManager::GetList() {
    return usedMem;
}

/**
 * @brief Limpia la lista enlazada con la memoria utilizada.
 */
void MemoryManager::Restart() {
    while(usedMem->Size()){
        delete usedMem->GetDelFirst();
    }
}

/**
 * @brief Averigua si existe una variable con el nombre pasado por parámetros.
 * @return bool
 */
bool MemoryManager::IsVariable(const std::string& name) {
    for (int i = 0; i < usedMem->Size(); ++i) {
        if (usedMem->Get(i)->varName == name) return true;
    }
    return false;
}
