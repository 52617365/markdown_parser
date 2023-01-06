#include <stdlib.h>
#include <stdbool.h>

void consume(const char* sequence) {
    sequence++;
}

char peek(const char* sequence) {
    return *sequence;
}

char get(const char* sequence) {
    return *sequence++;
}

char look_ahead(const char* sequence, size_t n) {
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

void consume_until_linebreak_or_null(const char* sequence) {
        while(*sequence != '\n' && *sequence != '\r' && *sequence != '\0') {
            consume(sequence);
        }
        // here we have arrived at one of the checked characters, 
        // reverting one to get back to the non checked characters.
        // TODO: check if this is even needed.
        // sequence--;
}

bool is_space(char c) {
    switch(c) {
        case ' ':
        case '\t':
            return true;
        default:
            return false;
    }
}

const char* get_token_type_string(size_t token) {
    if(token == 0) {
        return "Text";
    }
    if(token==1) {
        return "BoldText";
    }
    if(token==2) {
        return "ItalicText";
    }
    if(token==3) {
        return "Blockquote";
    }
    if(token==4) {
        return "Heading1";
    }
    if(token==5) {
        return "Heading2";
    }
    if(token==6) {
        return "Heading3";
    }
    if(token==7) {
        return "Heading4";
    }
    if(token==8) {
        return "Heading5";
    }
    if(token==9) {
        return "Heading6";
    }
    if(token==10) {
        return "List";
    }
    else {
        return "Unknown";
    }
}