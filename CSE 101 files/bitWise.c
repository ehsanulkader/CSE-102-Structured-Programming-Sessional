
#include <stdio.h>

void printBits(char *prefix, char x, char *suffix)
{
    int i;
    int nBits = sizeof(x)*8;
    char mask = ((char)1 << (nBits-1));
    printf("%s", prefix);
    for (i = 0; i < nBits; i++)
    {
        printf("%d", ((x & mask) ? 1 : 0));
        x <<= 1;
    }
    printf("%s", suffix);
}


int main()
{
    int x = 98, y = -82;

    printBits("x:     ", x, "\n");
    printBits("y:     ", y, "\n");
    printBits("(x&y): ", x&y, "\n");
    printBits("(x|y): ", x|y, "\n");
    printBits("(x^y): ", x^y, "\n");
    printf("~x: %d\n", ~x);
    printf("~y: %d\n", ~y);

    return 0;
}

