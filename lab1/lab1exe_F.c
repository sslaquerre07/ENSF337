/*
 *  lab1exe_F.c
 *  Created by Mahmood Moussavi
 *  Completed by: Samuel Laquerre
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

double degree_to_radian(double d){
    /*Converts from degrees to radians for sin() function
    *Returns the angle in radians
    */
    double radian = d*((2*PI)/360.0);
    return radian;
}

double Projectile_travel_time(double a, double v){
    /*Calculates projectile distance given the angle and a velocity with the formula given in the assignment
    *Returns said time
    */
    double time = 2*v*sin(degree_to_radian(a))/G;
    return time;
}

double Projectile_travel_distance(double a, double v){
    /*Calculates projectile distance given the angle and a velocity with the formula given in the assignment
    *Returns said distance
    */
    double distance = pow(v, 2)/G*sin(2*degree_to_radian(a));
    return distance;
}

void create_table(double v){
    /*Creates table based on velocity input*/
    printf("Angle\t           t\t          d\n");
    printf("(deg)\t         (sec)\t         (m)\n");
    for (double a=0;a<=90;a+=5){
        printf("%lf\t%lf\t%lf\n", a, Projectile_travel_time(a,v), Projectile_travel_distance(a,v));
    }
}

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}

/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */
