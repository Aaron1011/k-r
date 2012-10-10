#include <stdio.h>

#define IN 1
#define OUT 0

/* print output one line at a time */

main()
{
    int c, nw, state;
    
    state = OUT;
    nw = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            printf("\n");
        }
        else if (state == IN)
            putchar(c);
        else if (state == OUT) {
            state = IN;
            putchar(c);
        }
    }
}
