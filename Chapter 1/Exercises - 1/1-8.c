#include <stdio.h>

/* count blanks, tabs, and newlines */

main()
{
    double b, t, n; /* variables for blanks, tabs, and newlines */
    int c;          /* variable for holding current character */
    b=t=n=0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++n;
        if (c == ' ')
            ++b;
        if (c == '\t')
            ++t;
    }
    printf("Blanks: %.0f\nTabs: %.0f\nNewlines: %.0f\n", b, t, n);

}
