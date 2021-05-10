/**
 * @file Sjson.h
 * @author Sergio MB
 * @brief Definicion de metodos de la clase Sjson.
 */

#include "Sjson.h"

Sjson* Sjson::instance = nullptr;

/**
 * @brief Constructor de la clase, asigna a num un 0 como valor inicial.
 */
Sjson::Sjson() {
    num = 0;
}

/**
 * @brief Agrega al objeto json una variable nueva con sus respectivos valores, y finalmente aumenta el numero de variable.
 * @param type
 * @param val
 * @param address
 * @param refs
 */

void Sjson::AddVar(std::string type, std::string val, std::string address, std::string refs) {

    obj["num"+std::to_string(num)]["type"] = type;
    obj["num"+std::to_string(num)]["value"] = val;
    obj["num"+std::to_string(num)]["address"] = address;
    obj["num"+std::to_string(num)]["refs"] = refs;
    num++;

}

/**
 * @brief Retorna el objeto json
 * @return
 */
json Sjson::GetObj() {

    return obj;
}

/**
 * @brief Obtiene los valores de la lista de memoria meterlos en el objeto json y llenar el AddVar.
 */
void Sjson::ObtainVals() {

    MemoryList* memL = MemoryManager::Instance()->GetList();
    int i = memL->Size()-1;

    for (i; i != -1; i--){

        std::string name = memL->Get(i)->varName;
        std::string addr = memL->Get(i)->GetAddress();
        std::string refs = std::to_string(memL->Get(i)->references);
        std::string val = " ";
        if (memL->Get(i)->varType == "int") val = std::to_string(*(int*)memL->Get(i)->value);
        else if (memL->Get(i)->varType == "long") val = std::to_string(*(long*)memL->Get(i)->value);
        else if (memL->Get(i)->varType == "char") val = std::to_string(*(char*)memL->Get(i)->value);
        else if (memL->Get(i)->varType == "double") val = std::to_string(*(double*)memL->Get(i)->value);
        else if (memL->Get(i)->varType == "float") val = std::to_string(*(float*)memL->Get(i)->value);
        else if (memL->Get(i)->varType == "struct") val = *(std::string*)memL->Get(i)->value;

        AddVar(name,val,addr,refs);

    }



}

/**
 * @brief Obtiene la instancia de la clase ya que es un singleton.
 * @return
 */
Sjson *Sjson::getInstance() {
    if (instance == nullptr){
        instance = new Sjson;
    }
    return instance;
}

/**
 * @brief Vacia el objeto json y resetea la cuenta del numero.
 */
void Sjson::Reset() {
    obj.clear();
    num = 0;
}
