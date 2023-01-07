#include "copy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *copy_string(const char *begin, size_t offset)
{
    char *str = malloc(offset + 1);
    memcpy(str, begin, offset);
    str[offset + 1] = '\0';
    return str;
}