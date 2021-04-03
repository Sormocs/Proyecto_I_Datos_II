//
// Created by tiquillo on 31/3/21.
//

#ifndef PROYECTO_I_DATOS_II_CODEPARSER_H
#define PROYECTO_I_DATOS_II_CODEPARSER_H

#include <string>
#include <iostream>

#define NOT_IN_STRING -101010101

class CodeParser {

private:
    std::string fullCode;

    //float ExtractNumber(std::string numberStr);
    static float pow(float num, float power);
    static float negPow(float num, float power);
    int ToInt(char character);
    void ReverseStr(std::string& str);
    bool DotPos(std::string fragment, int& pos);


    bool GetAddSubSignPos(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);

public:
    std::string AritmetricDetector(std::string codeFragment);

    void DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos);

    float ExtractNumber(std::string numberStr);

    float AddSubtract(std::string codeFragment);
    float Multiply(std::string codeFragment);
    float Division(std::string codeFragment);
    float Power(std::string codeFragment);

    bool Contains(std::string fragment, char character, int& position);
    bool Contains(std::string fragment, char character);
};


#endif //PROYECTO_I_DATOS_II_CODEPARSER_H
