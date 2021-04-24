//
// Created by tiquillo on 31/3/21.
//

#ifndef PROYECTO_I_DATOS_II_CODEPARSER_H
#define PROYECTO_I_DATOS_II_CODEPARSER_H

#include <string>
#include <iostream>

#include "MemoryManager.h"
#include "TextList.h"

#define NOT_IN_STRING -00100000
#define NOT_VALID_OPERATION -90108020703060405

class CodeParser {

private:
    MemoryManager* memMan;
    std::string fullCode;

    // arithmetic operations
    double AddSubtract(std::string codeFragment);
    double Multiply(std::string codeFragment);
    double Division(std::string codeFragment);

    // arithmetic logic
    double AritmetricDetector(std::string& codeFragment);
    double ExtractNumber(std::string numberStr);
    bool DotPos(std::string fragment, int& pos);
    static double pow(float num, float power);
    static double negPow(float num, float power);
    int ToInt(char character);
    void GetFirstNumPos(std::string& codeBlock, int& position);

    // arithmetic sign
    void DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);
    bool GetAddSubSignPos(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);
    bool GetMultSignPos(std::string& codeFragment, int& timesPos);
    bool GetDivSignPos(std::string& codeFragment, int& divPos);


    // Code recognition
    void CodePartition(std::string code);

    // syntax checker
    bool CheckSemicolon(std::string& line);
    bool PartOfStruct(std::string& line);

    // variable declaration and value assignation
    bool Assignation(std::string assignation, std::string& type, std::string parentClass = "Main", std::string structCode = " ");
    void* AssignNum(double num, std::string type);
    void* AssignChar(std::string fragment);


    // text manipulation
    void DeleteSpaces(std::string& text);
    void ReverseStr(std::string& str);
    void SkipSpaces(std::string& text, int& position);

    // struct type detection, manipulation and declaration
    std::string GetFullStruct(std::string& fullStruct);
    std::string GetStructName(std::string& fullStruct);
    Node* AssignStruct(std::string fragment);

    // debugger Call
    void Debug(std::string);

protected:
    static CodeParser* instance;
    explicit CodeParser(MemoryManager* memoryManager);

public:
    CodeParser() = delete;

    static CodeParser* Instance();

    void SetFullCode(std::string fullCode);

    bool ContainsChar(std::string& fragment, char character, int& position);
    bool ContainsChar(std::string& fragment, char character);

    bool ContainsStr(std::string& text, std::string fragment, int& position, int& lenght);
    bool ContainsStr(std::string& text, std::string fragment, int& position);
    bool ContainsStr(std::string& text, std::string fragment);

    bool Declaration(std::string line);
};


#endif //PROYECTO_I_DATOS_II_CODEPARSER_H
