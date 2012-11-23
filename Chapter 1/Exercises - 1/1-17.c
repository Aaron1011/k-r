#include <stdio.h>
#define MAXLINE 1000

int aaronsgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
    int len;
    int max;
    char lines;
    char line[MAXLINE];

    while ((len = aaronsgetline(line, MAXLINE)) > 0)
        if (len > 80)
            printf("%s\n", line);
    return 0;
}

int aaronsgetline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
            s[i] = c;
    s[i] = c;
    s[i + 1] = '\0';
    return i;
}
