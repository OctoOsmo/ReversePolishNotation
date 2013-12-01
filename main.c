#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int GetOperPrior(char c)//get operation priority
{
    int ret;
    switch(c)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '(':
        return 0;
    default:
        printf("calculating priority error");
        return NULL;//error
        break;
    }
}

int ComparePrior(char a, char b)//compare operations prioritys
{
    if(GetOperPrior(a) > GetOperPrior(b)) return 1;
    if(GetOperPrior(a) == GetOperPrior(b)) return 0;
    if(GetOperPrior(a) < GetOperPrior(b)) return -1;
    return NULL;
}

DynStrStack *ToPolish(char *str)
{
    CharStack *CH = CharStackCreate();
    DynStrStack *DSStack = DynStrStackCreate();
    size_t  i;
    DynStr *DS = DynStrCreate();
    for(i=0; i<strlen(str); ++i)
    {
        switch(str[i])
        {
        case ' ':
            i++;
            break;
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
        case '.':
            if(!DS)
                DS = DynStrCreate();
            DS = DynStrPushBack(DS, str[i]);
            break;
        default:
            if(DS&&DS->len > 0)
            {
                DS = DynStrPushBack(DS, '\0');
                DynStrStackPushBack(DSStack, DS);
                DS = NULL;
            }
        }
        switch(str[i])
        {
        case '(':
            CharStackPushBack(CH, str[i]);
            break;
        case ')':
            while(CH->head->c != '(')
            {
                if(!CH)
                {
                    printf("mistake in expression\n");
                    exit(1);
                }
                DS = DynStrCreate();
                DS = DynStrPushBack(DS, CharStackPop(CH));
                DS = DynStrPushBack(DS, '\0');
                DynStrStackPushBack(DSStack, DS);
                DS = NULL;
            }
            CharStackPop(CH);//pop (
            if(CH->head&&(GetOperPrior(CH->head->c) > 0))
            {
                DS = DynStrCreate();
                DS = DynStrPushBack(DS, CharStackPop(CH));
                DS = DynStrPushBack(DS, '\0');
                DynStrStackPushBack(DSStack, DS);
                DS = NULL;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while(CH->head&&(GetOperPrior(str[i]) <= GetOperPrior(CH->head->c)))
            {
                if(!DS)
                    DS = DynStrCreate();
                DS = DynStrPushBack(DS, CharStackPop(CH));
                DS = DynStrPushBack(DS, '\0');
                DynStrStackPushBack(DSStack, DS);
                DS = NULL;
            }
            CharStackPushBack(CH, str[i]);
//            CharStackPrint(CH->head);
            break;
//        default:
//            printf("something goes whrong\n");
//            break;
        }
    }
    while(CH->head)
    {
        DS = DynStrCreate();
        DS = DynStrPushBack(DS, CharStackPop(CH));
        DS = DynStrPushBack(DS, '\0');
        DynStrStackPushBack(DSStack, DS);
        DS = NULL;
    }
    return DSStack;
}

int main()
{
    char *str = "(3/15.5+(4)*2/(1-5)/21.4235)";
    DynStrStack *DSStack;
    DSStack = ToPolish(str);
    DynStr *p;
    while(DSStack->head)
    {
        p = DynStrStackPop(DSStack);
        DynStrPrint(p);
    }
    printf("\n");
    return 0;
}
