#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

typedef enum
{
    Text,             // 0-9 or a-z + nordic.
    Blockquote,       // >
    Dash,             // -
    ExclamationMark,  // !
    Asterisk,         // *
    Underscore,       // _
    Backtick,         // ` 
    Linebreak,        // \n
    Unknown,          //
    End,              // '\0'
    Heading,          // '#' 1-6 times.
    ListItem,         // '-' or '*' at the start of the line followed by space.
    NumberedListItem, // Digit followed by .
    Italic,           // \n*{text}, \n_{text}, _{text}_ or *{text}*
    Bold,             // \n**{text}, \n__{text}, __{text}__ or **{text}**
}TokenType;

typedef struct
{
    size_t type;
    const char* start;
    const char* end;
} Token;

char peek(const char* sequence);
char peek_prev(const char* sequence); 
char peek_next(const char* sequence); 
char* get_token_type_string(size_t token);
bool is_identifier_char(char c);
bool is_digit(char c);
void consume(const char** sequence);
Token next(const char** sequence);

#endif