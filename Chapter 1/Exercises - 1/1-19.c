#include <stdio.h>
#define MAXLINE 1000

int mygetline(char s[], int lim);
int reverse(char string[]);
void copy(char to[], char from[]);

int main()
{
    char line[MAXLINE];
    int len, i;

    for (i = 0; i <= MAXLINE; ++i)
        line[i] = 0;

    while ((len = mygetline(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

int reverse(char s[])
{
    int len, i;
    char copied[MAXLINE];

    copy(copied, s);    

    for (len = 0; ; ++len)
        if (s[len] == '\n')
            break;
    printf("%i", len);
    for (i = 0; i <= len; ++i)
        s[len - i] = copied[i];

    
    return 0; 
}
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; c = getchar() != EOF && c != '\n'; ++i)
    {
        if (i < lim - 1)
            s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
