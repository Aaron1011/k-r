#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    printf("Calling invert with x = 1011010, p=5, n = 3\n");
    printf("%i\n", invert(0x5A, 5, 3));
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned tempx, mask;

    tempx = ~x;
    printf("%i\n", x);
    mask = ~(~0 << n) << p+1-n;
    tempx &= mask;
    x &= ~mask;
    printf("%i\n", x);
    return x | tempx;
}
