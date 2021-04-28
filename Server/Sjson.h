#pragma once
#include "json.hpp"
#include "MemoryManager.h"

using json = nlohmann::json;

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



