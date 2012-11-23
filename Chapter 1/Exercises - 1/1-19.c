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
        //printf("%s", line);
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
    s[len] = '\n';
    for (i = 0; i <= len -1; ++i)
    {
        if (copied[i] == '\n')
            break;
        s[len - 1 - i] = copied[i];
    }
    printf("%s", s); 
    return 0; 
}
int mygetline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && (c != '\n'); ++i)
    {
        if (i < lim - 1)
            s[i] = c;
    }
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
