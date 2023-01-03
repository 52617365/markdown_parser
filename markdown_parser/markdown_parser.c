#define SPACE22 32
#define TOKENS_SIZE 15

// char* identify_token(const char* token);

struct Token {
    char* token;
    char* name;
};

struct Token markdown_tokens[TOKENS_SIZE] = {{"> ", "blockquote"}, {"- ", "list_member"}, {"1. ", "numbered_list_member"}, {"# ", "h1_title"}, {"## ", "h2_title"}, {"### ", "h3_title"}, {"#### ", "h4_title"}, {"##### ", "h5_title"}, {"###### ", "h6_title"}, {"*", "italic_text"}, {"_", "italic_text"}, {"**", "bold_text"}, {"__", "bold_text"}, {"`", "code"}, {"```", "code_block"}};

int main() {
    for (int i = 0; i < TOKENS_SIZE; i++) {
        printf("Token: '%s', name: '%s'\n", markdown_tokens[i].token, markdown_tokens[i].name);
    }
    return 0;
}
// token: "> ", name: "blockquote", "- ", "1. ", "# ", "## ", "### ", "#### ", "##### ", "###### ", "*", "_", "**", "__", "```", "`"

// char* identify_token(const char* token) {
//     if (token == "> ") {
//         return "blockquote";
//     }
//     if (token == "- ") {
//         return "list";
//     }
//     if (token == "1. ") {
//         return "numbered_list";
//     }
//     if (token == "# ") {
//         return "h1_title";
//     }
//     if (token == "## ") {
//         return "h2_title";
//     }
//     if (token == "### ") {
//         return "h3_title";
//     }
//     if (token == "#### ") {
//         return "h4_title";
//     }
//     if (token == "##### ") {
//         return "h5_title";
//     }
//     if (token == "###### ") {
//         return "h6_title";
//     }
//     if (token == "*") {
//         return "italic_text";
//     }
//     if (token == "_") {
//         return "italic_text";
//     }
//     if (token == "**") {
//         return "bold_text";
//     }
//     if (token == "__") {
//         return "bold_text";
//     }
//     if (token == "`") {
//         return "code_text";
//     }
//     if (token == "```") {
//         return "code_block";
//     }
// }
// "> " is a blockquote.
// "- " is a list item.
// "1. " is a numbered list member.
// "# " is a h1 title.
// "## " is a h2 title.
// "### " is a h3 title.
// "#### " is a h4 title.
// "##### " is a h5 title.
// "###### " is a h6 title.
// *This text will be italic*
// _This text will also be italic_
// **This text will be bold**
// __This text will also be bold__
// _You **can** combine them_
// Text inside `backticks` on a line will be formatted like code. (<code></code>)
// ``` is a code block quote.