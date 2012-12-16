#include <stdio.h>
#define MAXLINE 1000
#define UPPERMIN 65
#define UPPERMAX 90
#define CASEDIFF 32

char lower(char str[]);
int aaronsgetline(char [], int lim);


int main()
{
	char line[MAXLINE];

    while (aaronsgetline(line, MAXLINE) > 0)
	{
		lower(line);
        printf("%s\n", line);
	}
    return 0;
}

char lower(char str[])
{
    int i;

    for (i = 0;  str[i] != '\0'; i++)
        str[i] = (str[i] >= UPPERMIN && str[i] <= UPPERMAX) ? (char) str[i] + CASEDIFF : str[i];
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
