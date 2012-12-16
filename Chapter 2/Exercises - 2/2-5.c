#include <stdio.h>
#define MAXLINE 1000


int any(char s1[], char s2[]);
int contains(char str[], char c);
int aaronsgetline(char s[], int lim);

int main()
{
    char line[MAXLINE];
    char s2[MAXLINE] = "abcd";

    while (aaronsgetline(line, MAXLINE) > 0)
    {
        printf("Match at %i\n", any(line, s2));
    }
    return 0;
}


int any(char s1[], char s2[])
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
    	if (contains(s2, s1[i]))
                return i;
    return -1;
}


int contains(char str[], char c)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
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
