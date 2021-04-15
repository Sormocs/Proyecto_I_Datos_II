#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>

#include "CodeParser.h"
#include "MemoryManager.h"
#include "MemoryList.h"



int main()
{

    MemoryManager memoryManager = MemoryManager();

    int value = 25;

    memoryManager.AddVar(value, "veinticinco");
    memoryManager.AddVar(1, "uno");
    memoryManager.AddVar(2, "dos");

    std::cout << std::endl << std::endl;

    std::cout << memoryManager.GetAddress("veinticinco") << std::endl;

//    memoryManager.usedMem->GetNodeOf("veinticinco");

    std::cout << std::endl << std::endl;
    return 0;
}