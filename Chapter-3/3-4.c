#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAXLINE 1000


void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    int i;
    char s[MAXLINE];

    for (i = 0; i <= MAXLINE; i++)
        s[i] = 0;
    itoa(-123, s);
    printf("%s\n", s);
}

void itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
