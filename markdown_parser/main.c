#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

int main(void) {
    // const char* sequence = "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";
    // const char* sequence = "hellobrother\nhellobrother2\n# hello\n########asd\n>blockquote\n- \n1. ";
    const char* sequence = "*hello*";
    for(Token token = next(&sequence); token.type != End; token = next(&sequence)) {
        printf("type: %s | start: %p | end: %p\n", get_token_type_string(token.type), token.start, token.end);
    }
    return 0;
}