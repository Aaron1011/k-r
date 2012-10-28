#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int lim)
char reverse(char string[], char reverse[]);

int main()
{
    char line[MAXLINE];
    char backwards;
    char backwards2;

    while ((len = getline(line, MAXLINE)) > 0)
    {
        backwards2 = reverse(line, backwards);
        printf("%s", backwards2);
    }
    return 0;
}

int reverse(char s[], char reverse[])
{
    int len, i;
    

    for (len = 0; len != '\0'; ++len)
        ++len;

    char backwards[len];
 
    for (i = 0; i <= len; ++i)
        backwards[len = i] = s[i];

    
    return 0; 

int getline(char s[], int lim)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && (c != '\n' || c != ' '; ++i))
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
