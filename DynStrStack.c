#include "DynStrStack.h"

DynStrStack *DynStrStackCreate()
{
    DynStrStack *DSStack = (DynStrStack *)malloc(sizeof(DynStrStack));
    DSStack->head = NULL;
    return DSStack;
}

DynStrStackEl *DynStrStackElCreate()
{
    DynStrStackEl *El = (DynStrStackEl *)malloc(sizeof(DynStrStackEl));
    El->DS = DynStrCreate();
    El->next = NULL;
    return El;
}

void DynStrStackPushBack(DynStrStack *DSStack, DynStr *DS)
{
    DynStrStackEl *El = DynStrStackElCreate();
    El->DS = DS;
    El->next = DSStack->head;
    DSStack->head = El;
}

DynStr *DynStrStackPop(DynStrStack *DSStack)
{
    DynStr *DS = DSStack->head->DS;
    DynStrStackEl *El = DSStack->head;
    DSStack->head = DSStack->head->next;
    free(El);
    return DS;
}
