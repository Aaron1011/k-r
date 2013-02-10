#include <stdio.h>
#include <string.h>
#define MAXLINE 1000


void itoa(int n, char s[], int minwidth);
void reverse(char s[]);

int main() {
    int i;
    char s[MAXLINE];

    for (i = 0; i <= MAXLINE; i++)
        s[i] = 0;
    itoa(123, s, 5);
    printf("%s\n", s);
}

void itoa(int n, char s[], int minwidth) {
    int i, sign, original_length;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    if (strlen(s) < minwidth) {
        original_length = strlen(s);
        for (i = original_length-1; i >= 0; i--)
            s[i+(minwidth - original_length)] = s[i];
    }
    s[minwidth] = '\0';
    for (i = 0; i < minwidth - original_length; i++)
        s[i] = ' ';

}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
