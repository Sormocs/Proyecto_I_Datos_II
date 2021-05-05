/**
 * @file CodeParser.cpp
 * @author Luis Delgado
 * @brief Definicion de métodos de la clase CodeParser.
 */
#include "CodeParser.h"

#include <utility>

CodeParser* CodeParser::instance = nullptr;

/**
 * @brief Constructor del parser.
 */
CodeParser::CodeParser(MemoryManager* memoryManager) {
    this->memMan = memoryManager;
}

/**
 * @brief Detecta operaciones aritmétricas y hace las llamadas respectivas para encontrar el valor.
 * @return double
 */
double CodeParser::AritmetricDetector(std::string& codeFragment) {
    double number = 0;

    if (ContainsChar(codeFragment, '+') or ContainsChar(codeFragment, '-')){
        number = AddSubtract(codeFragment);
    } else if (ContainsChar(codeFragment, '*')) number = Multiply(codeFragment);
    else if (ContainsChar(codeFragment,'/')) number = Division(codeFragment);
    else number = ExtractNumber(codeFragment);

    return number;
}

/**
 * @brief Realiza sumas y restas anidadas, pero sin combinaciones entre otros tipos de operaciones aritmétricas.
 * @return double
 */
double CodeParser::AddSubtract(std::string codeFragment) {

    double result = 0;
    std::string numberStr;
    char sign = ' ';
    double numToOperator = 0;
    int signPos = NOT_STRING_POS_OR_LENGHT;
    int plusPos = NOT_STRING_POS_OR_LENGHT;
    int minusPos = NOT_STRING_POS_OR_LENGHT;

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

/**
 * @brief Realiza multiplicaciones entre los números ingresados.
 * @return double
 */
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

/**
 * @brief Realiza divisiones entre los números ingresados.
 * @return double
 */
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

/**
 * @brief Extrae el valor numérico de una variable o de un número escrito como string.
 * @return double
 */
double CodeParser::ExtractNumber(std::string numberStr) {

    int power = 0;                                  // power for number positions
    int dotPos;                                     // position of the dot char
    double number = 0;                               // the number converted on float type
    bool isFloat = DotPos(numberStr, dotPos);    // isFloat says if number is float or not
    std::string num;

    DeleteSpaces(numberStr);
    if (numberStr.at(numberStr.length() -1) == ';') numberStr = numberStr.substr(0, numberStr.length() -1);

    if (MemoryManager::Instance()->IsVariable(numberStr)) {
        Node* temp = MemoryManager::Instance()->GetList()->GetNodeOfRef(numberStr);
        temp->references--;
        if (temp->varType == INT) return (double) MemoryManager::Instance()->GetValOfInt(numberStr);
        else if (temp->varType == LONG) return (double) MemoryManager::Instance()->GetValOfLong(numberStr);
        else if (temp->varType == FLOAT) return (double) MemoryManager::Instance()->GetValOfFloat(numberStr);
        else if (temp->varType == DOUBLE) return MemoryManager::Instance()->GetValOfDouble(numberStr);
        else Debug("Error in line " + std::to_string(lineNum) + ". You cannot add " + temp->varType + " to a number.");

    } else {

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
    }

    return number;
}

/**
 * @brief Realiza una potencia de los números ingresados.
 * @return double
 */
double CodeParser::pow(float num, float power) {

    if (power < 0) return 1/negPow(num, power);     // calls the negative power function and gives the fraction of 1/power

    else if (power == 0) return 1;                  // power of 0 of any number is always 1

    else if (power == 1) return num;                // power of 1 of any number is always the number

    else return num * pow(num, power - 1);   // gives power by recursion
}

/**
 * @brief Realiza una potencia negativa de los números ingresados.
 * @return double
 */
double CodeParser::negPow(float num, float power) {
    if (power == -1) return num;                    // when power is -1, the negative power ended

    else return num * negPow(num, power + 1); // gives power by recursion
}

/**
 * @brief Convierte un caracter a entero.
 * @return int
 */
int CodeParser::ToInt(char character) {
    return (int) character - 48;                    // converts char to int, subtracting 48 because of ASCII conversion
}

/**
 * @brief Invierte el orden de un string.
 */
void CodeParser::ReverseStr(std::string& str) {
    int lenght = str.length();

    for (int i = 0; i < lenght / 2; i++)
        std::swap(str[i], str[lenght - i - 1]); // swaps borders towards the middle
}

/**
 * @brief Ubica la posición del punto en un string que representa un número de coma flotante. Si no hay punto, retorna false.
 * @return bool
 */
bool CodeParser::DotPos(std::string fragment, int& pos) {
    for (int i = 0; i < fragment.length(); i++) {

        if (fragment.at(i) == '.' or fragment.at(i) == ',') {                // saves dot positions and returns true
            pos = i;
            return true;
        }
    }
    return false;
}

/**
 * @brief Revisa si el texto introducido contiene el caracter especificado. Incluye la posición como referencia.
 * @return bool
 */
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

/**
 * @brief Revisa si el texto introducido contiene el caracter especificado.
 * @return bool
 */
bool CodeParser::ContainsChar(std::string& fragment, char character) {

    for (char i : fragment) if (i == character) return true;
    return false;
}

/**
 * @brief Elimina el primer signo de suma o resta que encuentre en el string.
 */
void CodeParser::DelAddSubSign(std::string& codeFragment, int& minusPos, int& plusPos, int& signPos) {
    if (GetAddSubSignPos(codeFragment, minusPos, plusPos, signPos)) codeFragment = codeFragment.substr(signPos+1);
}

/**
 * @brief Revisa si el texto introducido contiene un signo de suma o resta y guarda la posición en variables pasadas por referencia.
 * @return bool
 */
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

/**
 * @brief Revisa si el texto introducido contiene un de multiplicación y guarda la posición en uan varaible pasada por referencia.
 * @return bool
 */
bool CodeParser::GetMultSignPos(std::string& codeFragment, int &timesPos) {
    return ContainsChar(codeFragment, '*', timesPos);
}

/**
 * @brief Revisa si el texto introducido contiene un de división y guarda la posición en uan varaible pasada por referencia.
 * @return bool
 */
bool CodeParser::GetDivSignPos(std::string &codeFragment, int &divPos) {
    return ContainsChar(codeFragment, '/', divPos);
}

/**
 * @brief Revisa si el texto introducido contiene un string específico y guarda la posición del primer caracter en uan varaible pasada por referencia y el largo total del texto.
 * @return bool
 */
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


/**
* @brief Revisa si el texto introducido contiene un string específico pasado por referencia.
* @return bool
*/
bool CodeParser::ContainsStr(std::string &text, std::string fragment) {
    int lenght = NOT_STRING_POS_OR_LENGHT;
    int position = NOT_STRING_POS_OR_LENGHT;

    return ContainsStr(text, std::move(fragment), position, lenght);
}

/**
 * @brief Revisa si el texto introducido contiene un string específico y guarda la posición del primer caracter en uan varaible pasada por referencia.
 * @return bool
 */
bool CodeParser::ContainsStr(std::string &text, std::string fragment, int &position) {
    int lenght = NOT_STRING_POS_OR_LENGHT;
    return ContainsStr(text, std::move(fragment), position, lenght);
}

/**
 * @brief Revisa si el texto introducido contiene una declaración de una variable o clase. En caso de haberla, hace las llamadas necesarias para guardar la variable en memoria.
 * @return bool
 */
bool CodeParser::Declaration(std::string& line, std::string& parentClass) {
//    std::string types[] = {INT, LONG, FLOAT, DOUBLE, CHAR, STRUCT};
    std::string asignation;
    int position = 0;
    int lenght = 0;

    for (std::string type : VAR_TYPES) {                    // esto no incluye reference

        if (ContainsStr(line, type, position, lenght)) {

            if (Assignation(line.substr(position + lenght), type, parentClass)) return true;
        }
    }
    if (position == NOT_STRING_POS_OR_LENGHT) {
        Debug("Introduced type in line " + std::to_string(lineNum) + " does not match any");
        return false;
    }

    CheckEndOfStruct(line);

    return false;
}

/**
 * @brief Revisa qué tipo de declaración está especificada en la línea en cuestión. Hace las llamadas necesarias para almacenar la variable en memoria.
 * @return bool
 */
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

/**
 * @brief Consigue la posición del primer número en un string.
 */
void CodeParser::GetFirstNumPos(std::string &codeBlock, int &position) {

    for (int i = 0; i < codeBlock.length(); ++i) {

        if (isdigit(codeBlock.at(i))) {

            position = i;
            return;
        }
    }
}

/**
 * @brief Crea un puntero de tipo void con el valor de un número con el fin de almacenarlo en memoria.
 * @return void*
 */
void* CodeParser::AssignNum(double num, std::string type) {
    if (type == INT) return (void*) new int ((int) num);
    else if (type == LONG) return (void*) new long ((long) num);
    else if (type == FLOAT) return (void*) new float ((float) num);
    else if (type == DOUBLE) return (void*) new double ((double) num);
    else return new void*();
}

/**
 * @brief Elimina todos los espacios que contiene un string pasado por referencia.
 */
void CodeParser::DeleteSpaces(std::string &text) {
    std::string newText = std::string();

    for (char character : text){
        if (character == ' ' or character == '\n') continue;
        newText += character;
    }
    text = newText;
}

/**
 * @brief Crea un puntero de tipo void con el valor de un caracter con el fin de almacenarlo en memoria.
 * @return void*
 */
void *CodeParser::AssignChar(std::string fragment) {

    int position = NOT_STRING_POS_OR_LENGHT;

    ContainsChar(fragment, '\'', position);
    fragment = fragment.substr(position + 1);
    ContainsChar(fragment, '\'', position);
    fragment = fragment.substr(0, position);

    if (fragment.length() != 1) Debug("Char is a character, it is not a chain of characters."); // CALLS DEBUGGER

    return (void*) new char ((char)fragment.at(0));
}

/**
 * @brief Crea un puntero de tipo Node con el valor de un struct con el fin de almacenarlo en memoria.
 * @return Node*
 */
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

/**
 * @brief Crea una instancia si no existe una y si existe una, la retorna. Esta es la función del Singleton.
 * @return CodeParser*
 */
CodeParser* CodeParser::Instance() {
    if (instance == nullptr) instance = new CodeParser(MemoryManager::Instance());
    return instance;
}

/**
 * @brief Solicita el nombre del struct en el que se está trabajando actualmente.
 * @return string
 */
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

/**
 * @brief Revisa el ';' en cada línea de código.
 * @return bool
 */
bool CodeParser::CheckSemicolon(std::string line) {
    DeleteSpaces(line);
    if (line.empty()) return true;
    else if (line.at(line.length()-1) == ';') return true;
    else if (line.at(line.length()-1) == '{') return true;
    else return false;
}

/**
 * @brief Añade una línea al atributo código, con el fin de parsear el código.
 */
void CodeParser::AddLine(const std::string& line) {
    this->fullCode += line;
    lines++;
}

void CodeParser::Debug(std::string msg) {

    debug += msg + "\n";

}

/**
 * @brief Revisa independientemente cada línea de código.
 */
bool CodeParser::CheckLine(std::string line, std::string parentClass) {
    lineNum++;
    if (!CheckSemicolon(line)) {
        Debug("Add a ';' to line " + std::to_string(lineNum) + ".");
        return false;
    }
    else if (Cout(line)) return true;

    else if (Declaration(line, parentClass)) return true;

    else {
        Debug("Error in line " + std::to_string(lineNum) + ". If not described before, its unknown");
        return false;
    }
}

/**
 * @brief Revisa el código completo para leer todas las instrucciones.
 */
void CodeParser::Parse() {
    std::string tempCode = fullCode;
    int position = NOT_STRING_POS_OR_LENGHT;
    for (int i = 0; i < lines; ++i) {
        if (ContainsChar(tempCode, '\n', position)) {
            if(!CheckLine(tempCode.substr(0, position))) return;
            tempCode = tempCode.substr(position + 1);
        }
    }
}

/**
 * @brief Averigua si el tipo enviado por referencia, corresponde a un tipo numérico.
 */
bool CodeParser::NumType(std::string &type) {
    std::string numTypes[] = {INT, LONG, FLOAT, DOUBLE};
    for (const std::string& numType : numTypes) {
        if (numType == type) return true;
    }
    return false;
}

/**
 * @brief Obtiene el texto guardado en el debug con los errores encontrados.
 * @return string
 */
std::string CodeParser::GetDebug() {
    return debug;
}

/**
 * @brief Revisa que se encuentre ante la salida de un struct. Si es así, cambia la clase de trabajo actal a Main, que corresponde a la clase principal.
 * @return bool
 */
bool CodeParser::CheckEndOfStruct(std::string& line) {
    if (ContainsChar(line, '}')) {
        currentClass = MAIN_CLASS;
        return true;
    }
    return false;
}

bool CodeParser::Cout(std::string line) {
    DeleteSpaces(line);
    int position = NOT_STRING_POS_OR_LENGHT;
    if (ContainsStr(line, "print(", position)){
        line = line.substr(6);
        if (ContainsChar(line, ')', position)) {
            line = line.substr(0, position);
            line = ValToStr(line);
            console += line + "\n";
            std::cout << line << std::endl;
            return true;
        }
        Debug("The parenthesis is left in line " + std::to_string(lineNum) + ".");
    }
    return false;
}

void CodeParser::Restart() {
    fullCode = std::string();
    console = std::string();
    debug = std::string();
    lineNum = 0;
    lines = 0;

    memMan->Restart();
}

std::string CodeParser::ValToStr(std::string &varName) {

    if (memMan->IsVariable(varName)) {
        Node *temp = MemoryManager::Instance()->GetList()->GetNodeOfRef(varName);
        std::string type = temp->varType;
        if (type == INT) return std::to_string(*(int *) temp->value);
        else if (type == LONG) return std::to_string(*(long *) temp->value);
        else if (type == FLOAT) return std::to_string(*(float *) temp->value);
        else if (type == DOUBLE) return std::to_string(*(double *) temp->value);
        else if (type == CHAR) return std::to_string(*(char *) temp->value);
        else if (type == STRUCT) return *(std::string *) temp->value;
        else {
            Debug("Unknown number when asking to print " + varName + ".");
            return std::string();
        }
    } else {
        return varName;
    }
}
