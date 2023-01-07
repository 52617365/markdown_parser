#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"
#include "token.h"
// TODO: make test for the headings, then support other stuff.
int main(void) {
    char* sequence = "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italic_text_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n==strike_through==\n- list_member\n> blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic and **bold**";
    Token token = next(&sequence);
    free(token.lexeme);
    Token token2 = next(&sequence);
    printf("lexeme: %s | type: %s | line: %zu\n", token.lexeme, get_token_type_string(token.type), token.line);
    printf("lexeme: %s | type: %s | line: %zu\n", token2.lexeme, get_token_type_string(token2.type), token2.line);
    free(token.lexeme);
    return 0;
}