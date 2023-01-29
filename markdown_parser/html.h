#include "lexer.h"
#include <stddef.h>
typedef struct
{ 
    const char* tag_start;
    const char* tag_end;
} Tag;

Tag markdown_to_html(size_t token);
