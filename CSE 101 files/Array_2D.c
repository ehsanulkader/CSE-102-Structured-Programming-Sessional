//
// Author: Saifur Rahman
// Last Modified: 14 JUL 2019
//

#include <stdio.h>

//
// Read a matrix from console. Notice how the left
// subscript of the 2D array parameter is left blank.
//
void readMatrix(int mat[][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void readMatrix2(int mat[], int maxCol, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i * maxCol + j]);
        }
    }
}

void printMatrix(int mat[][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

//
// Sum the elements of an 1D array.
//
int sum(int x[], int n)
{
    int i, j, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += x[i];
    }

    return sum;
}


int main() {
    int mat[10][10], r, c, i, j;

    while (scanf("%d%d", &r, &c) == 2) {
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                printf("%2d ", mat[i][j]);
            }
            printf("\n");
        }

        //
        // Home work: instead of the code in lines 37-48
        // call the readMatrix and printMatrix functions.
        // Can you use readMatrix2 instead?
        //

        //
        // Calculate and print row sums of the matrix
        // Notice how mat[i] is treated as a 1D array
        //
        for (i = 0; i < r; i++) {
            printf("Row %d sum: %d\n", i, sum(mat[i], c));
        }
    }


    return 0;
}
