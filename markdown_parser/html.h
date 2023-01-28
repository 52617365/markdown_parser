#include "lexer.h"
typedef struct
{ 
    const char* tag_start;
    const char* tag_contents; // This gets filled later.
    const char* tag_end;
} Tag;

Tag markdown_to_html(size_t token);
