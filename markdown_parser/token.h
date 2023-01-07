typedef enum
{
    Text,
    BoldText,
    ItalicText,
    Blockquote,
    Heading1,
    Heading2,
    Heading3,
    Heading4,
    Heading5,
    Heading6,
    List,
    Unknown,
}TokenType;

typedef struct
{
    char* lexeme;
    size_t type;
    size_t line;
} Token;

const char* get_token_type_string(size_t token);
void eat(size_t n, char** sequence);
char peek(char* sequence);
char look_ahead(size_t n, char* sequence);
void eat_until_linebreak_or_null(char** sequence);