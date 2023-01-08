#include "lexer.h"
#include "copy.h"
#include <stdio.h>

const char* start;

char peek_prev(const char* sequence){ 
    *sequence--;
    char prev_char = *sequence;
    *sequence++;
    return prev_char;
}

char peek(const char* sequence) {
    return *sequence;
}

char get(const char** sequence) {
    return *(*sequence)++;
}

char* get_token_type_string(size_t token) {
    switch(token) {
        case 0: return "Number";
        case 1: return "Text";
        case 2: return "GreaterThan";
        case 3: return "HashTag";
        case 4: return "Dash";
        case 5: return "ExclamationMark";
        case 6: return "Asterisk";
        case 7: return "Underscore";
        case 8: return "Backtick";
        case 9: return "Linebreak";
        case 10: return "Unknown";
        case 11: return "End";
        case 12: return "Heading";
        default: return "Unknown";
    }
}


bool is_identifier_char(char c) {
  switch (c) {
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
    case 'å':
    case 'ä':
    case 'ö':
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
    case 'Å':
    case 'Ä':
    case 'Ö':
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
      return true;
    default:
      return false;
  }
}

bool is_digit(char c) {
  switch (c) {
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
      return true;
    default:
      return false;
  }
}

//

size_t line;
size_t position;

Token next(const char** sequence) {
    switch(peek(*sequence)) {
        case '\0':
          return (Token){End, *sequence, ++(*sequence)};
        case '\n':
        case '\r':
          ++line;
          return (Token){Linebreak, *sequence, ++(*sequence)};
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
        case 'å':
        case 'ä':
        case 'ö':
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
        case 'Å':
        case 'Ä':
        case 'Ö':
            start = *sequence;
            while(is_identifier_char(peek(*sequence))) get(sequence);
            return (Token){Letters, start, *sequence};
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
            start = *sequence;
            while(is_digit(peek(*sequence))) get(sequence);
            return (Token){Number, start, *sequence};
        case '#':
            start = *sequence;
            // Headings can only start on a new line.
            if (peek_prev(*sequence) == '\n' || peek_prev(*sequence) == '\r') {
              while(peek(*sequence) == '#') get(sequence);
              if(peek(*sequence) == ' ') { // Headings have to end with a space.
                return (Token){Heading, start, *sequence};
              } else {
                return (Token){Letters, start, *sequence};
              }
            } else {
              return (Token){HashTag, start, ++(*sequence)};
            }
        default:
            return (Token){Unknown, *sequence, ++(*sequence)};
    }
}
