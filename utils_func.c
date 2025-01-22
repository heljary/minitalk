#include "minitalk.h"
#include <stdio.h>

void convertcharbin(char *str)
{
    int i = 0;
    int j;
    unsigned int bit = 0;
    while(str[i])
    {
        j = 8;
        while(j--)
        {
            bit = (str[i] >> j & 1) + 48;
            write(1, &bit, 1);
        }
        write(1, "\n",1);
        i++;
    }
}
