#include <stdio.h>
#define MINCHAR 33
#define MAXCHAR 126

main()
{
    int c, i, l, not_empty;
    int characters[MAXCHAR - MINCHAR];
    
    for (i = 0; i < MAXCHAR - MINCHAR; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= MINCHAR && c <= MAXCHAR)
            characters[c - MINCHAR] += 1;
    }
    printf("Character lengths:\n");

    for (i = 0; i < MAXCHAR - MINCHAR; i++)
    {
        not_empty = (characters[i] != 0);
        if (not_empty)
        {
            printf("%c: ", (i + MINCHAR));
            for (l = 0; l < characters[i]; l++)
                printf("*");
            printf("\n"); 
        }
    }
}
         
