#include "lexer_test.h"
#include "../token.h"
#include "../lexer.h"
#include <stdio.h>
#include "tests.h"

void test_next_h1(void) {
    char* example_h1_heading = "\n# heading";
    Token token = next(&example_h1_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading1) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading1'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}

void test_next_h2(void) {
    char* example_h2_heading = "\n## heading";
    Token token = next(&example_h2_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading2) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading2'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}

void test_next_h3(void) {
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
void test_next_h4(void) {
    char* example_h4_heading = "\n#### heading";
    Token token = next(&example_h4_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading4) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading4'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}

void test_next_h5(void) {
    char* example_h5_heading = "\n##### heading";
    Token token = next(&example_h5_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading5) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading5'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}
void test_next_h6(void) {
    char* example_h6_heading = "\n###### heading";
    Token token = next(&example_h6_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading6) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Heading6'");
        }
    } else {
        LOG_RED("token.lexeme was not 'heading'");
    }
}
void test_next_text(void) {
    char* example_text = "\ntext";
    Token token = next(&example_text);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Text) { 
            LOG_GREEN("PASS");
        } else {
            LOG_RED("token.type was not 'Text'");
        }
    } else {
        LOG_RED("token.lexeme was not 'text'");
    }
}