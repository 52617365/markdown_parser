#include "lexer.h"
#include "copy.h"
#include <stdio.h>
#include "token.h"
#include "heading.h"

size_t line;
const char* start_of_lexeme;
const char* end_of_lexeme;


Token next(char** sequence) {
    const char* start_addy = *sequence;
    switch(peek(*sequence)) {
        case '\n':
        case '\r':
            ++line;
            Token token = handle_heading_if_present(sequence); // TODO: this will go to a function in the future that handles all the other possibilities too. it's only here for now.
            token.line = line;
            return token;
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
            char* str = copy_string(start_addy, *sequence-start_addy);
            return (Token){str, Text};
        default:
            return (Token){"", Unknown};
    }
}