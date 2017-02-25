#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

    //declare
    int x,y,xmax,ymax,d;

    //init; takes care of left octants
    if (x1 >= x0){
        x = x0;
        y = y0;
        xmax = x1;
        ymax = y1;
    }
    else{
        x = x1;
        y = y1;
        xmax = x0;
        ymax = y0;
    }

    int a = ymax - y;
    //this will always be negative bc xmax > x
    int b = -1 *(xmax - x);

    //if q1 or q8; 0 < m < 1 u -1 > m > 0
    if (abs(a) <= -b){
        //if q1; bc a determines sign of slope
        if(a > 0){
            d = (2 * a) + b;

            while(x < xmax){
                //plot old point
                plot(s,c,x,y);

                //if mdpnt below line, use top pixel
                if (d > 0){
                    //switch to top pixel
                    y++;
                    //add to d
                    d+=2*b;
                }

                //always add to d
                d += 2*a;
                x++;
            }
        }
        //if q8
        else{
            d = (2 * a) - b;

            while(x < xmax){
                //plot old point
                plot(s,c,x,y);

                //if mdpnt above line, use bottom pixel
                if (d < 0){
                    //switch to ottom pixel
                    y--;
                    //add to d
                    d-=2*b;
                }

                //always add to d
                d += 2*a;
                x++;
            }
        }
    }

    //q2 or q7
    else{
        //q2
        if (a > 0){
            if(a > 0){
                d = a + 2*b;

                while(y < ymax){
                    //plot old point
                    plot(s,c,x,y);

                    //if mdpnt above of line, use bottom pixel
                    if (d < 0){
                        //switch to right pixel
                        x++;
                        //add to d
                        d+=2*a;
                    }

                    //always add to d
                    d += 2*b;
                    y++;
                }
            }
        }
        //q7
        else{
            int d = a - 2*b;
            printf("%d,%d to %d,%d\n",x0,y0,x1,y1);
            while(y > ymax){
                //plot old point
                plot(s,c,x,y);

                //if mdpnt left line, use right pixel
                if (d > 0){
                    //switch to right pixel
                    x++;
                    //add to d
                    d+=2*a;
                }

                //always add to d
                d -= 2*b;
                y--;
            }
        }
    }

    //plot final point
    plot(s,c,x,y);
}
