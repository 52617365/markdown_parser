#include "lexer.h"
#include "copy.h"
#include <stdio.h>

const char* start;
const char* end;

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

void consume(const char** sequence) {
  *(*sequence)++;
}


char* get_token_type_string(size_t token) {
    switch(token) {
        case 0: return "Text";
        case 1: return "Blockquote";
        case 2: return "Code";
        case 3: return "Linebreak";
        case 4: return "Unknown";
        case 5: return "End";
        case 6: return "Heading1";
        case 7: return "Heading2";
        case 8: return "Heading3";
        case 9: return "Heading4";
        case 10: return "Heading5";
        case 11: return "Heading6";
        case 12: return "ListItem";
        case 13: return "NumberedListItem";
        case 14: return "Italic";
        case 15: return "Strong";
        case 16: return "TERMINATE"; // TODO: Terminate when this gets called.
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
    case '_':
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

bool is_space(char c){ 
  switch(c) {
    case '\n':
    case '\r':
          ++line;
    case ' ':
    return true;
    default: return false;
  }
}


Token next(const char** sequence) {
    while(is_space(**sequence)) consume(sequence);
    switch(peek(*sequence)) {
        case '\0':
          return (Token){End, *sequence, ++(*sequence)};
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
            end = *sequence;
            consume(sequence);
            return (Token){Text, start, end};
        case '`':
          size_t amount_of_backticks = 0;
          while(peek(*sequence) == '`') {
            ++amount_of_backticks;
            consume(sequence);
          }
          start = *sequence;
          if (amount_of_backticks > 1) {
            while(**sequence != '`' && **sequence != '\0') consume(sequence);
            end = *sequence;
            while(**sequence == '`') consume(sequence);
            return (Token){Code, start, end};
          } else {
            while(**sequence != '`' && **sequence != '\0' && !is_line_break(**sequence)) consume(sequence);
            end = *sequence;
            while(**sequence == '`') consume(sequence);
            return (Token){Code, start, end};
          }
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
            while(is_digit(peek(*sequence))) consume(sequence);
            if (peek(*sequence) == '.') { 
              consume(sequence);
              // Numbered list items have to have a space after dot.
              if (peek(*sequence) == ' ') { 
                consume(sequence);
                start = *sequence;
                while(is_identifier_char(peek(*sequence))) consume(sequence);
                end = *sequence;
                consume(sequence);
                return (Token){NumberedListItem, start, end};
              } else {
                start = *sequence;
                while(is_identifier_char(peek(*sequence))) consume(sequence);
                end = *sequence;
                consume(sequence);
                return (Token){Text, start, end};
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
                start = *sequence;
                while(is_identifier_char(peek(*sequence))) consume(sequence);
                end = *sequence;
                consume(sequence);
                // TODO: determine the heading type here.
                size_t tokenType = get_heading_type(amount_of_hashes);
                return (Token){tokenType, start, end};
              }
            } else {
              consume(sequence);
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){Text, start, end};
            }
        case '>':
          // Blockquotes can only start on a new line.
          if(is_line_break(peek_prev(*sequence))) {
              consume(sequence);
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){Blockquote, start, end};
          } else {
              consume(sequence);
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){Text, start, end};
          }
        case '-':
          // List items can only start on a new line.
          start = *sequence;
          if(is_line_break(peek_prev(*sequence))) {
            consume(sequence);
            if(peek(*sequence) == ' ') {
              consume(sequence);
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){ListItem, start, end};
            }
            else {
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){Text, start, end};
            }
          } else {
              consume(sequence);
              start = *sequence;
              while(is_identifier_char(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              return (Token){Text, start, end};
          }
        case '*':
          start = *sequence;
          // Checking if list item.
          if(is_line_break(peek_prev(*sequence)) && peek_next(*sequence) == ' ') {
            consume(sequence);
            while(is_identifier_char(peek(*sequence))) consume(sequence);
            end = *sequence;
            consume(sequence);
            return (Token){ListItem, start, end};
          }

          // If user escaped the * then it's regular text.
          if(peek_prev(*sequence) == '\\') {
            while(is_identifier_char(peek(*sequence))) consume(sequence);
            end = *sequence;
            consume(sequence);
            return (Token){Text, start, end};
          }

          // Here we have a '*' + identifier so it's italic.
          if(is_identifier_char(peek_next(*sequence))) {
              consume(sequence);
              start = *sequence;
              while(peek(*sequence) != '*' && peek(*sequence) != '\0' && !is_line_break(peek(*sequence))) consume(sequence);
              end = *sequence;
              consume(sequence);
              consume(sequence);
              return (Token){Italic, start, end};
          }

          if(peek_next(*sequence) == '*') {
              consume(sequence);
              if(peek_next(*sequence) == '*') {
                consume(sequence);
                return (Token){Unsupported, start, start}; // TODO: terminate.
              }
              consume(sequence);
              start = *sequence;
              while(!is_line_break(peek(*sequence)) && peek(*sequence) != '\0' && peek(*sequence) != '*') consume(sequence);
              end = *sequence;
              if(peek_next(*sequence) == '*') consume(sequence); // if it's stopped with 2 *'s then consume both of them.
              consume(sequence);
              return (Token){Strong, start, end};
          }
      default:
          consume(sequence);
          return (Token){Unknown, *sequence, *sequence};
    }
}

size_t get_heading_type(size_t amount_of_hashes) {
  switch(amount_of_hashes) {
    case 1: return Heading1;
    case 2: return Heading2;
    case 3: return Heading3;
    case 4: return Heading4;
    case 5: return Heading5;
    case 6: return Heading6;
    default: return Unknown;
  }
}