#include "lexer_test.h"
#include "../token.h"
#include "../lexer.h"
#include <stdio.h>
#include "tests.h"
#include <string.h>

void test_next_h1(void) {
    char* example_h1_heading = "\n# heading";
    Token token = next(&example_h1_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading1) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading1", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}

void test_next_h2(void) {
    char* example_h2_heading = "\n## heading";
    Token token = next(&example_h2_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading2) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading2", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}

void test_next_h3(void) {
    char* example_h3_heading = "\n### heading";
    Token token = next(&example_h3_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading3) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading3", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}
void test_next_h4(void) {
    char* example_h4_heading = "\n#### heading";
    Token token = next(&example_h4_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading4) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading4", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}

void test_next_h5(void) {
    char* example_h5_heading = "\n##### heading";
    Token token = next(&example_h5_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading5) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading5", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}
void test_next_h6(void) {
    char* example_h6_heading = "\n###### heading";
    Token token = next(&example_h6_heading);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Heading6) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Heading6", token.lexeme);
        }
    } else {
        LOG_RED("token.lexeme", "heading", token.lexeme);
    }
}
void test_next_text(void) {
    char* example_text = "\ntext";
    Token token = next(&example_text);

    if(strcmp(token.lexeme, "heading") == 0) {
        if(token.type == Text) { 
            PRINT_SUCCESS();
        } else {
            LOG_RED("token.type", "Text", get_token_type_string(token.type));
        }
    } else {
        LOG_RED("token.lexeme", "Text", token.lexeme);
    }
}