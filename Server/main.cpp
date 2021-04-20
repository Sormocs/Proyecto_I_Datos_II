#include <iostream>
#include "Server.h"
#include "MemoryManager.h"
#include <thread>
#include "CodeParser.h"
using namespace std;
void RunServer(){

    Server::getInstance()->Start();
    std::cout << "Server Running" << std::endl;

}

void MemoryTests();

void ParseTest();

int main() {

    ParseTest();

//    std::thread RunS (RunServer);

//    RunS.join();

    return 0;
}

void ParseTest(){
//    CodeParser codeParser = CodeParser();
//
//    std::string buenas = "char patricio = 'a';";
//
//    codeParser.Declaration(buenas);
//
//    char data = *(char*)MemoryManager::Instance()->GetValOf("patricio");
//
//    std::cout << data << " " << std::endl;
//    //printf("Tamaño de Node: %lu\n", sizeof(void*));
    std::string asd;

    int usedMem = 0;

    void* mem = malloc(1024 * 1024);

    void* memoria = malloc(sizeof(void*)* 1024*1024*100);

    printf("Tamaño del puntero %lu.\n", sizeof(mem));

    int* entero1 = (int*)mem;
    usedMem += sizeof(int*);
    *entero1 = 54325;
    int* entero2 = (int*)((int*)mem + usedMem);
    usedMem += sizeof(int*);
    *entero2 = 123;
    int* entero3 = (int*)((int*)mem + usedMem);
    usedMem += sizeof(int*);
    *entero3 = 543;

    char* caracter1 = (char*)((char*)mem + usedMem);
    usedMem += sizeof(char*);
    *caracter1 = 'a';
    char* caracter2 = (char*)((char*)mem + usedMem);
    usedMem += sizeof(char*);
    *caracter2 = 'b';
    char* caracter3 = (char*)((char*)mem + usedMem);
    usedMem += sizeof(char*);
    *caracter3 = 'c';


    std::cout << entero1 << std::endl;
    std::cout << entero2 << std::endl;
    std::cout << entero3 << std::endl;

    std::cout << caracter1 << std::endl;
    std::cout << caracter2 << std::endl;
    std::cout << caracter3 << std::endl;

    std::cout << *entero1 << std::endl;
    std::cout << *entero2 << std::endl;
    std::cout << *entero3 << std::endl;

    std::cout << *caracter1 << std::endl;
    std::cout << *caracter2 << std::endl;
    std::cout << *caracter3 << std::endl;


    printf("Un puntero usa %lu bytes\n", sizeof(char*));

    std::cin >> asd;
}

void MemoryTests(){
    auto manager = MemoryManager();
}