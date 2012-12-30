#include <stdio.h>
#define DEFAULT 0
#define IN_CHAR 1
#define CHAR_ESCAPE 2
#define POS_COMMENT 3
#define IN_COMMENT 4
#define POS_COMMENT_END 5
#define IN_STRING 6
#define POS_INSTRING_QUOTE 7
#define COMMENT_ESCAPE 8
main() /* Remove comments from input */
{
    int state = DEFAULT;
    int c;

    while ((c = getchar()) != EOF) {
        if (state == DEFAULT) {
            if (c == '/')
                state = POS_COMMENT;
            if (c == '"') {
                state = IN_STRING;
                putchar(c);
            }
            if (state == '\'') {
                state = IN_CHAR;
                putchar(c);
            }
            else
                putchar(c);
        }
        else if (state == IN_CHAR) {
            if (c == '\'') {
                state = DEFAULT;
                putchar(c);
            }
            if (c == '\\') {
                state = CHAR_ESCAPE;
                putchar(c);
            }
            else
                putchar(c);
        }
        else if (state == CHAR_ESCAPE) {
            state = IN_CHAR;
            putchar(c);
        }
        else if (state == IN_STRING) {
            if (c == '\\') {
                state = POS_INSTRING_QUOTE;
                putchar(c);
            }
            else
                putchar(c);
        }
        else if (state == POS_INSTRING_QUOTE) {
            state = IN_STRING;
            putchar(c);
        }
        else if (state == POS_COMMENT) {
            if (c == '*')
                state = IN_COMMENT;
            else {
                putchar('/');
                state = DEFAULT;
            }
        }
        else if (state == IN_COMMENT) {
            if (c == '*')
                state = POS_COMMENT_END;
        }
        else if (state == POS_COMMENT_END) {
            if (c == '/')
                state = DEFAULT;
            if (c == '\\') {
                state = COMMENT_ESCAPE;
                putchar(c);
            }
        }
        else if (state == COMMENT_ESCAPE) {
            state = IN_COMMENT;
            putchar(c);
        }


    }
    return 0;
}
