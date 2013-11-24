#pragma once
typedef struct el CharStackEl;

struct el
{
    char c;
    CharStackEl *next;
};

typedef struct
{
    CharStackEl *head;
}CharStack;

CharStackEl *CharStackElCreate();
CharStack *CharStackCreate();
void CharStackPushBack(CharStack *CH, char c);
char CharStackPop(CharStack *CH);
void CharStackPrint(CharStackEl *CH);
