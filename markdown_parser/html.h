#include "lexer.h"
typedef struct
{ 
    char* tag_start;
    char* tag_contents; // This gets filled later.
    char* tag_end;
} Tag;

Tag markdown_to_html(TokenType token);
