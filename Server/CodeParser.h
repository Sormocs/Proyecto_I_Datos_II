//
// Created by tiquillo on 31/3/21.
//

#ifndef PROYECTO_I_DATOS_II_CODEPARSER_H
#define PROYECTO_I_DATOS_II_CODEPARSER_H

#include <string>
#include <iostream>

#define NOT_IN_STRING -00100000
#define NOT_VALID_OPERATION -90108020703060405

class CodeParser {

private:
    std::string fullCode;

    double ExtractNumber(std::string numberStr);
    static double pow(float num, float power);
    static double negPow(float num, float power);
    int ToInt(char character);
    void ReverseStr(std::string& str);
    bool DotPos(std::string fragment, int& pos);

    void DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);
    bool GetAddSubSignPos(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);

    bool GetMultSignPos(std::string& codeFragment, int& timesPos);

    bool GetDivSignPos(std::string& codeFragment, int& divPos);

public:
    double AritmetricDetector(std::string& codeFragment);



    double AddSubtract(std::string codeFragment);
    double Multiply(std::string codeFragment);
    double Division(std::string codeFragment);

    bool ContainsChar(std::string& fragment, char character, int& position);
    bool ContainsChar(std::string& fragment, char character);

    bool ContainsStr(std::string& text, std::string fragment, int& position, int& lenght);
    bool ContainsStr(std::string& text, std::string fragment);

    bool Declaration(std::string& line);

    bool Asignation(std::string asignation, std::string& type);

    void GetFirstNumPos(std::string& codeBlock, int& position);

    void* AsignNum(double num);

    void DeleteSpaces(std::string& text);
};


#endif //PROYECTO_I_DATOS_II_CODEPARSER_H
