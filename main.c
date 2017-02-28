#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "matrix.c"

int main() {

    struct matrix *d, *m, *w;
    d = new_matrix(4,4);
    m = new_matrix(4,8);
    w = new_matrix(4,4);

    //print stuff; test matrix fxns

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
    for (i = 0; i < w->rows; i++){

        for (j = 0; j < w->cols; j++){
            w->m[i][j] = 2;
        }

    }
    print_matrix(w);


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
    matrix_mult(w,m);
    print_matrix(m);

    //patterns

    struct matrix *topRight;
    topRight = new_matrix(4,200);
    double **tr = topRight->m;

    //350, 400 to 450,250
    int x = 300;
    int y = 400;
    for (i = 0; i < topRight->cols; i+=2){
        tr[0][i] = x;
        tr[1][i] = y;
        tr[0][i + 1] = x + 200;
        tr[1][i + 1] = y + 300;
        y-=3;
        x+=2;
    }

    struct matrix *left;
    left = new_matrix(4,300);
    double **l = left->m;

    x = 200;
    y = 300;
    for (i = 0; i < left->cols; i+= 2){
        l[0][i] = x;
        l[1][i] = y;
        l[0][i+1] = x - 300;
        l[1][i+1] = y + 200;
        x-=3;
        y-=2;
    }

    struct matrix *top;
    top = new_matrix(4,400);
    double **t = top->m;

    x = 250;
    y = 200;
    for (i = 0; i < top->cols; i+=2){
        t[0][i] = x;
        t[1][i] = y;
        t[0][i+1] = x+300;
        t[1][i+1] = y+10;
        x -= 2;
        y += 3;
    }


    //populate new matrix w/useful points
    struct matrix *points;
    points = new_matrix(4,12);
    double **p = points->m;

    p[0][0] = 150;
    p[1][0] = 400;

    p[0][1] = 350;
    p[1][1] = 400;

    p[0][2] = 350;
    p[1][2] = 400;

    p[0][3] = 450;
    p[1][3] = 250;

    p[0][4] = 450;
    p[1][4] = 250;

    p[0][5] = 350;
    p[1][5] = 100;

    p[0][6] = 350;
    p[1][6] = 100;

    p[0][7] = 150;
    p[1][7] = 100;

    p[0][8] = 150;
    p[1][8] = 100;

    p[0][9] = 50;
    p[1][9] = 250;

    p[0][10] = 50;
    p[1][10] = 250;

    p[0][11] = 150;
    p[1][11] = 400;

    //currently irrelevant points
    for (i = 0; i < points->cols; i++){
        //z
        p[2][1] = 0;
        //1
        p[3][1] = 1;
    }

    for (i = 0; i < topRight->cols; i++){
        //z
        tr[2][i] = 0;
        //1
        tr[3][i] = 1;
    }

    for (i = 0; i < left->cols; i++){
        //z
        l[2][i] = 0;
        //1
        l[3][i] = 1;
    }

    for (i = 0; i < top->cols; i++){
        t[2][i] = 0;
        t[3][i] = 1;
    }

    //actually draw stuff
    screen s;
    color c;

    clear_screen(s);

    c.red = 255;
    c.green = 0;
    c.blue = 255;

    for (i = 0; i < topRight->cols; i+=2){
        draw_line(tr[0][i],tr[1][i],tr[0][i+1],tr[1][i+1],s,c);
    }

    c.red = 255;
    c.green = 128;
    c.blue = 0;

    for (i = 0; i < left->cols; i+=2){
        draw_line(l[0][i],l[1][i],l[0][i+1],l[1][i+1],s,c);
    }

    c.red = 0;
    c.green = 255;
    c.blue = 9;

    for (i = 0; i < top->cols; i+=2){
        draw_line(t[0][i],t[1][i],t[0][i+1],t[1][i+1],s,c);
    }

    c.red = 255;
    c.green = 255;
    c.blue = 0;

    for (i = 0; i < points->cols; i+=2){
        draw_line(p[0][i],p[1][i],p[0][i+1],p[1][i+1],s,c);
    }

    display(s);
    save_extension(s, "matrix.png");

}
