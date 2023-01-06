#include <stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"
#include "token.h"
// const char* example_markdown= "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";

const char* sequence= "\n##### h2_text\n";
int line;
char* old_src;


struct Token next(void) {
    while(is_space(*sequence)) {
        consume(sequence);
    }

    const char* start_addy = sequence;
    switch(peek(sequence)) {
        case '\n':
        case '\r':
                if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    size_t start_of_h1_text = 3;
                    char* str = copy_string(start_addy + start_of_h1_text, (sequence-(start_addy - start_of_h1_text)));

                    return (struct Token){str, Heading1};
                }
                else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    int start_of_h2_text = 4;
                    char* str = copy_string(start_addy + start_of_h2_text, sequence-start_addy + start_of_h2_text);

                    return (struct Token){str, Heading2};
                }
                else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    int start_of_h3_text = 5;
                    char* str = copy_string(start_addy + start_of_h3_text, sequence-start_addy + start_of_h3_text);

                    return (struct Token){str, Heading3};
                }
                else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == '#' && look_ahead(sequence, 5) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    int start_of_h4_text = 6;
                    char* str = copy_string(start_addy + start_of_h4_text, sequence-start_addy + start_of_h4_text);

                    return (struct Token){str, Heading4};
                }
                else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == '#' && look_ahead(sequence, 5) == '#' && look_ahead(sequence, 6) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    int start_of_h5_text = 7;

                    char* str = copy_string(start_addy + start_of_h5_text, sequence-start_addy + start_of_h5_text);

                    return (struct Token){str, Heading5};
                }
                else if(look_ahead(sequence, 1) == '#' && look_ahead(sequence, 2) == '#' && look_ahead(sequence, 3) == '#' && look_ahead(sequence, 4) == '#' && look_ahead(sequence, 5) == '#' && look_ahead(sequence, 6) == '#' && look_ahead(sequence, 7) == ' ') {
                    consume_until_linebreak_or_null(sequence);

                    size_t start_of_h6_text = 8;
                    char* str = copy_string(start_addy + start_of_h6_text, sequence-start_addy + start_of_h6_text);

                    return (struct Token){str, Heading6};
                }
                else {
                    consume_until_linebreak_or_null(sequence);

                    char* str = copy_string(start_addy, sequence-start_addy);

                    return (struct Token){str, Text};
                }
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
            consume_until_linebreak_or_null(sequence);
            char* str = copy_string(start_addy, sequence-start_addy);
            return (struct Token){str, Text};
    }
	return (struct Token){"", Unknown};
}

int main(void) {
    struct Token token = next();
    printf("lexeme: %s | type: %s", token.lexeme, get_token_type_string(token.type));
    free(token.lexeme);
    return 0;
}