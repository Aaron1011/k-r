#include <stdio.h>
#define MAXCHAR 1000

#define MINCAP 65
#define MAXCAP 90
#define MINDIGIT 0
#define MAXDIGIT 9
#define MINLOWER 97
#define MAXLOWER 122

#define START 0
#define CHAR 1
#define DASH 2
#define LEAD_DASH 3
#define FINISH_STATE 4
#define EXIT_SHORTHAND 5

void expand(char s1[], char s2[]);
int isalphanum(char c);
int isalpha(char c);
int isnum(char c);
int writechars(char firstchar, char secondchar, char outputstring[], int outputindex);


int main() {
    int i;

    char s1[MAXCHAR];

    for(i = 0; i <= MAXCHAR; i++)
        s1[i] = 0;
    expand("a-z0-9 Hello world 1-2-3", s1);
    printf("%s\n", s1);
}

void expand(char s1[], char s2[]) {
    int i, state, s2index;
    char lastchar;

    state = START;
    s2index = 0;

    for (i = 0; s1[i] != '\0'; i++) {
        if (state == START) {
            if (s1[i] == '-')
                state = LEAD_DASH;
            else
                state = CHAR;
            s2[s2index++] = lastchar = s1[i];
        }
        else if (state == LEAD_DASH) {
            if (isalphanum(s1[i])) {
                state = CHAR;
                s2[s2index++] = lastchar = s1[i];
            }
            else {
                printf("\nError: Non-alphanumeric character following hyphen\n");
                return;
            }
        }
        else if (state == CHAR) {
            if (s1[i] == '-')
                state = DASH;
            else
                s2[s2index++] = lastchar = s1[i];

        }
        else if (state == DASH) {
            if ((isalpha(lastchar) && isalpha(s1[i])) || (isnum(lastchar) && isnum(s1[i]))) {
                s2index = writechars(lastchar+1, s1[i], s2, s2index);
                lastchar = s1[i];
                state = CHAR;
            }
            else {
                printf("\nError: Mismatched shorthand sequence\n");
                printf("Lastchar = %d, s1[i] = %d\n", lastchar-'0', s1[i]-'0');
                return;
            }
        }
    }
    s2[s2index+1] = '\0';
}


int isalpha(char c) {
   return (c-'0' <= MAXCAP && c-0 >= MINCAP) || (c-'0' <= MAXLOWER && c-'0' >= MINLOWER);
}

int isnum(char c) {
    return (c-'0' <= MAXDIGIT && c-'0' >= MINDIGIT);
}

int isalphanum(char c) {
    return isalpha(c) && isnum(c);
}

int writechars(char firstchar, char secondchar, char outputstring[], int outputindex) {
    char curchar = firstchar;

    for (; curchar-'0' <= secondchar-'0'; curchar++, outputindex++) {
        outputstring[outputindex] = curchar;
        printf("Curchar = %c\n", curchar);
    }
    return outputindex;
}
