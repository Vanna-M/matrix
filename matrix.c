#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m
Returns:

print the matrix
*/
void print_matrix(struct matrix *m) {
    //rows and cols
    int r = m->rows;
    int c = m->cols;

    int i, j;

    //for rows and cols
    for (i = 0; i < r; i++){
        for (j = 0; j < c; j++){

            double n = m->m[i][j];

            //print what's inside
            //exactly 2 digits; subject to change
            printf("%.2lf  ",n);
        }

        //next row
        printf("\n");

    }

}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns:

turns m in to an identity matrix
*/
void ident(struct matrix *m) {
    //keeps track of where to put 1
    int n = 0;

    int i, j;
    for (i = 0; i < m->cols; i++){
        for (j = 0; j < m->cols; j++){
            if (i == j){
                m->m[i][j] = 1;
            }
            else{
                m->m[i][j] = 0;
            }
        }
        ++n;
    }
}


/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m
Returns:

multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {
    int i, j;
    for (i = 0; i < m->rows; i++){
        for (j = 0; j < m->cols; j++){
            m->m[i][j] *= x;
        }
    }
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b
Returns:

a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
    //will always be 4 x 4 and 4 x n, so resulting 4 x n
    //therefore no need to resize matrix # 2

    //just in case checks
    if(a->cols != 4 || a->rows != 4 || b->rows != 4){
        printf("Error: Incompatible Matrices\n");
        return;
    }

    struct matrix *c;
    c = new_matrix(b->rows,b->cols);

    int i, j, k;
    for (i = 0; i < b->rows; i++){

        for (j = 0; j < b->cols; j++){

            int sum = 0;
            for (k = 0; k < a->rows; k++){
                sum += a->m[i][k] * b->m[k][j];
            }
            c->m[i][j] = sum;

        }
    }

    //copy
    copy_matrix(c,b);
    //clean up at end
    free_matrix(c);

}


/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols
Returns:

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)...
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m
Returns:

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols
Returns:

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {

  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b
Returns:

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++)
    for (c=0; c < a->cols; c++)
      b->m[r][c] = a->m[r][c];
}
