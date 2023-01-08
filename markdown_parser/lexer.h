#ifndef FILE_H
#define FILE_H
#include <stdbool.h>

typedef enum
{
    Number,          // 0-9
    Letters,         // [a-z]
    GreaterThan,     // >
    HashTag,         // #
    Dash,            // -
    ExclamationMark, // !
    Asterisk,        // *
    Underscore,      // _
    Backtick,        // ` 
    Linebreak,       // \n
    Unknown,         // 
    End,             // '\0'
    Heading,         // '#' 1-6 times.
}TokenType;

typedef struct
{
    size_t type;
    const char* start;
    const char* end;
} Token;

char peek(const char* sequence);
char peek_prev(const char* sequence); 
char* get_token_type_string(size_t token);
bool is_identifier_char(char c);
bool is_digit(char c);
Token next(const char** sequence);

#endif