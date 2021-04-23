//
// Created by tiquillo on 22/4/21.
//

#include "TextList.h"

Text::Text() {
    text = "";
    next = nullptr;
    prev = nullptr;
}

std::string TextList::GetDeleteFirst() {
    if (first == nullptr) return "";
    else {
        std::string text = first->text;
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        length--;
        return text;
    }
}

std::string TextList::GetDeleteLast() {
    if (last == nullptr) return "";
    else {
        std::string text = last->text;
        last = last->prev;
        delete last->next;
        last->next = nullptr;
        length--;
        return text;
    }
}

void TextList::AddFront(std::string text) {
    if (first == nullptr) {
        first = new Text();
        last = first;
    }
    else {
        Text* temp = new Text();
        temp->text = text;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    length++;
}

void TextList::AddLast(std::string text) {
    if (first == nullptr) {
        first = new Text();
        last = first;
    } else {
        Text* temp = new Text();
        temp->text = text;
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
    length++;
}

TextList::TextList(std::string parentClass) {
    length = 0;
    this->parentClass = parentClass;
}

int TextList::GetLenght() const {
    return length;
}

std::string TextList::GetParentClass() const {
    return parentClass;
}


int TextListList::GetLenght() const {
    return length;
}

TextList TextListList::GetDeleteFirst() {
    if (first == nullptr) throw ("No elements in TextListList");
    else {
        TextList temp = *first;
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
        length--;
        return temp;
    }
}

void TextListList::AddFront(TextList* list) {
    if (first == nullptr) {
        first = list;
        last = first;
    }
    else {
        list->next = first;
        first->prev = list;
        first = list;
    }
    length++;
}

void TextListList::AddLast(TextList *list) {
    if (first == nullptr) {
        first = list;
        last = first;
    } else {
        last->next = list;
        list->prev = last;
        last = list;
    }
    length++;
}
