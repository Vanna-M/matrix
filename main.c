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

    printf("Add an Edge (34,50,123,45)\n");
    add_edge(m,34,50,123,45);
    print_matrix(m);

    printf("\n");

    //patterns

    struct matrix *topRight;
    topRight = new_matrix(4,200);

    //350, 400 to 450,250
    int x = 300;
    int y = 400;
    for (i = 0; i < topRight->cols; i+=2){
        add_edge(topRight,x,y,x+200,y+300);
        y-=3;
        x+=2;
    }

    struct matrix *left;
    left = new_matrix(4,300);

    x = 200;
    y = 300;
    for (i = 0; i < left->cols; i+= 2){
        add_edge(left,x,y,x-300,y+200);
        x-=3;
        y-=2;
    }

    struct matrix *top;
    top = new_matrix(4,400);

    x = 250;
    y = 200;
    for (i = 0; i < top->cols; i+=2){
        add_edge(top,x,y,x+300,y+10);
        x -= 2;
        y += 3;
    }


    //populate new matrix w/useful points
    struct matrix *hex;
    hex = new_matrix(4,10);

    add_edge(hex,150,400,350,400);
    add_edge(hex,350,400,450,250);
    add_edge(hex,450,250,350,100);
    add_edge(hex,350,100,150,100);
    add_edge(hex,150,100,50,250);
    add_edge(hex,50,250,150,400);

    //actually draw stuff
    screen s;
    color c;

    clear_screen(s);

    c.red = 255;
    c.green = 0;
    c.blue = 255;

    draw_matrix(topRight,s,c);

    c.red = 255;
    c.green = 128;
    c.blue = 0;

    draw_matrix(top,s,c);

    c.red = 0;
    c.green = 255;
    c.blue = 9;

    draw_matrix(left,s,c);

    c.red = 255;
    c.green = 255;
    c.blue = 0;

    draw_matrix(hex,s,c);

    display(s);
    save_extension(s, "matrix.png");

}
