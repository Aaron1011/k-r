#include <stdio.h>
#define MINCHAR 33
#define MAXCHAR 126
#define NUMCHARS 94
main()
{
    int c, i, l, not_empty;
    int characters[NUMCHARS];
    
    for (i = 0; i < NUMCHARS; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c >= MINCHAR && c <= MAXCHAR)
            characters[c - MINCHAR] += 1;
    }
    printf("Character lengths:\n");

    for (i = 0; i < NUMCHARS; i++)
    {
        if (characters[i] != 0)
        {
            printf("%c: ", (i + MINCHAR));
            for (l = 0; l < characters[i]; l++)
                printf("*");
            printf("\n"); 
        }
    }
}
         
