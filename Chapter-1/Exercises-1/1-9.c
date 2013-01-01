#include <stdio.h>

main()
{
    double nc = 0;          /* keep track of number of newlines in a row */
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nc;
        else
        {
            if (nc != 0)
            {
                putchar('\n');
                putchar(c);
                nc = 0;
            }
            else
            {
                printf("%c", c);
            }   
        }
    }
}
