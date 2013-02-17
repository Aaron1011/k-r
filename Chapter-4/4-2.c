#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAXLINE 100

int mygetline(char line[], int max);
double atof(char s[]);

int main() {
    double sum;
    char line[MAXLINE];
    int i;

    for (i=0; i <= MAXLINE; i++)
        line[i] = 0;

    sum = 0;
    while (mygetline(line, MAXLINE) > 0)
        printf("\t%g\n", atof(line));
    return 0;
}

int mygetline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

double atof(char s[]) {
    double val, power, exp, coefficient;
    int i, sign, expsign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        expsign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
    }

    coefficient = (sign * val / power);

    if (expsign == 1)
        return coefficient * pow(10, exp);
    else
        return coefficient / pow(10,exp);
}
