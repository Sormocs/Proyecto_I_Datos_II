//
// Created by tiquillo on 31/3/21.
//

#include "CodeParser.h"

#include <utility>

CodeParser* CodeParser::instance = nullptr;

CodeParser::CodeParser(MemoryManager* memoryManager) {
    this->memMan = memoryManager;
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
    int signPos = NOT_STRING_POS_OR_LENGHT;
    int plusPos = NOT_STRING_POS_OR_LENGHT;
    int minusPos = NOT_STRING_POS_OR_LENGHT;

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

        if (ContainsChar(codeFragment, '/', signPos) or ContainsChar(codeFragment, '*', signPos)) return NULL;
        else if (ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) {

            GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos);

            sign = codeFragment.at(signPos);

            DelAddSubSign(codeFragment, minusPos, plusPos, signPos);

            if (!GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) signPos = -1;

            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

            if (sign == '+') result += numToOperator;
            else result -= numToOperator;
        }
        else break;

        if (GetAddSubSignPos(codeFragment,minusPos, plusPos, signPos)) {
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
    int signPos = NOT_STRING_POS_OR_LENGHT;

    if (GetDivSignPos(codeFragment, signPos) or ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) return NOT_VALID_OPERATION;

    if (ContainsChar(codeFragment, '*', signPos)) {

        numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

    } else {
        numToOperator = ExtractNumber(codeFragment);
    }
    result = numToOperator;
    if (GetMultSignPos(codeFragment, signPos)) codeFragment = codeFragment.substr(signPos-1);

    while (true){

        if (ContainsChar(codeFragment, '*', signPos)) {

            codeFragment = codeFragment.substr(signPos+1);

            if (!GetMultSignPos(codeFragment, signPos)) signPos = -1;

            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

            result *= ExtractNumber(codeFragment.substr(0, signPos));
        }
        else break;

        if (GetMultSignPos(codeFragment, signPos)) {
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
    int signPos = NOT_STRING_POS_OR_LENGHT;

    if (GetMultSignPos(codeFragment, signPos) or ContainsChar(codeFragment, '+', signPos) or ContainsChar(codeFragment, '-', signPos)) return NOT_VALID_OPERATION;

    if (GetDivSignPos(codeFragment, signPos)) {

        numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

    } else {
        numToOperator = ExtractNumber(codeFragment);
    }
    result = numToOperator;
    if (GetMultSignPos(codeFragment, signPos)) codeFragment = codeFragment.substr(signPos-1);

    while (true){

        if (GetDivSignPos(codeFragment, signPos)) {

            codeFragment = codeFragment.substr(signPos+1);

            if (!GetDivSignPos(codeFragment, signPos)) signPos = -1;

            numToOperator = ExtractNumber(codeFragment.substr(0, signPos));

            result /= ExtractNumber(codeFragment.substr(0, signPos));
        }
        else break;

        if (GetDivSignPos(codeFragment, signPos)) {
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

    if (MemoryManager::Instance()->IsVariable(numberStr)) {
        Node* temp = MemoryManager::Instance()->GetList()->GetNodeOfRef(numberStr);
        temp->references--;
        if (temp->varType == INT) return (double) MemoryManager::Instance()->GetValOfInt(numberStr);
        else if (temp->varType == LONG) return (double) MemoryManager::Instance()->GetValOfLong(numberStr);
        else if (temp->varType == FLOAT) return (double) MemoryManager::Instance()->GetValOfFloat(numberStr);
        else if (temp->varType == DOUBLE) return MemoryManager::Instance()->GetValOfDouble(numberStr);
        else Debug("Error in line " + std::to_string(lineNum) + ". You cannot add " + temp->varType + " to a number.");

    }

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
    } else Debug("Error in line " + std::to_string(lineNum) + ". " + numberStr + " does not match any value or variable.");

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
    position = NOT_STRING_POS_OR_LENGHT;
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
        if (minusPos == NOT_STRING_POS_OR_LENGHT) signPos = plusPos;
        else signPos = minusPos;
    } else {
        if (plusPos == NOT_STRING_POS_OR_LENGHT) signPos = minusPos;
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

        } else { position = NOT_STRING_POS_OR_LENGHT; fragIter = 0; }

        if (fragIter == lenght) return true;
    }

    lenght = NOT_STRING_POS_OR_LENGHT;
    return false;
}

bool CodeParser::ContainsStr(std::string &text, std::string fragment) {
    int lenght = NOT_STRING_POS_OR_LENGHT;
    int position = NOT_STRING_POS_OR_LENGHT;

    return ContainsStr(text, std::move(fragment), position, lenght);
}

bool CodeParser::ContainsStr(std::string &text, std::string fragment, int &position) {
    int lenght = NOT_STRING_POS_OR_LENGHT;
    return ContainsStr(text, std::move(fragment), position, lenght);
}

bool CodeParser::Declaration(std::string& line, std::string& parentClass) {
//    std::string types[] = {INT, LONG, FLOAT, DOUBLE, CHAR, STRUCT};
    std::string asignation;
    int position = NOT_STRING_POS_OR_LENGHT;
    int lenght = NOT_STRING_POS_OR_LENGHT;

    for (std::string type : VAR_TYPES) {                    // esto no incluye reference

        if (ContainsStr(line, type, position, lenght)) {

            if (Assignation(line.substr(position + lenght), type, parentClass)) return true;
        }
    }
    if (position == NOT_STRING_POS_OR_LENGHT) {
        Debug("Introduced type in line " + std::to_string(lineNum) + " does not match any");
        return false;
    }

    return false;
}


bool CodeParser::Assignation(std::string assignation, std::string& type, std::string parentClass, std::string structCode) {
    int position = NOT_STRING_POS_OR_LENGHT;
    std::string varName;
    if (ContainsChar(assignation, '=', position)) {      // revisa que '=' esté en la cadena. Si no esta, no es una asignacion numérica o de char.

        if (type == INT or type == LONG or type == FLOAT or type == DOUBLE) {

            varName = assignation.substr(0, position);
            DeleteSpaces(varName);

            std::string strToDetectAritmetricOperators = assignation.substr(position + 1);

            memMan->Add(AssignNum(AritmetricDetector(strToDetectAritmetricOperators), type), varName, type, parentClass, structCode);

        } else if (type == CHAR){
            varName = assignation.substr(0, position);
            DeleteSpaces(varName);

            std::string str = assignation.substr(position + 1);
            memMan->Add(AssignChar(str), varName, CHAR, parentClass, structCode);

        }

        return true;

    } else if (ContainsChar(assignation, '{', position)){
        if (type == STRUCT) {
            if (parentClass != MAIN_CLASS) {
                Debug("Cascade struct declaration is not allowed."); // call debugger because of chain struct declaration
                return false;
            }
            memMan->Add((void*) new std::string("<" + StructName() + " struct type>"), StructName(), STRUCT, parentClass, structCode);
            currentClass = StructName();
        }

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

void* CodeParser::AssignNum(double num, std::string type) {
    if (type == INT) return (void*) new int ((int) num);
    else if (type == LONG) return (void*) new long ((long) num);
    else if (type == FLOAT) return (void*) new float ((float) num);
    else if (type == DOUBLE) return (void*) new double ((double) num);
    else return new void*();
}

void CodeParser::DeleteSpaces(std::string &text) {
    std::string newText = std::string();

    for (char character : text){
        if (character == ' ' or character == '\n') continue;
        newText += character;
    }
    text = newText;
}

void *CodeParser::AssignChar(std::string fragment) {

    int position = NOT_STRING_POS_OR_LENGHT;

    ContainsChar(fragment, '\'', position);
    fragment = fragment.substr(position + 1);
    ContainsChar(fragment, '\'', position);
    fragment = fragment.substr(0, position);

    if (fragment.length() != 1) Debug("Char is a character, it is not a chain of characters."); // CALLS DEBUGGER

    return (void*) new char ((char)fragment.at(0));
}

Node *CodeParser::AssignStruct(std::string fragment) {
    int position = NOT_STRING_POS_OR_LENGHT;
    int lenght = NOT_STRING_POS_OR_LENGHT;
    std::string varName;

    if (ContainsStr(fullCode, fragment, position)){

        fragment = fullCode.substr(position);
        if (ContainsChar(fragment, '}', position)){
            varName = fragment.substr(position + 1);

            if (!ContainsChar(varName, ';', position)) Debug("There is no \';\' in line no sé cual."); // call debugger cause there is no ; in this line.

            varName = varName.substr(0,position);
        } else Debug("Uknown error in line no se cual la verda");

    } else; //call debugger cause definition of struct is not concise
}

void CodeParser::SkipSpaces(std::string &text, int &position) {
    position = 0;

    for (char ch : text){

        if (ch == ' ') position++;
        else return;
    }
    position = NOT_STRING_POS_OR_LENGHT;
}

CodeParser* CodeParser::Instance() {
    if (instance == nullptr) instance = new CodeParser(MemoryManager::Instance());
    return instance;
}

std::string CodeParser::GetFullStruct(const std::string& structLine, const std::string& structName) {
    std::string fullStruct = fullCode;
    int position = NOT_STRING_POS_OR_LENGHT;
    bool searching = true;

    do {                // search for declaration of this struct
        if (ContainsChar(fullStruct, '\n', position)){
            if (ContainsStr(fullStruct, structLine)) searching = false;
        }
    } while (searching);


}

std::string CodeParser::StructName() {
    std::string tempStr = fullCode;
    int line = 0;
    int pos = NOT_STRING_POS_OR_LENGHT;
    while (line != lineNum){
        if (ContainsChar(tempStr, '\n', pos)){
            tempStr = tempStr.substr(pos);
            line++;
        } else {
            Debug("You declared a struct with no name. Struct begins at line" + std::to_string(lineNum) + ".");
            return std::string();
        }
    }
    bool exit = false;
    while (!exit){
        if (ContainsChar(tempStr, '}', pos)){
            tempStr = tempStr.substr(pos);
            if (ContainsChar(tempStr, '\n', pos)) {
                tempStr = tempStr.substr(0, pos);
                if (ContainsChar(tempStr, ';', pos)){
                    tempStr = tempStr.substr(0, pos);
                    exit = true;
                } else {
                    Debug("A line with struct name does not have ';'.");
                    exit = true;
                }
            } else if (ContainsChar(tempStr, ';', pos)) {
                tempStr = tempStr.substr(0, pos);
                exit = true;

            } else {
                Debug("A line with struct name does not have ';' or  there is an unknown problem.");
                exit = true;
            }
        }
    }

    if (pos == NOT_STRING_POS_OR_LENGHT) return std::string ();
    else return tempStr;
}

bool CodeParser::CheckSemicolon(std::string line) {
    DeleteSpaces(line);
    if (line.empty()) return true;
    else if (line.at(line.length()-1) == ';') return true;
    else if (line.at(line.length()-1) == '{') return true;
    else return false;
}

bool CodeParser::PartOfStruct(std::string& line) {
    return false;
}

void CodeParser::AddLine(const std::string& line) {
    this->fullCode += line;
}

void CodeParser::Debug(std::string msg) {

    debug += msg + "\n";

}

void CodeParser::CheckLine(std::string line, std::string parentClass) {
    lineNum++;
    if (!CheckSemicolon(line)) {
        Debug("Add a ';' to line " + std::to_string(lineNum) + ".");
        return;
    }
    else if (Declaration(line, parentClass)) return;
    else {
        Debug("Error in line " + std::to_string(lineNum) + ". If not described before, its unknown");
        return;
    }
}

void CodeParser::Parse() {
    std::string tempCode = fullCode;
    int position = NOT_STRING_POS_OR_LENGHT;
    for (int i = 0; i < lines; ++i) {
        if (ContainsChar(tempCode, '\n', position)) {
            CheckLine(tempCode.substr(0, position));
            tempCode = tempCode.substr(position);
        }
    }
}

bool CodeParser::NumType(std::string &type) {
    std::string numTypes[] = {INT, LONG, FLOAT, DOUBLE};
    for (std::string numType : numTypes) {
        if (numType == type) return true;
    }
    return false;
}

std::string CodeParser::GetDebug() {
    return debug;
}

bool CodeParser::CheckEndOfStruct(std::string& line) {
    if (ContainsChar(line, '}')) {
        currentClass = MAIN_CLASS;
    }
}

