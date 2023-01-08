#include "lexer_test.h"
#include "../lexer.h"
#include <stdio.h>
#include "tests.h"
#include <string.h>

void test_next_letters(void) {
    char* text = "heading";
    Token token = next(&text);

    if(token.type == Letters) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Letters", get_token_type_string(token.type));
    }
}

void test_next_heading(void) {
    char* text = "\n# ";
    next(&text);
    Token token = next(&text);

    if(token.type == Heading) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Heading", get_token_type_string(token.type));
    }
}

void test_next_letters_that_could_be_thought_of_heading(void) {
    char* text = "\n####### ";
    next(&text);
    Token token = next(&text);

    if(token.type == Letters) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Letters", get_token_type_string(token.type));
    }
}

void test_next_numbers(void) {
    char* text = "22233311";
    Token token = next(&text);

    if(token.type == Number) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Number", get_token_type_string(token.type));
    }
}

void test_next_blockquote(void) {
    char* text = "\n> ";
    next(&text);
    Token token = next(&text);

    if(token.type == Blockquote) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Blockquote", get_token_type_string(token.type));
    }
}