#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "copy.h"

int main(void) {
    const char* sequence = "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic* and **bold**";
    for(Token token = next(&sequence); token.type != End; token = next(&sequence)) {
        char* copied_result = copy_string(token.start, token.end-token.start);
        printf("type: %s | string: %s | start: %p | end: %p\n", get_token_type_string(token.type), copied_result, token.start, token.end);
    }
    return 0;
}

// TODO:
// - TODO: !!!! Differentiate between diff. headings.
// - Backticks into code.
// bold with 2 "_"s.