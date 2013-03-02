#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXOP   100
#define NUMBER  '0'
#define MAXVAL  100
#define BUFSIZE 100


int getop(char []);
void push(double);
double pop(void);
double nopopch(void);
void clearstack(void);
int getch(void);
void ungetch(int);


/* reverse Polish calculator */
main () {
    int type;
    double op1;
    double op2;
    char s[MAXOP];


    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Zero division error\n");
                break;
            case '%':
                op2 = pop();
                push((int) pop() % (int) op2);
                break;
            case 't':
                printf("\t%.8g\n", nopopch());
                break;
            case 'd':
                push(nopopch());
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'c':
                clearstack();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

int sp = 0;
double val[MAXVAL];


void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c, temp, place = 0;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '\n')
        return '\n';
    temp = getch();
    if (c == '-' && isdigit(temp)) {
        c = temp;
        s[1] = c;
        place = 1;
    }
    else
        ungetch(temp);

    if (!isdigit(c) && c != '.')
        return c;
    i = place;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

char buf[BUFSIZE];
int  bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

double nopopch(void) {
    return (sp > 0) ? val[sp-1] : 0;
}

void clearstack(void) {
    int i;

    for (i = 0; i < MAXVAL; i++)
        val[i] = 0;
    sp = 0;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("Ungetch: Too many characters\n");
    else
        buf[bufp++] = c;
}
