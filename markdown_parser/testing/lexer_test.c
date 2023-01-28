#include "lexer_test.h"
#include "../lexer.h"
#include <stdio.h>
#include "tests.h"
#include <string.h>

void test_next_letters(void) {
    char* text = "heading";
    Token token = next(&text);

    if(token.type == Text) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Text", get_token_type_string(token.type));
    }
}

void test_next_heading1(void) {
    char* text = "\n# ";
    Token token = next(&text);

    if(token.type == Heading1) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading1", get_token_type_string(token.type));
    }
}

void test_next_heading2(void) {
    char* text = "\n## ";
    Token token = next(&text);

    if(token.type == Heading2) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading2", get_token_type_string(token.type));
    }
}

void test_next_heading3(void) {
    char* text = "\n### ";
    Token token = next(&text);

    if(token.type == Heading3) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading3", get_token_type_string(token.type));
    }
}

void test_next_heading4(void) {
    char* text = "\n#### ";
    Token token = next(&text);

    if(token.type == Heading4) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading4", get_token_type_string(token.type));
    }
}

void test_next_heading5(void) {
    char* text = "\n##### ";
    Token token = next(&text);

    if(token.type == Heading5) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading5", get_token_type_string(token.type));
    }
}

void test_next_heading6(void) {
    char* text = "\n###### ";
    Token token = next(&text);

    if(token.type == Heading6) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading6", get_token_type_string(token.type));
    }
}

void test_next_letters_that_could_be_mistaken_for_heading(void) {
    char* text = "\n####### ";
    Token token = next(&text);

    if(token.type == Text) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Text", get_token_type_string(token.type));
    }
}

void test_next_numbers(void) {
    char* text = "22233311";
    Token token = next(&text);

    if(token.type == Text) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Text", get_token_type_string(token.type));
    }
}

void test_next_blockquote(void) {
    char* text = "\n>";
    Token token = next(&text);

    if(token.type == Blockquote) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Blockquote", get_token_type_string(token.type));
    }
}

void test_next_list_item(void) {
    char* text = "\n- ";
    Token token = next(&text);

    if(token.type == ListItem) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "ListItem", get_token_type_string(token.type));
    }   
}

void test_next_list_item2(void) {
    const char* sequence = "\n* asd";
    Token token = next(&sequence);

    if(token.type == ListItem) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "ListItem", get_token_type_string(token.type));
    }      
}

void test_next_numbered_list_item(void) {
    char* text = "\n1. ";
    Token token = next(&text);

    if(token.type == NumberedListItem) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "NumberedListItem", get_token_type_string(token.type));
    }   
}

void test_next_italic(void) {
    const char* sequence = "\n*asd";
    Token token = next(&sequence);

    if(token.type == Italic) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Italic", get_token_type_string(token.type));
    }   
}

void test_next_italic2(void) {
    const char* sequence = "*asd*";
    Token token = next(&sequence);

    if(token.type == Italic) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Italic", get_token_type_string(token.type));
    }   
}

void test_next_strong(void) {
    const char* sequence = "\n**asd";
    Token token = next(&sequence);

    if(token.type == Strong) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Strong", get_token_type_string(token.type));
    }   
}

void test_next_strong2(void) {
    const char* sequence = "**asd**";
    Token token = next(&sequence);

    if(token.type == Strong) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Strong", get_token_type_string(token.type));
    }   
}
