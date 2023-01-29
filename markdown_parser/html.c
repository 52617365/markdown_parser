#include "html.h"

Tag markdown_to_html(size_t token) {
    switch(token) {
        case Heading1:
            return (Tag){"<h1>", "</h1>"};
        case Heading2:
            return (Tag){"<h2>", "</h2>"};
        case Heading3:
            return (Tag){"<h3>", "</h3>"};
        case Heading4:
            return (Tag){"<h4>", "</h4>"};
        case Heading5:
            return (Tag){"<h5>", "</h5>"};
        case Heading6:
            return (Tag){"<h6>", "</h6>"};
        case Text:
        case Linebreak:
            return (Tag){"", ""};
        case Blockquote:
            return (Tag){"<blockquote>", "</blockquote>"};
        case Code:
            return (Tag){"<code>", "</code>"};
        case ListItem:
        case NumberedListItem:
            // TODO: we have to somehow include this inside <ul> or <ol>
            return (Tag){"<li>", "</li>"};
        case Italic:
            return (Tag){"<em>", "</em>"};
        case Strong:
            return (Tag){"<strong>", "</strong>"};
        default:
            return (Tag){NULL, NULL};
    }
}
