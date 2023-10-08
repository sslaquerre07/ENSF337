/* File: lab5exC.c
 * ENSF 337 - lab 5 - Exercise C
 */

#include "lab5exC.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    Point alpha = { "A1", 2.3, 4.5, 56.0} ;
    Point beta = { "B1", 25.9, 30.0, 97.0} ;
    printf ("Display the values in alpha, and beta: ");
    display_struct_point(alpha);
    display_struct_point(beta);
    
    Point *stp = &alpha;
    printf ("\n\nDisplay the values in *stp: ");
    display_struct_point(*stp);
    
    Point gamma = mid_point(stp, &beta, "M1");
    printf ("\n\nDisplay the values in gamma after calling mid_point function.");
    printf ("Expected result is: M1 <14.10, 17.25, 76.50>");
    
    printf("\n\nThe actual result of calling mid_point function is: ");
    display_struct_point(gamma);
    
    swap (stp, &beta);
    printf ("\n\nDisplay the values in *stp, and beta after calling swap function.");
    printf ("Expected to be:\nB1 <25.90, 30.00, 97.00>\nA1 <2.30, 4.50, 56.00>");
    
    
    printf("\n\nThe actual result of calling swap function is: ");
    display_struct_point(*stp);
    display_struct_point(beta);
    
    
    printf("\n\nThe distance between alpha and beta is: %.2f. ", distance(&alpha, &beta));
    printf ("(Expected to be: 53.74)");
    printf("\nThe distance between gamma and beta is: %.2f. ", distance(&gamma, &beta));
    printf ("(Expected to be: 26.87)");
    return 0;
}

void display_struct_point(const Point x)
{
    printf("\n%s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


// Complete, ask about the string though
Point mid_point(const Point* p1, const Point* p2, const char* label)
{
    double a = ((p1->x)+(p2->x))/2.0;
    double b = ((p1->y)+(p2->y))/2.0;
    double c = ((p1->z)+(p2->z))/2.0;
    
    Point middle = {"M1", a, b, c};
    
    return middle;
}

//Complete
void swap(Point* p1, Point *p2)
{
    Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

//Complete
double distance(const Point* p1, const Point* p2)
{
    double dist;
    double inside_root;
    inside_root = pow(((*p2).x - (*p1).x), 2.0) + pow(((*p2).y - (*p1).y), 2.0) + pow(((*p2).z - (*p1).z), 2.0);
    dist = pow(inside_root, 0.5);
    return dist;
}

