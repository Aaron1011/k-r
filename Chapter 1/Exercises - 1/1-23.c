#include <stdio.h>
#define IN 0
#define OUT 1
#define QUOTE 2
#define SLASH 3
main() /* Remove comments from input */
{
    int state = OUT;
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '"' || c == "'"[0])
        {
            if (state == QUOTE)
                state = OUT;
            else if (state == OUT)
                state = QUOTE;
            putchar(c);
        }
        else if (c == '/')
        {
			if (state == SLASH)
				state = IN;
            else if (state == IN)
                state = OUT;
            else if (state == QUOTE)
                putchar(c);
            else
			{
				putchar(c);
                state = SLASH;
			}
        }
        else if (state == OUT || state == QUOTE)
            putchar(c);
		else if (state == SLASH)
		{
			putchar(c);
			state = OUT;
		}
    }
    return 0;
}
