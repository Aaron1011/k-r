#include <stdio.h>


int strrindex(char s[], char t[]);

int main() {
    printf("strrindex(\"test test\", \"te\") = %d\n", strrindex("test test", "te"));
    return 0;
}


int strrindex(char s[], char t[]) {
    int i, j, k, last_pos;
    last_pos = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            last_pos = i;
    }
    return last_pos;
}
