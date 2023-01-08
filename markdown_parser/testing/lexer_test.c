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

