#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    printf("Setbits with x = 1101101, p = 5, n = 3, y = 1000\n");
    printf("%i\n", setbits(1101101, 5, 3, 1000));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned tempx;

    tempx = x >> (p+1-n);
	tempx |= ~(~0 << n);
    y &= ~(~0 << n);
    x = tempx << (p+1-n);
    return x & y;
}
