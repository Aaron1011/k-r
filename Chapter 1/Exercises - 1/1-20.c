#include <stdio.h>
#define TABSTOP 8
#define MAXLINE 1000

main()
{
    int c, i, l;
    char str[MAXLINE];

    i = 0;

    while ((c = getchar()) != EOF)
    {
        if  (c == '\t')
            for (l = 0; l < TABSTOP; ++l)
            {
                str[i+l] = ' ';
            }
        else
            str[i] = c;
        ++i;
    }
    printf("%s\n", str);
}
