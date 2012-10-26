#include <stdio.h>
#define IN 1    /* inside a word */
#define OUT 0   /* outside a world */
#define MAX_LENGTH 45 /* longest word in a major English dictionary is 45 letters */


/* print a histogram of the lengths of words in input */

main()
{
    int c, i, l, currentlength, not_empty;
    int lengths[MAX_LENGTH]; /* longest word in a major English dictionary is 45 letters */
    currentlength = 0;

    for (i = 0; i < MAX_LENGTH; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++lengths[currentlength];
            currentlength = 0;
        }
        else
         ++currentlength;
    }
    printf("Word lengths:\n");
    
    for (i=0; i < MAX_LENGTH; i++)
    {
        not_empty = (lengths[i] != 0);
        if (not_empty)
        {
            printf("%i: ", i);
            for (l=0; l < lengths[i]; l++)
                printf("*");
            printf("\n"); 
        }
    }
    return 0;
}
