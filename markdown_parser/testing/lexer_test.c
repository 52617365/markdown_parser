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

void test_next_letters_that_could_be_mistaken_for_heading(void) {
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
    char* text = "\n>";
    next(&text);
    Token token = next(&text);

    if(token.type == Blockquote) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Blockquote", get_token_type_string(token.type));
    }
}

void test_next_list_item(void) {
    char* text = "\n- ";
    next(&text);
    Token token = next(&text);

    if(token.type == ListItem) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "ListItem", get_token_type_string(token.type));
    }   
}

void test_next_numbered_list_item(void) {
    char* text = "\n1. ";
    next(&text);
    Token token = next(&text);

    if(token.type == NumberedListItem) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "NumberedListItem", get_token_type_string(token.type));
    }   
}

// Tests if the previously lexed token has the same end address as the successors start address. This is done to make sure that the whole source is covered. And that there is no off by one's etc.
void test_full_source_coverage(void) {
    const char* sequence = "hellobrother\nhellobrother2\n# hello\n########asd\n>blockquote\n- \n1. ";
    const char* prev_end;
    Token token = next(&sequence);
    prev_end = token.end;
    for(token = next(&sequence); token.type != End; token = next(&sequence)) {
        if (token.start != prev_end) {
            LOG_ADDRESS_RED("token.start", prev_end, token.start);
            return;
        }
        prev_end = token.end;
    }
    PRINT_SUCCESS();
}

void test_newline_italic_text(void) {
    const char* sequence = "\n_hellobrothermen";
    next(&sequence);
    Token token = next(&sequence);

    if(token.type == Italic) {
        PRINT_SUCCESS();
    } else {
        LOG_RED("token.type", "Italic", get_token_type_string(token.type));
    }   
}