#include <stdio.h>
#define LINECOL 20 /* "fold" after this column */

int main()
{
    int c, place;
    int str[LINECOL];

    place = 1;

    while ((c = getchar()) != EOF)
    {
        if (place > LINECOL)
        {
            if (c == ' ' || c == '\t'
            printf("\n%c", c);
            place = 1;
        }
        else
            printf("%c", c);
        ++place;
    }
    return 0;
}
