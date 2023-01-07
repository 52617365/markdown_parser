#include "lexer_test.h"
#include "../token.h"
#include "../lexer.h"
#include <stdio.h>
#include "tests.h"
void test_next_heading(void) {
    char* example_h3_heading = "\n### heading";
    Token token = next(&example_h3_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading3) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading3'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}
void test_wont_pass(void) {
    LOG_RED("token.lexeme was not 'heading'");
}