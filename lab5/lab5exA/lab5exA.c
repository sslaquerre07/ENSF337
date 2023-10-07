// File: lab5exA.c

#include "lab5_point.h"
#include <stdio.h>

const int SIZE = 2;

int main(void)
{
    struct point alpha = { 2.3, 4.5} ;
    struct point beta = { 25.9, 30.0 } ;
    struct point gamma [SIZE];
    struct point *stp = gamma;
    
    printf("Size of struct-point in our  lab is: %d bytes.\n",
           (int) sizeof(struct point));
    printf("Size of object alpha in 64-bit Cygwin is: %d bytes.\n",
           (int) sizeof(alpha));
    printf("Size of struct-point pointer in 64-bit Cygwin is: %d bytes.\n",
           (int) sizeof(stp));
    printf("Size of struct that stp points to is:  %d bytes.\n",
           (int) sizeof(*stp));
    printf("Size of array of structs, gamma  is:  %d bytes.\n\n",
           (int) sizeof(gamma));
 
    for(int i = 0; i < SIZE; i++) {
        (*stp).x = i + 200;
        (*stp).y = i + 300;
        stp++;
    }
    change_them(*gamma, &beta);

    printf("Program Terminted!\n");
    return 0;
}


void change_them (struct point point1, struct point point2 [2])
{
    printf("Size of point1 in function change_them is: %d bytes.\n",
           (int) sizeof(point1));
    printf("Size of point 2 in function change_them is: %d bytes.\n",
           (int) sizeof(point2));
    double* p1 = &point1.x;
    double* p2 = &(*point2).x;

    *p1 = 500;
    point1.y = 600;
 
    *p2 = 1000;
    (*point2). y = 2000;
    
    // point one
}



