#include <stdio.h>
#define LINECOL 20 /* "fold" after this column */
void upto(char s[], int i);

int main()
{
    int c, i, j, lastchar;
    char str[LINECOL];
    for (i = 0; i <= LINECOL; i++)
        str[i] = 0;

    i = 0;
    lastchar = -1;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' && c != '\t' && c!= '\n')
            lastchar = i;
        if (i == LINECOL - 1)
        {
            str[i] = c;
            upto(str, lastchar);
                      
            i = 0;
            lastchar = -1;
        }
        else
        {
            str[i] = c;
            if (c == '\n')
                upto(str, lastchar);
            ++i;
        }
     
    }
    return 0;
}

void upto(char s[], int stop)
{
    int j;
    for (j = 0; j <= stop; j++)
        printf("%c", s[j]);

    if (stop >= 0)
        putchar('\n');
}
