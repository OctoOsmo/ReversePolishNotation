#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
//    printf("Hello world!\n");
    DynStr *DS = DynStrCreate();
    DS = DynStrPushBack(DS, '!');
    DynStrPrint(DS);
    CharStack *CH = CharStackCreate();
    CharStackPushBack(CH, '1');
    CharStackPushBack(CH, '2');
    CharStackPushBack(CH, '3');
    CharStackPushBack(CH, '4');
    CharStackPrint(CH->head);
    while(CH->head)
    {
        printf("%c ", CharStackPop(CH));
    }
    printf("\n");
    CharStackPrint(CH->head);
    DynStr *DS1 = DynStrCreate();
    DS1 = DynStrAssign(DS1, "DynStr1");
    DynStr *DS2 = DynStrCreate();
    DS2 = DynStrAssign(DS2, "DynStr2");
    DynStrStack *DSStack = DynStrStackCreate();
    DynStrStackPushBack(DSStack, DS1);
    DynStrStackPushBack(DSStack, DS2);
    while(DSStack->head)
    {
        DynStrPrint(DynStrStackPop(DSStack));
    }
    printf("\n");
    return 0;
}
