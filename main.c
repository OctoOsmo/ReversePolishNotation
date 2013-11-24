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
    return 0;
}
