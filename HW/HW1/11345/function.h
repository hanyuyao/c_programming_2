#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

man* head;
man* createList(int n);
int solveJosephus(int step);

#endif
