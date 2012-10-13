#include <stdio.h>
#define IN 1    /* inside a word */
#define OUT 0   /* outside a world */

/* print a histogram of the lengths of words in input */

main()
{
    int c, i, l, word, not_empty;
    int lengths[45]; /* longest word in a major English dictionary is 45 letters */
    word = 0;

    for (i = 0; i < 45; ++i)
        lengths[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            ++lengths[word];
            word = 0;
        }
        else
         ++word;
    }
    printf("Word lengths:\n");
    
    for (i=1; i < 46; i++)
    {
        not_empty = (lengths[i] != 0);
        if (not_empty)
            printf("%i: ", i);
        for (l=0; l < lengths[i]; l++)
        {
            if (not_empty)
                printf("*");
        }
        if (not_empty)
            printf("\n");
        
    }
    return 0;
}
