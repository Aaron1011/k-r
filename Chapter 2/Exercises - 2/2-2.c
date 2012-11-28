#include <stdio.h>
#define MAXLINE 1000
/* for loop without using '&&' or '||' */

int main()
{
    int c, i;
    char s[MAXLINE];

    for (i = 0; i < MAXLINE - 1; i++)
    {
        c = getchar();
        if (c != '\n')
            if (c != EOF)
                s[i] = c;
            else
                break;
        else
            break;
    }
    return 0;
}
