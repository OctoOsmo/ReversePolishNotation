#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
//    printf("Hello world!\n");
//    DynStr *DS = DynStrCreate();
//    DS = DynStrPushBack(DS, '!');
//    DynStrPrint(DS);
    CharStack *CH = CharStackCreate();
//    CharStackPushBack(CH, '1');
//    CharStackPushBack(CH, '2');
//    CharStackPushBack(CH, '3');
//    CharStackPushBack(CH, '4');
//    CharStackPrint(CH->head);
//    while(CH->head)
//    {
//        printf("%c ", CharStackPop(CH));
//    }
//    printf("\n");
//    CharStackPrint(CH->head);
//    DynStr *DS1 = DynStrCreate();
//    DS1 = DynStrAssign(DS1, "DynStr1");
//    DynStr *DS2 = DynStrCreate();
//    DS2 = DynStrAssign(DS2, "DynStr2");
    DynStrStack *DSStack = DynStrStackCreate();
//    DynStrStackPushBack(DSStack, DS1);
//    DynStrStackPushBack(DSStack, DS2);
//    while(DSStack->head)
//    {
//        DynStrPrint(DynStrStackPop(DSStack));
//    }
//    printf("\n");
    char *str = "23+32";
    size_t  i;
    DynStr *DS = DynStrCreate();
    for(i=0; i<strlen(str); ++i)
    {
        switch(str[i])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            if(!DS)
                DS = DynStrCreate();
            DS = DynStrPushBack(DS, str[i]);
            break;
        case '+':
            CharStackPushBack(CH, str[i]);
            if(DS&&DS->len > 0)
            {
                DS = DynStrPushBack(DS, '\n');
                DynStrStackPushBack(DSStack, DS);
                DynStrPrint(DS);
                DS = NULL;
            }
            break;
        }
    }
    while(CH->head)
    {
        printf("%c ", CharStackPop(CH));
    }
    printf("\n");
    return 0;
}
