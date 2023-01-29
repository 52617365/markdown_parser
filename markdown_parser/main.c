#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "copy.h"
#include "html.h"

int main(void) {
    const char* sequence = "\n# h1_text\nnormal text\n## h2_title\n### h3_title\n#### h4_title\n##### h5_title\n###### h6_title\n*italic_text*\n_italictext_\n**bold_text**\n__bold_text__\n`code_text`\n```code_block```\n- list_member\n>blockquote\n1. numbered_list_member\n2. numbered_list_member\n*italic* and **bold**";
    FILE* html_output = fopen("output.html", "w");


    for(Token token = next(&sequence); token.type != End; token = next(&sequence)) {
        char* copied_result = copy_string(token.start, token.end-token.start);
        printf("type: %s | string: %s | start: %p | end: %p\n", get_token_type_string(token.type), copied_result, token.start, token.end);
        Tag html = markdown_to_html(token.type);
        // printf("html start tag: %s | html end tag: %s | html tag contents: %s\n", html.tag_start, html.tag_end, html.tag_contents);
        if (html.tag_start != NULL && html.tag_end != NULL) {
            fprintf(html_output,"%s%s%s",html.tag_start, copied_result, html.tag_end);
        }
        free(copied_result);
    }
    fclose(html_output);
    return 0;
}


// TODO in order:
// - Include the linebreaks in the html output.
// - Bold and italic with _ and - doesn't seem to work well.
// - We need the <ul> or <ol> in the list items.