#include <stdio.h>
#define MAXLINE 1000
#define MAXSPACE 8

main()
{
    int c, i, spacecnt;
    char str[MAXLINE];
    for (i = 0; i <= MAXLINE; ++i)
        str[i] = 0;
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
        {
            str[i] = c;
            ++spacecnt;
        }
        else
            str[i] = c;
        ++i;

    }
    str[i - 1] = '\0';
    printf("%s\n", str);
}
