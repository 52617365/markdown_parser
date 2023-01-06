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

struct Token
{
    char* lexeme;
    size_t type;
    size_t line;
    size_t start;
};

void consume(const char* sequence);
char peek(const char* sequence);
char look_ahead(const char* sequence, size_t n);
void consume_until_linebreak_or_null(const char* sequence);
bool is_space(char c);
char get(const char* sequence);
const char* get_token_type_string(size_t token);