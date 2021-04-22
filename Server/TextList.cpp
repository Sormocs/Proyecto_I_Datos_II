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
}


