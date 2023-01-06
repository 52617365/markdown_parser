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
} TypeOfToken;

typedef struct
{
    char* lexeme;
    size_t type;
    size_t line;
    const char* start;
    const char* end;
} Token;

void eat(const char* sequence);
void eat_many(const char* sequence, size_t n);
char peek(const char* sequence);
char look_ahead(const char* sequence, size_t n);
void eat_until_linebreak_or_null(const char* sequence);
char get_next(const char* sequence);
const char* get_token_type_string(size_t token);
char next_in(const char* sequence);