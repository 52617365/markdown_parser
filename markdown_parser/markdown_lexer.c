#include <stdbool.h>  
// const char* example_markdown= "\n# h1_title\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold** *";
const char* example_markdown = "\n# hello";

const char* token;
int line;

typedef enum TokenType{
    Text,
    Comment,
    Blockquote,
    Title,
    Undefined,
    End,
}TokenType;

typedef struct Token {
    char* Lexeme;
    TokenType type;
    int line;
}Token;

struct Token next() {
    while(token = example_markdown) {
        *example_markdown++;
        switch(*token) {
            case '\n':
                ++line;
                return (Token){"", Text, line};
            case '#':
                if(*token-- == '\n') {
                    *token++;
                    if (*token++ == ' ') {
                        const char* start = token;
                        
                        while(*token != '\0' || *token != '\n'){
                            *token++;
                        }

                        char* copied_string = (char*)malloc(*token - *start + 1);
                        memcpy(copied_string, *start, *token - *start);
                        
                        return (Token) {
                            copied_string,
                            Title,
                            line,
                        };
                    }
                }
            default: return (Token){"", Undefined, line};
        }
    }
    return (Token){"", End, line};
}
//             case '#':
//             case '-':
//             case '>':
//             case ' ':
//             case 'a':
//             case 'b':
//             case 'c':
//             case 'd':
//             case 'e':
//             case 'f':
//             case 'g':
//             case 'h':
//             case 'i':
//             case 'j':
//             case 'k':
//             case 'l':
//             case 'm':
//             case 'n':
//             case 'o':
//             case 'p':
//             case 'q':
//             case 'r':
//             case 's':
//             case 't':
//             case 'u':
//             case 'v':
//             case 'w':
//             case 'x':
//             case 'y':
//             case 'z':
//             case 'A':
//             case 'B':
//             case 'C':
//             case 'D':
//             case 'E':
//             case 'F':
//             case 'G':
//             case 'H':
//             case 'I':
//             case 'J':
//             case 'K':
//             case 'L':
//             case 'M':
//             case 'N':
//             case 'O':
//             case 'P':
//             case 'Q':
//             case 'R':
//             case 'S':
//             case 'T':
//             case 'U':
//             case 'V':
//             case 'W':
//             case 'X':
//             case 'Y':
//             case 'Z':
//                 return "identifier";
//             case '0':
//             case '1':
//             case '2':
//             case '3':
//             case '4':
//             case '5':
//             case '6':
//             case '7':
//             case '8':
//             case '9':
//                 return "number";
//         }

//     }

//     switch(example_markdown++) {
//         case '\n':
//             char succ_token = get();
//             char succ_succ_token = get();
//             if(succ_token == '#' && is_space(succ_succ_token)) {
//                 while(get() != '\n')
//                 return (Token){Lexemem: }
                
//                 // it's title.
//             }
//             if(succ_token == '>' && is_space(succ_succ_token)) {
//                 while(get() != '\n')
//                 // it's a blockquote.
//             }

//         case '#':
//         case '-':
//         case '>':
//         case ' ':
//         case 'a':
//         case 'b':
//         case 'c':
//         case 'd':
//         case 'e':
//         case 'f':
//         case 'g':
//         case 'h':
//         case 'i':
//         case 'j':
//         case 'k':
//         case 'l':
//         case 'm':
//         case 'n':
//         case 'o':
//         case 'p':
//         case 'q':
//         case 'r':
//         case 's':
//         case 't':
//         case 'u':
//         case 'v':
//         case 'w':
//         case 'x':
//         case 'y':
//         case 'z':
//         case 'A':
//         case 'B':
//         case 'C':
//         case 'D':
//         case 'E':
//         case 'F':
//         case 'G':
//         case 'H':
//         case 'I':
//         case 'J':
//         case 'K':
//         case 'L':
//         case 'M':
//         case 'N':
//         case 'O':
//         case 'P':
//         case 'Q':
//         case 'R':
//         case 'S':
//         case 'T':
//         case 'U':
//         case 'V':
//         case 'W':
//         case 'X':
//         case 'Y':
//         case 'Z':
//             return "identifier";
//         case '0':
//         case '1':
//         case '2':
//         case '3':
//         case '4':
//         case '5':
//         case '6':
//         case '7':
//         case '8':
//         case '9':
//             return "number";
//         default:
//             return "unexpected";
//     }
// }

// bool token_is_bad(const char* token) {
//     return token == "end" || token == "unexpected";
// }

// // prev has to be nullbyte or newline for the blockquote or anything else to work.

// bool is_identifier(char c) {
//     switch(c){
//         case ' ':
//         case '\n':
//         case 'a':
//         case 'b':
//         case 'c':
//         case 'd':
//         case 'e':
//         case 'f':
//         case 'g':
//         case 'h':
//         case 'i':
//         case 'j':
//         case 'k':
//         case 'l':
//         case 'm':
//         case 'n':
//         case 'o':
//         case 'p':
//         case 'q':
//         case 'r':
//         case 's':
//         case 't':
//         case 'u':
//         case 'v':
//         case 'w':
//         case 'x':
//         case 'y':
//         case 'z':
//         case 'A':
//         case 'B':
//         case 'C':
//         case 'D':
//         case 'E':
//         case 'F':
//         case 'G':
//         case 'H':
//         case 'I':
//         case 'J':
//         case 'K':
//         case 'L':
//         case 'M':
//         case 'N':
//         case 'O':
//         case 'P':
//         case 'Q':
//         case 'R':
//         case 'S':
//         case 'T':
//         case 'U':
//         case 'V':
//         case 'W':
//         case 'X':
//         case 'Y':
//         case 'Z':
//         case '0':
//         case '1':
//         case '2':
//         case '3':
//         case '4':
//         case '5':
//         case '6':
//         case '7':
//         case '8':
//         case '9':
bool is_space(char c) {
    return c == ' ';
}
int main() {
    struct Token token = next();
    printf("string: %s - type: %s", token.Lexeme, token.type);
    // printf("\ttype: %s", token.type);
    return 0;
}