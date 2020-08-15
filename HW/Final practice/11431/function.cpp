#include "function.h"

Str::Str(char* c)
{
    head = new Char(c[0]);
    Char* current = head;

    for(int i = 1; c[i] != '\0'; i++){
        current->next = new Char(c[i]);
        current = current->next;
    }
    tail = current;
}

Str::Str(const Str &s)
{
    head = new Char(s.head->text);
    Char* current = s.head->next;
    Char* temp = head;
    temp->next = nullptr;
    while(current){
        temp->next = new Char(current->text);
        current = current->next;
        temp = temp->next;
    }
    tail = temp;
}

bool Str::operator==( const Str &s) const
{
    Char* temp = head;
    Char* current = s.head;
    while(temp && current){
        if(temp->text != current->text)
            return false;
        temp = temp->next;
        current = current->next;
    }
    if(temp == nullptr && current == nullptr)
        return true;
    else
        return false;
}
