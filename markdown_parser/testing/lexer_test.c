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

void test_next_heading(void) {
    char* text = "\n# ";
    Token token = next(&text);

    if(token.type == Heading) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading", get_token_type_string(token.type));
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

void test_next_bold(void) {
    const char* sequence = "\n**asd";
    Token token = next(&sequence);

    if(token.type == Bold) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Bold", get_token_type_string(token.type));
    }   
}

void test_next_bold2(void) {
    const char* sequence = "**asd**";
    Token token = next(&sequence);

    if(token.type == Bold) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Bold", get_token_type_string(token.type));
    }   
}
