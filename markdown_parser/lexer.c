#include <stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"
#include "lexer.h"
// const char* example_markdown= "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";


size_t line;
const char* start_of_lexeme;
const char* end_of_lexeme;


void eat(size_t n, char** sequence) {
    while (n > 0) {
        n--;
        (*sequence)++;
    }
}

char peek(char* sequence) {
    return *sequence;
}

char look_ahead(size_t n, char* sequence) {
    size_t i = n;

    for(; i > 0; i--) {
        sequence++;
    }
    char peeked_char = *sequence;

    for(; i < n; i++) {
        sequence--;
    }

    return peeked_char;
}

void eat_until_linebreak_or_null(char** sequence) {
        while(*(*sequence) != '\n' && *(*sequence) != '\r' && *(*sequence) != '\0') {
            eat(1, sequence);
        }
}

Token next(char* sequence) {
    const char* start_addy = sequence;
    switch(peek(sequence)) {
        case '\n':
        case '\r':
        ++line;
            if(look_ahead(1, sequence) == '#') {
                eat(1, &sequence); // TODO: why does this not get assigned??

                if(look_ahead(1, sequence) == ' ') {
                    // h1 heading
                    eat(2, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading1, line, start_of_lexeme, end_of_lexeme};
                    // TODO: return.
                } else if(look_ahead(1, sequence) == '#' && look_ahead(2, sequence) == ' ') {
                    // h2
                    eat(3, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading2, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(1, sequence) == '#' && look_ahead(2, sequence) == '#' && look_ahead(3, sequence) == ' ') {
                    // h3
                    eat(4, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading3, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(1, sequence) == '#' && look_ahead(2, sequence) == '#' && look_ahead(3, sequence) == '#' && look_ahead(4, sequence) == ' ') {
                    // h4
                    eat(5, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading4, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(1, sequence) == '#' && look_ahead(2, sequence) == '#' && look_ahead(3, sequence) == '#' && look_ahead(4, sequence) == '#' && look_ahead(5, sequence) == ' ') {
                    // h5
                    eat(6, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading5, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(1, sequence) == '#' && look_ahead(2, sequence) == '#' && look_ahead(3, sequence) == '#' && look_ahead(4, sequence) == '#' && look_ahead(5, sequence) == '#' && look_ahead(6, sequence) == ' ') {
                    // h6
                    eat(7, &sequence);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(&sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading6, line, start_of_lexeme, end_of_lexeme};
                }
            } else { 
                start_of_lexeme = sequence;
                eat_until_linebreak_or_null(&sequence);
                end_of_lexeme = sequence;

                char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                return (Token){lexeme, Text, line, start_of_lexeme, end_of_lexeme};
                // it's text.
            }

                // char* str = copy_string(start_addy, sequence-start_addy);
        case '#':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case '_':
            eat_until_linebreak_or_null(&sequence);
            char* str = copy_string(start_addy, sequence-start_addy);
            return (Token){str, Text};
        default:
            return (Token){"", Unknown};
    }
}

int main(void) {
    char* sequence= "\n####### text\n";
    Token token = next(sequence);
    printf("lexeme: %s | type: %s", token.lexeme, get_token_type_string(token.type));
    free(token.lexeme);
    return 0;
}