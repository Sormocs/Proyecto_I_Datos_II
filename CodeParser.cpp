//
// Created by tiquillo on 31/3/21.
//

#include "CodeParser.h"

std::string CodeParser::AritmetricDetector(std::string codeFragment) {
    std::string tempStr = codeFragment;
    int charPos;
    float number = 0;
}

float CodeParser::AddSubtract(std::string codeFragment) {

    float result = 0;
    std::string tempStr = codeFragment;
    std::string numberStr;
    int signPos = NOT_IN_STRING;
    int plusPos = NOT_IN_STRING;
    int minusPos = NOT_IN_STRING;

    if (Contains(codeFragment, '+', plusPos) or Contains(codeFragment, '-', minusPos)) {

        GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos);

        result = ExtractNumber(codeFragment.substr(0, signPos));
        std::cout << "En asignación." << std::endl;

    } else {
        result = ExtractNumber(codeFragment);
    }

    std::cout << "Code fragment: " << codeFragment << std::endl;

    while (true){

        std::cout << "En bucle de sumaResta. " << "Posición de + " << signPos << " tempStr: " << tempStr << std::endl;

        if (Contains(codeFragment, '+', plusPos)) {

            DelAddSubSign(codeFragment, minusPos, plusPos, signPos);

            std::cout << "Code fragment: " << codeFragment << std::endl;

            if (!GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) result += ExtractNumber(codeFragment);

            else result += ExtractNumber(tempStr.substr(0, signPos));

            std::cout << "En suma." << std::endl;

        }else if (Contains(tempStr, '-', signPos)) {
            DelAddSubSign(codeFragment, minusPos, plusPos, signPos);

            std::cout << "Code fragment: " << codeFragment << std::endl;

            if (!GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) result += ExtractNumber(codeFragment);

            else result -= ExtractNumber(tempStr.substr(0, signPos));
            std::cout << "En resta." << std::endl;

        } else if (Contains(tempStr, '/', signPos) or Contains(tempStr, '*', signPos)) return NULL;

        else break;

        DelAddSubSign(codeFragment,minusPos, plusPos, signPos);
    }
    return result;
}

float CodeParser::Multiply(std::string codeFragment) {
    return 0;
}

float CodeParser::Division(std::string codeFragment) {
    return 0;
}

float CodeParser::Power(std::string codeFragment) {
    return 0;
}

float CodeParser::ExtractNumber(std::string numberStr) {

    int power = 0;                                  // power for number positions
    int dotPos;                                     // position of the dot char
    float number = 0;                               // the number converted on float type
    bool isFloat = DotPos(numberStr, dotPos);    // isFloat says if number is float or not
    std::string num;

    // extrae el número si es entero
    if (!isFloat) {
        ReverseStr(numberStr);                   // Reverses the number for correct conversion

        for (char i : numberStr){
            if (isdigit(i)) {
                number += ToInt(i)*pow(10, power); // Adds the number to the float type
                power++;
            }
        }
        return number;
    }

    // extrae unidades
    num = numberStr.substr(0, dotPos);          // Saves a temp with string before the dot
    ReverseStr(num);                             // Reverses the number for correct conversion

    for (char i : num){
        if (isdigit(i)) {
            number += ToInt(i)*pow(10, power);  // Adds the number to the float type
            power++;
        }
    }

    // extrae fraccionales
    num = numberStr.substr(dotPos);                 // Saves a temp with string before the dot
    power = -1;                                     // Fractions start with negative power

    for (char i : num){
        if (isdigit(i)) {
            number += ToInt(i)*pow(10, power); // Adds the number to the float type
            power--;
        }
    }

    return number;
}

float CodeParser::pow(float num, float power) {

    if (power < 0) return 1/negPow(num, power);     // calls the negative power function and gives the fraction of 1/power

    else if (power == 0) return 1;                  // power of 0 of any number is always 1

    else if (power == 1) return num;                // power of 1 of any number is always the number

    else return num * pow(num, power - 1);   // gives power by recursion
}

float CodeParser::negPow(float num, float power) {
    if (power == -1) return num;                    // when power is -1, the negative power ended

    else return num * negPow(num, power + 1); // gives power by recursion
}

int CodeParser::ToInt(char character) {
    return (int) character - 48;                    // converts char to int, subtracting 48 because of ASCII conversion
}

void CodeParser::ReverseStr(std::string& str) {
    int lenght = str.length();

    for (int i = 0; i < lenght / 2; i++)
        std::swap(str[i], str[lenght - i - 1]); // swaps borders towards the middle
}

bool CodeParser::DotPos(std::string fragment, int& pos) {
    for (int i = 0; i < fragment.length(); i++) {
        if (fragment.at(i) == ',') return false; // should stop

        if (fragment.at(i) == '.') {                // saves dot positions and returns true
            pos = i;
            return true;
        }
    }
    return false;
}

bool CodeParser::Contains(std::string fragment, char character, int &position) {
    /* Checks if a string contains a character and assigns the position by reference
     */

    for (int i = 0; i < fragment.length(); i++) {
        if (fragment.at(i) == character) {
            position = i;
            return true;
        }
    }
    position = NOT_IN_STRING;
    return false;
}

bool CodeParser::Contains(std::string fragment, char character) {
    /* Checks if a string contains a character
     */

    for (char i : fragment) if (i == character) return true;
    return false;
}

void CodeParser::DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos) {
    if (GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) codeFragment = codeFragment.substr(signPos+1);
}

bool CodeParser::GetAddSubSignPos(std::string &codeFragment, int &minusPos, int &plusPos, int &signPos) {
    Contains(codeFragment, '-', minusPos);
    Contains(codeFragment, '+', plusPos);

    if (minusPos == plusPos) return false;

    if (minusPos < plusPos){
        if (minusPos == NOT_IN_STRING) signPos = plusPos;
        else signPos = minusPos;
    } else {
        if (plusPos == NOT_IN_STRING) signPos = minusPos;
        else signPos = plusPos;
    }

    return true;
}
