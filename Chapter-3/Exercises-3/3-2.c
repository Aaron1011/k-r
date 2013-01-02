#include <stdio.h>
#define MAXCHAR 1000
#define DEFAULT 0
#define ESCAPE 1


void escape(char s[], char t[]);
void unescape(char s[], char t[]);


int main() {
    int i;

    char s[MAXCHAR];
    char s2[MAXCHAR];

    for (i = 0; i <= MAXCHAR; i++) {
        s[i] = 0;
        s2[i] = 0;
    }

    escape(s, "Hello\t\nworld");
    unescape(s2, "Hello\n\tworld");
    printf("%s\n%s\n", s, s2);
}

void escape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++, j++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }
    }
}

void unescape(char s[], char t[]) {
    int i, j, state;

    state = DEFAULT;

    for (i = j = 0; t[i] != 0; i++, j++) {
        switch (t[i]) {
            case '\\':
                if (state == DEFAULT) {
                    state = ESCAPE;
                    j--;
                }
                else if (state == ESCAPE)
                    s[j] = '\\';
                break;
            case 't':
                if (state == ESCAPE) {
                    s[j] = '\t';
                    state = DEFAULT;
                }
                else if (state == DEFAULT)
                    s[j] = 't';
                break;
            case 'n':
                if (state == ESCAPE) {
                    s[j] = '\n';
                    state = DEFAULT;
                }
                else if (state == DEFAULT)
                    s[j] = 'n';
                break;
            default:
                s[j] = t[i];
                break;

        }
    }
}





