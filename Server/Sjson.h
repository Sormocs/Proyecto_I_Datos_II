/**
 * @file Sjson.h
 * @author Sergio MB
 * @brief Clase para parsear y crear objetos json
 */

#pragma once
#include "json.hpp"
#include "MemoryManager.h"

using json = nlohmann::json;

/**
 * @brief Clase que crea el json y hace posible utilizar el objeto para el futuro. Obtenido del json.hpp de nlohmann en github.
 */
class Sjson {
private:
    int num;
    json obj;
    static Sjson* instance;

public:
    Sjson();
    static Sjson* getInstance();
    void AddVar(std::string, std::string, std::string, std::string);
    void ObtainVals();
    json GetObj();
    void Reset();

};



