#include <stdbool.h>  
bool is_styling_identifier(char c);
bool is_identifier_char(char c);
bool is_number(char c);
// const char* example_markdown= "# h1_title\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold** *";
const char* example_markdown = "> hello";
// Stuff that will not be supported because I don't need them:
// Tables, Math, Diagram, Callouts

bool is_unwanted_space(char c) {
    switch(c) {
        case '\t':
        case '\r':
            return true;
        default:
            return false;
    }
}

bool is_space(char c) {
    return c == ' ';
}

char peek() {
    return *example_markdown;
}

char get() {
    return *example_markdown++;
}

char* next() {
    while (is_unwanted_space(peek())) get();

    switch(peek()) {
        case '\0':
            return "end";
        case '#':
        case '-':
        case '>':
            return "styling";
        case ' ':
            return "space";
        case '\n':
            return "line_break";
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
            return "identifier";
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return "number";
        default:
            return "unexpected";
    }
}

bool token_is_bad(const char* token) {
    return token == "end" || token == "unexpected";
}

// prev has to be nullbyte or newline for the blockquote or anything else to work.

int main() {
    for(int i = 0; example_markdown[i] != 0; i++) {
        char* token = next();
        get();
        printf("%c is %s\n", peek(), token);
    }
    return 0;
}