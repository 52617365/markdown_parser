#include "html.h"

Tag markdown_to_html(size_t token) {
    switch(token) {
        case Heading1:
            return (Tag){"<h1>", "TODO", "</h1>"};
        case Heading2:
            return (Tag){"<h2>", "TODO", "</h2>"};
        case Heading3:
            return (Tag){"<h3>", "TODO", "</h3>"};
        case Heading4:
            return (Tag){"<h4>", "TODO", "</h4>"};
        case Heading5:
            return (Tag){"<h5>", "TODO", "</h5>"};
        case Heading6:
            return (Tag){"<h6>", "TODO", "</h6>"};
        case Text:
        case Linebreak:
            return (Tag){"text", "TODO", "text"};
        case Blockquote:
            return (Tag){"<blockquote>", "TODO", "</blockquote>"};
        case Code:
            return (Tag){"<code>", "TODO", "</code>"};
        case ListItem:
        case NumberedListItem:
            // TODO: we have to somehow include this inside <ul> or <ol>
            return (Tag){"<li>", "TODO", "</li>"};
        case Italic:
            return (Tag){"<em>", "TODO", "</em>"};
        case Strong:
            return (Tag){"<strong>", "TODO", "</strong>"};
        default:
            return (Tag){"text", "error", "text"};
    }
}
