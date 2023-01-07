#include <stdlib.h>
#include <stdbool.h>
#include "token.h"

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