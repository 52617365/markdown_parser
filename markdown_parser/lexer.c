#include <stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"
#include "lexer.h"
// const char* example_markdown= "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";

const char* sequence= "\n##### h2_text\n";

size_t line;
const char* start_of_lexeme;
const char* end_of_lexeme;


Token next(void) {
    const char* start_addy = sequence;
    switch(peek(sequence)) {
        case '\n':
        case '\r':
        ++line;
            if(look_ahead(sequence, 1) == '#') {
                eat(sequence); // TODO: why does this not get assigned??

                if(look_ahead(sequence, 1) == ' ') {
                    // h1 heading
                    eat_many(sequence, 2);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading1, line, start_of_lexeme, end_of_lexeme};
                    // TODO: return.
                } else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == ' ') {
                    // h2
                    eat_many(sequence, 3);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading2, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == ' ') {
                    // h3
                    eat_many(sequence, 4);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading3, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == ' ') {
                    // h4
                    eat_many(sequence, 5);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading4, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == '#' && look_ahead(sequence, 5) == ' ') {
                    // h5
                    eat_many(sequence, 6);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading5, line, start_of_lexeme, end_of_lexeme};
                } else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == '#' && look_ahead(sequence, 5) == ' ') {
                    // h6
                    eat_many(sequence, 7);
                    start_of_lexeme = sequence;
                    eat_until_linebreak_or_null(sequence);
                    end_of_lexeme = sequence;

                    char* lexeme = copy_string(start_of_lexeme, end_of_lexeme-start_of_lexeme);
                    return (Token){lexeme, Heading6, line, start_of_lexeme, end_of_lexeme};
                }
            } else { 
                start_of_lexeme = sequence;
                eat_until_linebreak_or_null(sequence);
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
            eat_until_linebreak_or_null(sequence);
            char* str = copy_string(start_addy, sequence-start_addy);
            return (Token){str, Text};
        default:
            return (Token){"", Unknown};
    }
}

int main(void) {
    Token token = next();
    printf("lexeme: %s | type: %s", token.lexeme, get_token_type_string(token.type));
    free(token.lexeme);
    return 0;
}