#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (len != 1)
            printf("%s\n", line);
    return 0;
}
            


int getline(char s[], int lim)
{
    int c, i, orig;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[i] = c;
    orig = i;
    for (i; i >= 0; --i)
    {
        if (s[i] == ' ' || s[i] == '\t')
            s[i] = '\0';
        else
            break;
    }
    if (c == '\n')
    {
        s[orig] = c;
        ++orig;
    }
        
    s[orig] = '\0';
   
    return orig;
}
