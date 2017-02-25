#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "matrix.c"

int main() {

    struct matrix *d, *m, *x;
    d = new_matrix(4,4);
    m = new_matrix(4,7);
    x = new_matrix(4,4);

    //test

    printf("Identity Matrix: \n");
    ident(d);
    print_matrix(d);

    printf("\n");

    printf("Regular Matrix:\n");

    int i, j;
    int n = 0;

    //example matrix (just iterate by 5)
    for (i = 0; i < m->rows; i++){

        for (j = 0; j < m->cols; j++){
            m->m[i][j] = n;
            n += 5;
        }

    }
    print_matrix(m);

    printf("\n");

    printf("Example Matrix Pt. 2 (all the #s are 2)\n");
    for (i = 0; i < x->rows; i++){

        for (j = 0; j < x->cols; j++){
            x->m[i][j] = 2;
        }

    }
    print_matrix(x);


    printf("\n");

    printf("Scalar Multiplication: * 1/5\n");
    scalar_mult(.2,m);
    print_matrix(m);

    printf("\n");

    printf("Multiply by Identity Matrix\n");
    matrix_mult(d,m);
    print_matrix(m);

    printf("\n");

    printf("Multiply by 4x4 Non-Identity Matrix\n");
    matrix_mult(x,m);
    print_matrix(m);

}
