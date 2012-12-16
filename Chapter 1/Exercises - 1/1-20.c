#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000

main()
{
    int c, i, l;
    char str[MAXLINE];
    for (i = 0; i <= MAXLINE; ++i)
        str[i] = 0;

    i = 0;

    while ((c = getchar()) != EOF)
    {
        if  (c == '\t')
        {
            for (l = 0; l < TABSTOP; ++l)
                str[i+l] = ' ';
            i += TABSTOP - 1;
        }
        else
            str[i] = c;
        ++i;
    }
    str[i] = '\0';
    for (l = 0; l <= i; l++)
        printf("%c", str[l]);

}
