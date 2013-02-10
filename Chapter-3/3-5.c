#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000


void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
    char s[MAXCHAR];

    itob(255, s, 16);
    printf("%s\n", s);
    return 0;
}



void itob(int n, char s[], int b) {

    int cur_num, i;
    char CHARS[MAXCHAR] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    i = 0;

    while (n > 0) {
        cur_num = n % b;
        s[i++] = CHARS[cur_num];
        n /= b;
    }
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
