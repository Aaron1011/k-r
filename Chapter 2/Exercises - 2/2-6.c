#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned create_mask(int p, int n);

int main()
{
    printf("Setbits with x = 1101101, p = 5, n = 3, y = 001\n");
    printf("%i\n", setbits(0x6D, 5, 3, 1));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask, masked_x, masked_y;

    y <<= p+1-n;
    mask = create_mask(p, n);
    masked_x = x & ~mask;
    masked_y = y & mask;
    return masked_x | masked_y;
}

unsigned create_mask(int p, int n)
{
    return ~(~0  << n) << p+1-n;
}
