//
// Created by tiquillo on 31/3/21.
//

#include "CodeParser.h"

std::string CodeParser::AritmetricDetector(std::string codeFragment) {
    return std::string();
}

float CodeParser::Plus(std::string codeFragment) {
    float plus = 0;
    std::string tempStr = codeFragment;
    std::string numberStr;
    size_t charPos;

    while (true){
        charPos = tempStr.find("+");

        if (charPos == NOT_IN_STRING){
            break;

        } else{
            plus += ExtractNumber(tempStr.substr(0 , charPos));

        }
    }
    return plus;
}

float CodeParser::Minus(std::string codeFragment) {
    return 0;
}

float CodeParser::Times(std::string codeFragment) {
    return 0;
}

float CodeParser::Division(std::string codeFragment) {
    return 0;
}

float CodeParser::Power(std::string codeFragment) {
    return 0;
}

float CodeParser::ExtractNumber(std::string numberStr) {

    int power = 0;
    int dotPos;
    float number = 0;
    bool isFloat = DotPos(numberStr, dotPos); // isFloat says if number is float or not
    std::string num;

    // extrae el número si es entero
    if (!isFloat) {
        ReverseStr(numberStr);

        for (char i : numberStr){
            if (isdigit(i)) {
                number += ToInt(i)*pow(10, power);
                power++;
            }
        }
        return number;
    }

    // extrae unidades
    num = numberStr.substr(0, dotPos);
    ReverseStr(num);

    for (char i : num){
        if (isdigit(i)) {
            number += ToInt(i)*pow(10, power);
            power++;
        }
    }

    // extrae fraccionales
    num = numberStr.substr(dotPos);
    power = -1;

    for (char i : num){
        if (isdigit(i)) {
            number += ToInt(i)*pow(10, power);
            power--;
        }
    }

    return number;
}

float CodeParser::pow(float num, float power) {

    if (power < 0) return 1/negPow(num, power);

    else if (power == 0) return 1;

    else if (power == 1) return num;

    else return num * pow(num, power - 1);
}

float CodeParser::negPow(float num, float power) {
    if (power == -1) return num;

    else return num * negPow(num, power + 1);
}

int CodeParser::ToInt(char character) {
    return (int) character - 48;
}

void CodeParser::ReverseStr(std::string& str) {
    int lenght = str.length();

    for (int i = 0; i < lenght / 2; i++)
        std::swap(str[i], str[lenght - i - 1]);
}

bool CodeParser::DotPos(std::string fragment, int& pos) {
    for (int i = 0; i < fragment.length(); i++) {
        if (fragment.at(i) == ',') continue; // should stop
        if (fragment.at(i) == '.') {
            pos = i;
            return true;
        }
    }
    return false;
}

bool CodeParser::Contains(std::string fragment, char character, int &position) {
    for (int i = 0; i < fragment.length(); i++) {
        if (fragment.at(i) == character) {
            position = i;
            return true;
        }
    }
    return false;
}

bool CodeParser::Contains(std::string fragment, char character) {
    for (char i : fragment) if (i == character) return true;
    return false;
}
