#include "function.h"
#include "string.h"

Str::Str(char* ch)
{
    if(ch[0] == '\0'){
        head = tail = NULL;
        return;
    }
    head = new Char(ch[0]);
    tail = head;
    for(int i = 1; ch[i] != '\0'; i++){
        tail->next = new Char(ch[i]);
        tail = tail->next;
    }
}

Str::Str(const Str& s)
{
    if(s.head == NULL){
        head = tail = NULL;
        return;
    }
    head = new Char(s.head->text);
    tail = head;
    Char* temp = NULL;
    for(temp = s.head->next; temp != NULL; temp = temp->next){
        tail->next = new Char(temp->text);
        tail = tail->next;
    }
}

bool Str::operator==(const Str& s) const
{
    Char* a = this->head;
    Char* b = s.head;
    if(a == NULL && b == NULL) return true;
    while(a != NULL || b != NULL){
        if(a != NULL && b == NULL) return false;
        else if(a == NULL && b != NULL) return false;
        else{
            //a != NULL && b != NULL
            if(a->text != b->text)
                return false;
            else{
                a = a->next;
                b = b->next;
            }
        }
    }
    return true;
}
