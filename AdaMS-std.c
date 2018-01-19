#include "AdaMS-std.h"


bool is_num(char* arg)
{
    while(*arg)
    {
        if(isdigit(*arg++)==0) return false;
    } 

    return true;
}


bool is_jmp(char* arg)
{
    if(arg[0]==':')
        return true;
    else
        return false;
}
