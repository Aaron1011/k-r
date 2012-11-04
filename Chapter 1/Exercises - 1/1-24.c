#include <stdio.h>
#define IN 0
#define OUT 1
#define QUOTE 2
#define PARAN 3
#define BRACKET 4
#define BRACE 5

main()
{
    int state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == '(')
            state = PARAN;
        else if (c == '[')
            state = BRACKET;
        else if (c == '{')
            state = BRACE;
        else if (state == PARAN && c == ')')
            state = OUT
        else if (state =;= BRACKET && c == ']')
            state = OUT;
        else if (state == BRACE && c == '}')
            state = OUT;

    }
    if (state != OUT)
        printf("Syntax Error: No closing %c found", c
