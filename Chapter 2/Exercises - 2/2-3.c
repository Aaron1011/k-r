#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int htoi(char s[]);
int aaronsgetline(char line[], int maxline);

main()
{
    int i, c;
    char line[MAXLINE];

    while (aaronsgetline(line, MAXLINE) > 0)
        printf("%i\n", htoi(line));
}

int htoi(char str[])
{
    int len, i, base10, mult;

    base10 = 0;
    mult = 1;
    len = strlen(str) - 2;

    for (i = 0; i <= len; ++i)
    {

        if (str[len - i] == 'a' || str[len - i] == 'A')
            base10 += 10 * mult;
        if (str[len - i] == 'b' || str[len - i] == 'B')
            base10 += 11 * mult;
        if (str[len - i] == 'c' || str[len - i] == 'C')
            base10 += 12 * mult;
        if (str[len - i] == 'd' || str[len - i] == 'D')
            base10 += 13 * mult;
        if (str[len - i] == 'e' || str[len - i] == 'E')
            base10 += 14 * mult;
        if (str[len - i] == 'f' || str[len - i] == 'F')
            base10 += 15 * mult;
        if (str[len - i] - '0' >= 0 && str[len - i] - '0' <= 9)
            base10 += (str[len - i] - '0') * mult;
        mult *= 16;
    }
    return base10;
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
