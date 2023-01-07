#include "heading.h"
#include "copy.h"
char* start_of_heading_lexeme;
char* end_of_heading_lexeme;

Token handle_heading_if_present(char** sequence) {
    if(look_ahead(1, *sequence) == '#') {
        eat(1, sequence);
        if(look_ahead(1, *sequence) == ' ') {
            // h1 heading
            eat(2, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading1};
        } else if(look_ahead(1, *sequence) == '#' && look_ahead(2, *sequence) == ' ') {
            // h2
            eat(3, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading2};
        } else if(look_ahead(1, *sequence) == '#' && look_ahead(2, *sequence) == '#' && look_ahead(3, *sequence) == ' ') {
            // h3
            eat(4, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading3};
        } else if(look_ahead(1, *sequence) == '#' && look_ahead(2, *sequence) == '#' && look_ahead(3, *sequence) == '#' && look_ahead(4, *sequence) == ' ') {
            // h4
            eat(5, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading4};
        } else if(look_ahead(1, *sequence) == '#' && look_ahead(2, *sequence) == '#' && look_ahead(3, *sequence) == '#' && look_ahead(4, *sequence) == '#' && look_ahead(5, *sequence) == ' ') {
            // h5
            eat(6, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading5};
        } else if(look_ahead(1, *sequence) == '#' && look_ahead(2, *sequence) == '#' && look_ahead(3, *sequence) == '#' && look_ahead(4, *sequence) == '#' && look_ahead(5, *sequence) == '#' && look_ahead(6, *sequence) == ' ') {
            // h6
            eat(7, sequence);
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Heading6};
        } else {
            // only headings up to h6 are supported by obsidian. this is therefore text.
            start_of_heading_lexeme = *sequence;
            eat_until_linebreak_or_null(sequence);
            end_of_heading_lexeme = *sequence;

            char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
            return (Token){lexeme, Text};
            // it's text.
        }
    } else { 
                start_of_heading_lexeme = *sequence;
                eat_until_linebreak_or_null(sequence);
                end_of_heading_lexeme = *sequence;

                char* lexeme = copy_string(start_of_heading_lexeme, end_of_heading_lexeme-start_of_heading_lexeme);
                return (Token){lexeme, Text};
                // it's text.
    }
}