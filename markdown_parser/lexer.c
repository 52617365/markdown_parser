#include "lexer.h"
#include "copy.h"
#include <stdio.h>

const char* start;

char peek_prev(const char* sequence){ 
    --sequence;
    char prev_char = *sequence;
    sequence++;
    return prev_char;
}

char peek(const char* sequence) {
    return *sequence;
}

char get(const char** sequence) {
    return *(*sequence)++;
}

void consume(const char** sequence) {
  *(*sequence)++;
}


char* get_token_type_string(size_t token) {
    switch(token) {
        case 0: return "Number";
        case 1: return "Text";
        case 2: return "Blockquote";
        case 3: return "Dash";
        case 4: return "ExclamationMark";
        case 5: return "Asterisk";
        case 6: return "Underscore";
        case 7: return "Backtick";
        case 8: return "Linebreak";
        case 9: return "Unknown";
        case 10: return "End";
        case 11: return "Heading";
        case 12: return "ListItem";
        case 13: return "NumberedListItem";
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
    while(**sequence == ' ') get(sequence);
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
            while(is_identifier_char(peek(*sequence))) consume(sequence);
            return (Token){Letters, start, *sequence};
        case '_':
              // TODO: if next char is '_' then it's potential bold text.
              // we need to do a look ahead to know for sure.

              // TODO: if second is ' ' then it's potential italic text.
              // we once again need to do a look ahead to make sure.
        case '*':
            // TODO.
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
            if (peek(*sequence) == '.') { 
              consume(sequence);
              // numbered list items have to have a space after dot.
              if (peek(*sequence) == ' ') { 
                return (Token){NumberedListItem, start, *sequence};
              } else {
                return (Token){Number, start, --(*sequence)};
              }
            }
            return (Token){Number, start, *sequence};
        case '#':
            start = *sequence;
            size_t amount_of_hashes = 0;
            // Headings can only start on a new line.
            if(peek_prev(*sequence) == '\n' || peek_prev(*sequence) == '\r') {
              while(peek(*sequence) == '#') {
                get(sequence);
                ++amount_of_hashes; // we are calculating the amount of hashes because if(amount_of_hashes > 6) then it would be <h6+> and it's not supported by HTML5.
              }
              if(peek(*sequence) == ' ' && amount_of_hashes <= 6) { // Headings have to end with a space.
                return (Token){Heading, start, ++(*sequence)};
              } else {
                return (Token){Letters, start, ++(*sequence)};
              }
            } else {
              return (Token){Letters, start, ++(*sequence)};
            }
        case '>':
          start = *sequence;
          // Blockquotes can only start on a new line.
          if(peek_prev(*sequence) == '\n' || peek_prev(*sequence) == '\r') {
              return (Token){Blockquote, start, ++(*sequence)};
          } else {
              return (Token){Letters, start, ++(*sequence)};
          }
        case '-':
          start = *sequence;
          // List items can only start on a new line.
          if(peek_prev(*sequence) == '\n' || peek_prev(*sequence) == '\r') {
            consume(sequence);
            if(peek(*sequence) == ' ') {
              return (Token){ListItem, start, ++(*sequence)};
            }
            else {
              return (Token){Letters, start, ++(*sequence)};
            }
          } else {
              return (Token){Letters, start, *sequence};
          }
        default:
            return (Token){Unknown, *sequence, ++(*sequence)};
    }
}
