#include "DynStr.h"

DynStr* DynStrCreate()
{
    DynStr *DS = (DynStr*)malloc(sizeof(DynStr));
    if(!DS)
    {
        printf("memory allocation error in DynStrCreate\n");
        exit(1);
    }
    DS->str = (char*)calloc(1,sizeof(char));
    DS->len = 0;
    DS->reserve = 0;
    return DS;
}

DynStr* DynStrAssign(DynStr *DS, char *str)
{
    //c = strcat(c, "\0");
    if(!DS) return NULL;
    size_t len = strlen(str);
    if(!len) return DS;
    if(len+1>=DS->len)
    {
        DS = (DynStr*)realloc(DS, sizeof(DynStr)*len*3);
        if(!DS)
        {
            printf("memory allocation error in DynStrAssign\n");
            exit(1);
        }
        DS->reserve = len*3;
    }
    DS->str = strcpy(DS->str, str);
    DS->str = strcat(DS->str, "\0");
    DS->len = len;
    return DS;
}

DynStr* DynStrPushBack(DynStr *DS, char ch)
{
    if(!DS) return NULL;
    if(DS->len == DS->reserve)
    {
        DS = (DynStr*)realloc(DS, sizeof(DynStr)*(DS->len+1)*3);
        if(!DS)
        {
            printf("memory allocation error in DynStrPushBack\n");
            exit(1);
        }
        DS->reserve = (DS->len+1)*3;
    }
    /*DS->str = strcat(DS->str, str[0]);
    DS->str = strcat(DS->str, "\0");*/
    DS->str[DS->len] = ch;
    //DS->str[DS->len+1] = "\0";
    DS->str = strcat(DS->str, "\0");
    DS->len += 1;
    return DS;
}

void DynStrPrint(DynStr *DS)
{
    printf("%s\n", DS->str);
}

int DynStrFree(DynStr *DS)
{
    free(DS->str);
    free(DS);
    return 0;
}
