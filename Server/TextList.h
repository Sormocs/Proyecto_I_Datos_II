//
// Created by tiquillo on 22/4/21.
//

#ifndef SERVER_TEXTLIST_H
#define SERVER_TEXTLIST_H
#include "string"

class Text{
public:
    std::string text;
    Text* next;
    Text* prev;

    Text();
};

class TextList {
    Text* first;
    Text* last;

public:
    std::string GetDeleteFirst();
    std::string GetDeleteLast();
    void AddFront(std::string text);
    void AddLast(std::string text);
};


#endif //SERVER_TEXTLIST_H
