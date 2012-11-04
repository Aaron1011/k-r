#include <stdio.h>
#define MAXLINE 1000
#define MAXSPACE 8

main()
{
    int c, i, spacecnt;
    char str[MAXLINE];
    spacecnt = 0;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        if (spacecnt == MAXSPACE)
        {
            i -= spacecnt;
            str[i] = '\t';
            spacecnt = 0;
            ++i;
        }
        if (c == ' ')
            ++spacecnt;
        else
            str[i] = c;
        ++i;

    }
    printf("%s\n", str);
}
