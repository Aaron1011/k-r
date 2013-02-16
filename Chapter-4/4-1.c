#include <stdio.h>
#include <string.h>


int strrindex(char s[], char t[]);

int main() {
    printf("%d\n", strrindex("back in the backwoods of back bay, wisconsin i hurt my back", "back"));
    return 0;
}


int strrindex(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) - 1; i != -1; i--) {
        for (j=i, k=strlen(t) - 1; k != -1 && s[j]==t[k]; j--, k--)
            ;
        if (k == -1)
            return j + 1;
    }
    return -1;
}
