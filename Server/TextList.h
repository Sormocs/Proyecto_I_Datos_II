//
// Created by tiquillo on 22/4/21.
//

#ifndef SERVER_TEXTLIST_H
#define SERVER_TEXTLIST_H
#include "string"

#define NONE "no_class"

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
    int length;
    std::string parentClass;

public:
    TextList(std::string parentClass = NONE);
    int GetLenght() const;
    std::string GetParentClass() const;
    std::string GetDeleteFirst();
    std::string GetDeleteLast();
    void AddFront(std::string text);
    void AddLast(std::string text);

    TextList* next;
    TextList* prev;
};

class TextListList {
    TextList* first;
    TextList* last;
    int length;

public:
    int GetLenght() const;
    TextList GetDeleteFirst();
    void AddFront(TextList* list);
    void AddLast(TextList* list);
};


#endif //SERVER_TEXTLIST_H
