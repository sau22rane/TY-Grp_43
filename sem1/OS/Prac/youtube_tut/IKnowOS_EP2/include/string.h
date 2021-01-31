#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlen(string ch)
{
        uint16 i = 1;
        while(ch[i++]);  
        return --i;
}


#endif
