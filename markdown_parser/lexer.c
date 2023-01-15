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

char peek_next(const char* sequence){ 
    ++sequence;
    char next_char = *sequence;
    sequence--;
    return next_char;
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
        case 0: return "Text";
        case 1: return "Blockquote";
        case 2: return "Dash";
        case 3: return "ExclamationMark";
        case 4: return "Asterisk";
        case 5: return "Underscore";
        case 6: return "Backtick";
        case 7: return "Linebreak";
        case 8: return "Unknown";
        case 9: return "End";
        case 10: return "Heading";
        case 11: return "ListItem";
        case 12: return "NumberedListItem";
        case 13: return "Italic";
        case 14: return "Bold";
        default: return "Unknown";
    }
}

bool is_line_break(char c) {
  switch(c) {
    case '\n':
    case '\r':
      return true;
    default: 
      return false;
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
    case ':':
    case ';':
    case ' ':
    case '.':
    case ',':
    case '!':
    case '@':
    case '^': // TODO: Might change cuz footnotes https://help.obsidian.md/How+to/Format+your+notes#Footnotes.
    case '%': // TODO: Might change cuz comments https://help.obsidian.md/How+to/Format+your+notes#Comments.
    case '&':
    case '?':
    case '|':
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
        case '%':
        case '_': // TODO: this will change cuz italic and strong text.
            start = *sequence;
            while(is_identifier_char(peek(*sequence))) consume(sequence);
            return (Token){Text, start, *sequence};
        case '`':
            return (Token){Backtick, *sequence, ++(*sequence)};
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
              // Numbered list items have to have a space after dot.
              if (peek(*sequence) == ' ') { 
                return (Token){NumberedListItem, start, *sequence};
              } else {
                return (Token){Text, start, --(*sequence)};
              }
            }
            return (Token){Text, start, *sequence};
        case '#':
            start = *sequence;
            size_t amount_of_hashes = 0;
            // Headings can only start on a new line.
            if(is_line_break(peek_prev(*sequence))) {
              while(peek(*sequence) == '#') {
                consume(sequence);
                ++amount_of_hashes; // We are calculating the amount of hashes because if(amount_of_hashes > 6) then it would be <h6+> and it's not supported by HTML5.
              }
              if(peek(*sequence) == ' ' && amount_of_hashes <= 6) { // Headings have to end with a space.
                consume(sequence);
                return (Token){Heading, start, *sequence};
              } else {
                consume(sequence);
                return (Token){Text, start, *sequence};
              }
            } else {
              consume(sequence);
              return (Token){Text, start, *sequence};
            }
        case '>':
          start = *sequence;
          // Blockquotes can only start on a new line.
          if(is_line_break(peek_prev(*sequence))) {
              consume(sequence);
              return (Token){Blockquote, start, *sequence};
          } else {
              consume(sequence);
              return (Token){Text, start, *sequence};
          }
        case '-':
          start = *sequence;
          // List items can only start on a new line.
          if(is_line_break(peek_prev(*sequence))) {
            consume(sequence);
            if(peek(*sequence) == ' ') {
              while(is_identifier_char(**sequence)) consume(sequence);
              // TODO: do we want to capture the text within the list item here?
              consume(sequence);
              return (Token){ListItem, start, *sequence};
            }
            else {
              while(is_identifier_char(**sequence)) consume(sequence);
              consume(sequence);
              return (Token){Text, start, *sequence};
            }
          } else {
              consume(sequence);
              return (Token){Text, start, *sequence};
          }
        case '*':
          start = *sequence;

          // Handling list item.
          if(peek_prev(*sequence) == '\n' && peek_next(*sequence) == ' ') {
            while(is_identifier_char(peek(*sequence))) consume(sequence);
            consume(sequence);
            return (Token){ListItem, start, *sequence};
          }

          // Handling if it's italic (*...) or bold (**...).
          if(is_identifier_char(peek_next(*sequence))) {
            // Potential italic because there was 1 '*' only.
            while(is_identifier_char(**sequence)) consume(sequence);
            if(peek(*sequence) == '*' || is_line_break(peek(*sequence))) {
              // Italic text
              consume(sequence);
              return (Token){Italic, start, *sequence};
            }
            else {
              // Regular text
              consume(sequence);
              return (Token){Text, start, *sequence};
            }
          // Checking if there is 2 '*'s in a row.
          } else if(peek_next(*sequence) == '*') {
            consume(sequence);
            if(peek_next(*sequence) == ' ') {
              // Not bold because it was '** '
              while(is_identifier_char(**sequence)) consume(sequence);

              consume(sequence);
              return (Token){Text, start, *sequence}; // TODO get rid of the potential *'s.
            }
            else if (is_identifier_char(peek_next(*sequence))) {
              // Bold because an identifier was after the **'s.
              while(is_identifier_char(**sequence)) consume(sequence);

              if(is_line_break(peek(*sequence))) {

                  consume(sequence);
                  return (Token){Bold, start, *sequence}; // TODO get rid of the *'s.
              }
              else if(peek(*sequence) == '*' && peek_next(*sequence) == '*') {

                  consume(sequence);
                  return (Token){Bold, start, *sequence}; // TODO get rid of the *'s.
                  // strong text.
              } 
              else {
                consume(sequence);
                return (Token){Text, start, *sequence};
              }
            } else {
                consume(sequence);
                return (Token){Text, start, *sequence};
            }
          }
        // case '_':
          // TODO:
        default:
            return (Token){Unknown, *sequence, ++(*sequence)};
    }
}
