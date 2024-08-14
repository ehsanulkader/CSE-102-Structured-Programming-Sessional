//
// Macro demo
// Author: Mohammad Saifur Rahman
//
#include <stdio.h>

//
// a macro written erronously. There is no compile error, however
// See what happens if you pass 3-40 (not -37, but the expression 3-40)
//
// #define abs(x) (x < 0 ? -x : x)

//
// Correct version of the macro. Notice the use of parentheses
// Can you tell why we did not use a semicolon at the end?
//
#define abs(x) ((x) < 0 ? -(x) : (x))

//
// Multi-line macro
// Swap variables a and b using a third variable t
//
#define swap(a, b) \
{\
    int t = a;\
    a = b;\
    b = t;\
}

//
// Notice function f(). Can you tell what will be the value
// printed by main() below?
//
int x = 5;

int f()
{
    x = x*x;
    return x;
}

int main()
{
    int x = -5;
    double y = -10;

    swap(x, y);
    printf("x = %d, y = %f\n", x, y);

    printf("%d\n", abs(f()));

    printf("Printing line %d of file %s.\nThe function name is %s\n", __LINE__, __FILE__, __FUNCTION__);

    return 0;
}
