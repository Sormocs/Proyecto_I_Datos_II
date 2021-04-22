//
// Created by tiquillo on 31/3/21.
//

#include "CodeParser.h"

CodeParser::CodeParser() {
    memMan = MemoryManager::Instance();
}

double CodeParser::AritmetricDetector(std::string& codeFragment) {
    double number = 0;

    if (ContainsChar(codeFragment, '+') or ContainsChar(codeFragment, '-')){
        number = AddSubtract(codeFragment);
    } else if (ContainsChar(codeFragment, '*')) number = Multiply(codeFragment);
    else if (ContainsChar(codeFragment,'/')) number = Division(codeFragment);
    else number = ExtractNumber(codeFragment);

    return number;
}

double CodeParser::AddSubtract(std::string codeFragment) {

    double result = 0;
    std::string numberStr;
    char sign = ' ';
    double numToOperator = 0;
    int signPos = NOT_IN_STRING;
    int plusPos = NOT_IN_STRING;
    int minusPos = NOT_IN_STRING;

    std::cout << "First code fragment: " << codeFragment << std::endl;

    if (ContainsChar(codeFragment, '+', plusPos) or ContainsChar(codeFragment, '-', minusPos)) {

        GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos);

        numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

    } else {
        numToOperator = ExtractNumber(codeFragment);
    }

    result += numToOperator;GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos);
    codeFragment = codeFragment.substr(signPos-1);

    while (true){

        std::cout << "En bucle. " << "code fragment: " << codeFragment << " result: " << result << std::endl;

        if (ContainsChar(codeFragment, '/', signPos) or ContainsChar(codeFragment, '*', signPos)) return NULL;
        else if (ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) {

            std::cout << "En operación." << std::endl;

            GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos);

            sign = codeFragment.at(signPos);

            std::cout << "Sign: " << sign << std::endl;

            DelAddSubSign(codeFragment, minusPos, plusPos, signPos);

            if (!GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) signPos = -1;

            std::cout << "Code fragment: " << codeFragment << std::endl;
            std::cout << "StrNumber to add: " << codeFragment.substr(0, signPos) << std::endl;

            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

            std::cout << "Number to add: " << numToOperator << std::endl;

            if (sign == '+') result += numToOperator;
            else result -= numToOperator;
        }

        else break;

        if (GetAddSubSignPos(codeFragment,minusPos, plusPos, signPos)) {
            std::cout << "Eliminación al final del while. Se eliminará: " << codeFragment.substr(0, signPos) << std::endl;
            codeFragment = codeFragment.substr(signPos);
        }
        else break;
    }
    return result;
}

double CodeParser::Multiply(std::string codeFragment) {
    double result = 0;
    std::string numberStr;
    double numToOperator = 0;
    int signPos = NOT_IN_STRING;

    std::cout << "First code fragment: " << codeFragment << std::endl;

    if (GetDivSignPos(codeFragment, signPos) or ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) return NOT_VALID_OPERATION;

    if (ContainsChar(codeFragment, '*', signPos)) {

        numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

    } else {
        numToOperator = ExtractNumber(codeFragment);
    }

    result = numToOperator;
    if (GetMultSignPos(codeFragment, signPos)) codeFragment = codeFragment.substr(signPos-1);

    while (true){

        std::cout << "En bucle. " << "code fragment: " << codeFragment << " result: " << result << std::endl;

        if (ContainsChar(codeFragment, '*', signPos)) {

            std::cout << "En operación." << std::endl;

            codeFragment = codeFragment.substr(signPos+1);

            if (!GetMultSignPos(codeFragment, signPos)) signPos = -1;

            std::cout << "Code fragment: " << codeFragment << std::endl;

            std::cout << "StrNumber to add: " << codeFragment.substr(0, signPos) << std::endl;
            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));
            std::cout << "Number to add: " << numToOperator << std::endl;

            result *= ExtractNumber(codeFragment.substr(0, signPos));
        }

        else break;

        if (GetMultSignPos(codeFragment, signPos)) {
            std::cout << "Eliminación al final del while. Se eliminará: " << codeFragment.substr(0, signPos) << std::endl;
            codeFragment = codeFragment.substr(signPos);
        }
        else break;
    }
    return result;
}

double CodeParser::Division(std::string codeFragment) {
    double result = 0;
    std::string numberStr;
    double numToOperator = 0;
    int signPos = NOT_IN_STRING;

    std::cout << "First code fragment: " << codeFragment << std::endl;

    if (GetMultSignPos(codeFragment, signPos) or ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) return NOT_VALID_OPERATION;

    if (GetDivSignPos(codeFragment, signPos)) {

        numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

    } else {
        numToOperator = ExtractNumber(codeFragment);
    }

    result = numToOperator;
    if (GetMultSignPos(codeFragment, signPos)) codeFragment = codeFragment.substr(signPos-1);

    while (true){

        std::cout << "En bucle. " << "code fragment: " << codeFragment << " result: " << result << std::endl;

        if (GetDivSignPos(codeFragment, signPos)) {

            std::cout << "En operación." << std::endl;

            codeFragment = codeFragment.substr(signPos+1);

            if (!GetDivSignPos(codeFragment, signPos)) signPos = -1;

            std::cout << "Code fragment: " << codeFragment << std::endl;

            std::cout << "StrNumber to add: " << codeFragment.substr(0, signPos) << std::endl;
            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));
            std::cout << "Number to add: " << numToOperator << std::endl;

            result /= ExtractNumber(codeFragment.substr(0, signPos));
        }

        else break;

        if (GetDivSignPos(codeFragment, signPos)) {
            std::cout << "Eliminación al final del while. Se eliminará: " << codeFragment.substr(0, signPos) << std::endl;
            codeFragment = codeFragment.substr(signPos);
        }
        else break;
    }
    return result;
}

double CodeParser::ExtractNumber(std::string numberStr) {

    int power = 0;                                  // power for number positions
    int dotPos;                                     // position of the dot char
    double number = 0;                               // the number converted on float type
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

double CodeParser::pow(float num, float power) {

    if (power < 0) return 1/negPow(num, power);     // calls the negative power function and gives the fraction of 1/power

    else if (power == 0) return 1;                  // power of 0 of any number is always 1

    else if (power == 1) return num;                // power of 1 of any number is always the number

    else return num * pow(num, power - 1);   // gives power by recursion
}

double CodeParser::negPow(float num, float power) {
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

        if (fragment.at(i) == '.' or fragment.at(i) == ',') {                // saves dot positions and returns true
            pos = i;
            return true;
        }
    }
    return false;
}

bool CodeParser::ContainsChar(std::string& fragment, char character, int &position) {
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

bool CodeParser::ContainsChar(std::string& fragment, char character) {
    /* Checks if a string contains a character
     */

    for (char i : fragment) if (i == character) return true;
    return false;
}

void CodeParser::DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos) {
    if (GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) codeFragment = codeFragment.substr(signPos+1);
}

bool CodeParser::GetAddSubSignPos(std::string &codeFragment, int &minusPos, int &plusPos, int &signPos) {
    ContainsChar(codeFragment, '-', minusPos);
    ContainsChar(codeFragment, '+', plusPos);

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

bool CodeParser::GetMultSignPos(std::string& codeFragment, int &timesPos) {
    return ContainsChar(codeFragment, '*', timesPos);
}

bool CodeParser::GetDivSignPos(std::string &codeFragment, int &divPos) {
    return ContainsChar(codeFragment, '/', divPos);
}

bool CodeParser::ContainsStr(std::string &text, std::string fragment, int &position, int &lenght) {

    int fragIter = 0;                        // initializes fragment iterator
    lenght = fragment.length();             // asigns length to fragment lenght
    for (int i = 0; i < text.length(); i++){

        if (text.at(i) == fragment.at(fragIter)){

            if (fragIter == 0) position = i;

            fragIter++;

        } else { position = NOT_IN_STRING; fragIter = 0; }

        if (fragIter == lenght) return true;
    }

    lenght = NOT_IN_STRING;
    return false;
}

bool CodeParser::ContainsStr(std::string &text, std::string fragment) {
    int lenght = NOT_IN_STRING;
    int position = NOT_IN_STRING;

    return ContainsStr(text, fragment, position, lenght);
}

bool CodeParser::Declaration(std::string& line, char reference) {
    std::string types[] = {"int", "long", "float", "double", "char"};
    std::string asignation;
    int position = NOT_IN_STRING;
    int lenght = NOT_IN_STRING;

    for (std::string type : types) {                    // esto no incluye struct ni reference

        if (ContainsStr(line, type, position, lenght)) {

            if (Asignation(line.substr(position + lenght), type)) return true;
        }
    }
    return false;
}

bool CodeParser::Declaration(std::string line) {
    return Declaration(line, 2);
}

bool CodeParser::Asignation(std::string asignation, std::string& type) {
    int position = NOT_IN_STRING;
    std::string varName;
    if (ContainsChar(asignation, '=', position)) {      // revisa que '=' esté en la cadena. Si no esta, no es una asignacion.

        if (type == "int" or type == "long" or type == "float" or type == "double") {

            varName = asignation.substr(0, position);
            DeleteSpaces(varName);

            std::string strToDetectAritmetricOperatorsXD = asignation.substr(position + 1);

            memMan->Add(AsignNum(AritmetricDetector(strToDetectAritmetricOperatorsXD), type), varName, type);


        } else if (type == "char"){
            varName = asignation.substr(0, position);
            DeleteSpaces(varName);

            std::string str = asignation.substr(position + 1);
            memMan->Add(AsignChar(str), varName, "char");

        }

        return true;

    } else if (ContainsChar(asignation,  '{', position)){
        if (type == "struct")

    } else return false;
}

void CodeParser::GetFirstNumPos(std::string &codeBlock, int &position) {

    for (int i = 0; i < codeBlock.length(); ++i) {

        if (isdigit(codeBlock.at(i))) {

            position = i;
            return;
        }
    }
}

void* CodeParser::AsignNum(double num, std::string type) {
    if (type == "int") return (void*) new int ((int) num);
    else if (type == "long") return (void*) new long ((long) num);
    else if (type == "float") return (void*) new float ((float) num);
    else if (type == "double") return (void*) new double ((double) num);
}

void CodeParser::DeleteSpaces(std::string &text) {
    std::string newText = "";

    for (char character : text){
        if (character == ' ') continue;
        newText += character;
    }
    text = newText;
}

void *CodeParser::AsignChar(std::string fragment) {

    int position = NOT_IN_STRING;

    ContainsChar(fragment, '\'', position);
    fragment = fragment.substr(position + 1);
    ContainsChar(fragment, '\'', position);
    printf("El caracter es %s y la posición es %d\n", fragment.substr(0,1).c_str(), position);
    fragment = fragment.substr(0, position);

    if (fragment.length() != 1); // CALLS DEBUGGER

    return (void*) new char ((char)fragment.at(0));
}

void CodeParser::SkipSpaces(std::string &text, int &position) {
    position = 0;

    for (char ch : text){

        if (ch == ' ') position++;
        else return;
    }
    position = NOT_IN_STRING;
}
