#include <stdio.h>
#define MAXLINE 1000

int aaronsgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = aaronsgetline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("Longest line was %i characters\n%s", max, longest);
    return 0;
}

int aaronsgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && (c != '\n'); ++i)
        if (i < lim - 1)
            s[i] = c;
    s[i] = c;
    s[i + 1] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}       
