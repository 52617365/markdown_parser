#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int main(void) {
    // const char* sequence = "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";
    const char* sequence = "hellobrother\nhellobrother2\n# hello";
    Token token = next(&sequence);
    Token token2 = next(&sequence);
    Token token3 = next(&sequence);
    Token token4 = next(&sequence);
    Token token5 = next(&sequence);
    printf("type: %s | start: %p | end: %p\n", get_token_type_string(token.type), token.start, token.end);
    printf("type: %s | start: %p | end: %p\n", get_token_type_string(token2.type), token2.start, token2.end);
    printf("type: %s | start: %p | end: %p\n", get_token_type_string(token3.type), token3.start, token3.end);
    printf("type: %s | start: %p | end: %p\n", get_token_type_string(token4.type), token4.start, token4.end);
    printf("type: %s | start: %p | end: %p\n", get_token_type_string(token5.type), token5.start, token5.end);
    return 0;
}