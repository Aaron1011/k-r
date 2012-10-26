#include <stdio.h>
#define MINCHAR 33
#define MAXCHAR 126

main()
{
    int c, i, l, not_empty;
    int characters[MAXCHAR - 33];
    
    for (i = 0; i < MAXCHAR - 33; i++)
        characters[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c - '0' >= MINCHAR && c - '0' <= MAXCHAR)
           characters[c - 33] += 1;
    }
    printf("Character lengths:\n");

    for (i = 0; i < MAXCHAR - 33; i++)
    {
        not_empty = (characters[i] != 0);
        if (not_empty)
        {
            printf("%c: ", (i + 33));
            for (l = 0; l < characters[i]; l++)
                printf("*");
            printf("\n"); 
        }
    }
}
         
