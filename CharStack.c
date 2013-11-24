#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CharStack.h"

CharStackEl *CharStackElCreate()
{
    CharStackEl *El =(CharStackEl *)malloc(sizeof(CharStackEl));
    return El;
}

CharStack *CharStackCreate()
{
    CharStack *CH = (CharStack *)malloc(sizeof(CharStack));
    CH->head = NULL;
    return CH;
}

void CharStackPushBack(CharStack *CH, char c)
{
    CharStackEl *El = CharStackElCreate();
    El->c = c;
    El->next = CH->head;
    CH->head = El;
}
char CharStackPop(CharStack *CH)
{
    char c = CH->head->c;
    CharStackEl *El; //= CharStackElCreate();
    El = CH->head;
    CH->head = CH->head->next;
    free(El);
    return c;
}
void CharStackPrint(CharStackEl *El)
{
    if(El)
    {
        printf("%c ", El->c);
        CharStackPrint(El->next);
    }else
        printf("\n");
}


