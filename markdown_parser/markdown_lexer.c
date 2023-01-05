#include <stdbool.h>  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// const char* example_markdown= "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";

const char* example_markdown= "\n####### h2";
int line;
char* old_src;


enum
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
    List
};

struct Token
{
    int type;
    const char* lexeme;
};

char peek_prev(void) {
    *example_markdown--;
    char prev_char = *example_markdown;
    *example_markdown++;
    return prev_char;
}

char peek_curr(void) {
    return *example_markdown;
}

char peek_next(void) {
    *example_markdown++;
    char next_char = *example_markdown;
    *example_markdown--;
    return next_char;
}

char lookahead_n_times(int n) {
    int i = n;
    for(; i > 0; i--) {
        *example_markdown++;
    }
    char peeked_char = *example_markdown;
    for(; i < n; i++) {
        *example_markdown--;
    }
    return peeked_char;
}

bool is_space(char c) {
    switch(c) {
        case '\n':
        case '\r':
        case ' ':
        case '\t':
            return true;
        default:
            return false;
    }
}

bool is_a_fresh_line() {
    switch(peek_prev()) {
        case '\n':
        case '\r':
        case '\0':
            return true;
        default:
            return false;
    }

}

void next(void) {
    while(is_space(*example_markdown)) {
        *example_markdown++;
    }

    const char* start = &(example_markdown[2]);
    switch(peek_curr()) {
        case '#':
            if (is_a_fresh_line()) {
                if(lookahead_n_times(1) == ' ') {
                    printf("h1");
                    return;
                    // it's h1 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == ' ') {
                    printf("h2");
                    return;
                    // it's h2 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == '#' && lookahead_n_times(3) == ' ') {
                    printf("h3");
                    return;
                    // it's h3 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == '#' && lookahead_n_times(3) == '#' && lookahead_n_times(4) == ' ') {
                    printf("h4");
                    return;
                    // it's h4 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == '#' && lookahead_n_times(3) == '#' && lookahead_n_times(4) == '#' && lookahead_n_times(5) == ' ') {
                    printf("h5");
                    return;
                    // it's h5 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == '#' && lookahead_n_times(3) == '#' && lookahead_n_times(4) == '#' && lookahead_n_times(5) == '#' && lookahead_n_times(6) == ' ') {
                    printf("h6");
                    return;
                    // it's h6 header
                }
                else if(lookahead_n_times(1) == '#' && lookahead_n_times(2) == '#' && lookahead_n_times(3) == '#' && lookahead_n_times(4) == '#' && lookahead_n_times(5) == '#' && lookahead_n_times(6) == '#') {
                    printf("text");
                    return;
                    // it's h6 header
                }
                
            }
            else {
                const char* end = &(*example_markdown++);
                printf("Text: | value: %.*s\n", end-start, start);
                return;
            }

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
            while(*example_markdown != '\n' && *example_markdown != '\r') {
                *example_markdown++;
            }
            const char* end = &example_markdown;
            printf("Text | value: %.*s\n", end - start, start);
    }
}

int main(void) {
    next();
    next();
    return 0;
}