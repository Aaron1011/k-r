#include <stdio.h>
#define MAXLINE 1000

int aaronsgetline(char line[], int maxline);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = aaronsgetline(line, MAXLINE)) > 0)
        if (len != 1)
            printf("%s\n", line);
    return 0;
}
            


int aaronsgetline(char s[], int lim)
{
    int c, i, orig;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[i] = c;
    orig = i;
    i--;
    for (i; i >= 0; --i)
    {
        if (s[i] == ' ' || s[i] == '\t')
        {
            printf("Hit space/tab\n");
            s[i] = '\0';
        }
        else
            break;
    }
    s[orig] = c;
    s[orig + 1] = '\0';
   
    return orig;
}
