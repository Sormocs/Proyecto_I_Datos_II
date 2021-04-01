//
// Created by tiquillo on 31/3/21.
//

#ifndef PROYECTO_I_DATOS_II_CODEPARSER_H
#define PROYECTO_I_DATOS_II_CODEPARSER_H

#include <string>
#include <iostream>

#define NOT_IN_STRING 18446744073709551615

class CodeParser {

private:
    std::string code;

    //float ExtractNumber(std::string numberStr);
    static float pow(float num, float power);
    static float negPow(float num, float power);
    int ToInt(char character);
    void ReverseStr(std::string& str);
    bool DotPos(std::string fragment, int& pos);

public:
    std::string AritmetricDetector(std::string codeFragment);

    float ExtractNumber(std::string numberStr);

    float Plus(std::string codeFragment);
    float Minus(std::string codeFragment);
    float Times(std::string codeFragment);
    float Division(std::string codeFragment);
    float Power(std::string codeFragment);

    bool Contains(std::string fragment, char character, int& position);
    bool Contains(std::string fragment, char character);
};


#endif //PROYECTO_I_DATOS_II_CODEPARSER_H
