#include <stdio.h>
#include <string.h>
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

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /- 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j = 0;


