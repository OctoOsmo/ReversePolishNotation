#include "DynStr.h"
#pragma once

typedef struct DSEl DynStrStackEl;

struct DSEl
{
    DynStr *DS;
    DynStrStackEl *next;
};

typedef struct
{
    DynStrStackEl *head;
}DynStrStack;

DynStrStack *DynStrStackCreate();
DynStrStackEl *DynStrStackElCreate();
void DynStrStackPushBack(DynStrStack *DSStack, DynStr *DS);
DynStr *DynStrStackPop(DynStrStack *DSStack);
