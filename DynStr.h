#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* str;
    size_t len;
    size_t reserve;
} DynStr;

DynStr* DynStrCreate();
DynStr* DynStrAssign(DynStr *DS, char *str);
DynStr* DynStrPushBack(DynStr *DS, char ch);
void DynStrPrint(DynStr *DS);
int DynStrFree(DynStr *DS);
