#include <stdio.h>
#define MAXCHAR 1000

#define MINCAP 65
#define MAXCAP 90
#define MINDIGIT 48
#define MAXDIGIT 57
#define MINLOWER 97
#define MAXLOWER 122

#define DEFAULT 0
#define POS_SHORTHAND 1
#define IN_SHORTHAND 2


void expand(char s1[], char s2[]);

int main() {
    int i;

    char s1[MAXCHAR];

    for(i = 0; i <= MAXCHAR; i++)
        s1[i] = 0;
    expand(s1, "a-Z");
    printf("%s\n", s1);
}

void expand(char s1[], char s2[]) {
    int i, j, state;

    state = DEFAULT;

    for (i = j = 0; s2[j] != '\0'; i++, j++) {
        if (state == DEFAULT) {
            if (s2[j]-'0' <= MAXDIGIT && s2[j]-'0' >= MINDIGIT)
                state = POS_SHORTHAND;
            else if (s2[j] <= MAXCAP && s2[j] <= MAXLOWER && s2[j] >= MINCAP && s2[j] >= MINLOWER)
                state = POS_SHORTHAND;
            s1[i] = s2[j];
        }
        else if (state == POS_SHORTHAND) {
            if (s2[j] == '-')
                state = IN_SHORTHAND;
            else {
                state = DEFAULT;
                s1[i] = s2[j];
            }
        }
        else if (state == IN_SHORTHAND) {
            printf("In shorthand\n%c\n", s2[j]);
            if (s2[j] <= MAXCAP && s2[j] >= MINCAP) {
                for (i; s1[i] <= s2[j]; i++) {
                    printf("In for loop, i = %i, j = %i\n", i, j);
                    s1[i] = s2[j-2];
                    printf("s2[j-2] = %i", s2[j-2]);
                    s2[j-2] += 1;
                }
            }
        }
    }
}
