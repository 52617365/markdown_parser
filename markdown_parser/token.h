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
    const char* start;
    const char* end;
} Token;

const char* get_token_type_string(size_t token);