#include "tests.h"

int main(void) {
    test_next_letters();
    test_next_heading();
    test_next_numbers();
    test_next_blockquote();
    test_next_letters_that_could_be_mistaken_for_heading();
    test_next_list_item();
    test_next_numbered_list_item();
    test_full_source_coverage();
    test_newline_italic_text();
    // define test function calls here.
}

