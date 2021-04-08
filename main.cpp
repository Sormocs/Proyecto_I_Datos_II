#include <iostream>
#include <SFML/Graphics.hpp>

#include "CodeParser.h"
#include "MemList.h"
#include "MemoryManager.h"

void ParserTest();
void Screen();
void MemoryTests();

int main()
{

    //Screen();
    //ParserTest();
    MemoryTests();

    return 0;
}

void ParserTest() {
    CodeParser* codeParser = new CodeParser();
    int signPos = NOT_IN_STRING;
    int plusPos = NOT_IN_STRING;
    int minusPos = NOT_IN_STRING;
    std::string ajua = "15 - 12;";

    //codeParser->DelAddSubSign(ajua, minusPos, plusPos, signPos);

    //std::cout << "Minus: " << minusPos << " Plus: " << plusPos << " Sign: " << signPos << " string " << ajua << std::endl;
    //std::cout << ajua.substr(3,-1) << std::endl;
    //std::cout << codeParser->ExtractNumber(" 12 ") << std::endl;
    //std::cout << codeParser->AddSubtract(" 2 + 2") << std::endl;
    //std::cout << codeParser->Multiply("3.2 * 5.1 * 4.34534;") << std::endl;
    //std::cout << codeParser->Division("3.34 / 2 / 400;") << std::endl;

}

void Screen(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Algo :v",sf::Style::Close);
    sf::RectangleShape shape(sf::Vector2f(120.f,50.f));
    shape.setPosition(300,100);
    shape.setFillColor(sf::Color::Red);
    float mouse[2] = {};

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;

            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

void MemoryTests(){
    //void array[100];
    void* p = malloc(1000);
    int* pInt = (int*)p;
    std::string* pString = (std::string*)p+8;

    *pInt = 25;
    *pString = "buenas";

    std::cout << "p size->" << sizeof(p) << " and value is void" << " cell at " << p << std::endl;
    std::cout << "pInt size->" << sizeof(pInt) << " and value is " << *pInt << " cell at " << pInt << std::endl;
    std::cout << "pString size->" << sizeof(pString) << " and value is " << *pString << " cell at " << pString << std::endl;

    //MemoryList* memList = new MemoryList();
    auto* memoryManager = new MemoryManager();
    Node* nodo = memoryManager->GetMemory();
    nodo->referenceValue = malloc(sizeof(Node));
    *(((Node*)(nodo->referenceValue))->charValue) = 'a';
    std::cout << ((Node*)(nodo->referenceValue))->charValue;
}